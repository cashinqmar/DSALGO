#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>
// #include <sys/socket.h>
#include <string.h>

int doElections(int server_id, int n_processes, int process_ids[], int PORT)
{
    int i = 0;
    char buffer[1024];
    strcpy(buffer, "ELECTION");
    printf("Sending ELECTION Message to processes with higher ids\n");
    int sentElection = 0;

    struct sockaddr_in receiver_address;

    receiver_address.sin_family = AF_INET;
    receiver_address.sin_addr.s_addr = INADDR_ANY;

    for(i = 0; i < n_processes; ++i)
    {
        // send Election message to higher process number
        if(process_ids[i] > PORT)
        {
            receiver_address.sin_port = htons(process_ids[i]);
            sendto(server_id, (char * )buffer, strlen(buffer),0, (
                    struct sockaddr * )&receiver_address, sizeof(receiver_address));
            sentElection = 1;

        }
    }


    // return 1 if no election message is sent. It means that this is the current coordinator
    return !sentElection;

}

int compareString(char buffer1[1024], char buffer2[1024])
{
    return !strcmp(buffer1, buffer2);
}

int main(int argc, char * argv[])
{
    // getting input variables for port
    int PORT = atoi(argv[1]);
    PORT += 8000;

    // whether the process is an election initiator or not
    int election_initiator = atoi(argv[2]);

    int n_processes = atoi(argv[3]);

    // inputting ids of other processes
    int * process_ids = (int *) malloc(sizeof(int) * n_processes);
    int i;
    for(i = 0; i < n_processes; ++i)
    {
        process_ids[i] = atoi(argv[4 + i]);
        process_ids[i] += 8000;
    }

    // buffer for sending messages
    char buffer[1024];

    // creating server. Initializing the server at PORT
    int server_id;
    struct sockaddr_in current_address;

    server_id = socket(PF_INET, SOCK_DGRAM, 0);

    if(server_id < 0)
    {
        printf("Server Connection failed\n");
        exit(1);
    }

    // binding the server id to a socket
    current_address.sin_family = AF_INET;
    current_address.sin_addr.s_addr = INADDR_ANY;
    current_address.sin_port = htons(PORT);


    if( bind(server_id, (struct sockaddr *) &current_address, sizeof(current_address) ) < 0 )
    {
        printf("Bind Failed\n");
        exit(1);
    }

    int election = 0;

    int Coordinator = 0;
    if(election_initiator == 1)
    {
        Coordinator = doElections(server_id, n_processes, process_ids, PORT);
        election = 1;
    }

    struct sockaddr_storage receiver_address;

    socklen_t address_len = sizeof(current_address
    ), from_temp_len = sizeof(receiver_address);

    while(1)
    {
        printf("Waiting for message\n");
        memset(buffer, 0, 1024);
        int size = recvfrom(server_id, (char * ) buffer, 1024, 0, (struct sock_addr *) &
                receiver_address, &from_temp_len);

        // print the received message

        printf("Received Message %s from %d \n", buffer,  ntohs(((struct
                sockaddr_in*)&receiver_address)->sin_port)-8000);

        // check for messages

        if(compareString(buffer, "ELECTION"))
        {
            // Send Ok message to the lower process


            strcpy(buffer, "OK");
            sendto(server_id, (char * )buffer, strlen(buffer),0, (
                    struct sockaddr * )&receiver_address, sizeof(receiver_address));

            if(election == 0)
            {
                // if elections have not been done till now, do the elections
                Coordinator = doElections(server_id, n_processes, process_ids, PORT);
                election = 1;
            }

        }
        else if(compareString(buffer, "COORDINATOR"))
        {
            printf("Setting %d as the new COORDINATOR\n", ntohs(((struct
                    sockaddr_in*)&receiver_address)->sin_port)-8000);
        }

        if(Coordinator == 1)
        {
            // send COORDINATOR messages to all processes
            memset(buffer, 0, 1024);
            strcpy(buffer, "COORDINATOR");
            printf("Choosen as new COORDINATOR\n");
            printf("Sending COORDINATOR messages to all processes\n");

            for(i = 0; i < n_processes; ++i)
            {
                // send Election message to higher process number
                if(process_ids[i] != PORT)
                {
                    struct sockaddr_in receiver_address;

                    receiver_address.sin_family = AF_INET;
                    receiver_address.sin_addr.s_addr = INADDR_ANY;

                    receiver_address.sin_port = htons(process_ids[i]);
                    sendto(server_id, (char * )buffer, strlen(buffer),0, (
                            struct sockaddr * )&receiver_address, sizeof(receiver_address));

                }
            }

	    Coordinator = 0;

        }

    }

    return 0;
}
