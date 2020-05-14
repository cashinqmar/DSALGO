#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
  while(t--){

        int baba;
        cin >> baba;
        vector<int> abra(baba + 1,0);
        vector<int> babra(baba + 1,0);
        vector<int> arrey(baba + 1,0);
        for (int i = 0; i <= baba; i++)
        {
            if(i==0)continue;

            abra[i] = 0;
            babra[i] = 0;
            arrey[i] = 0;
            cin >> arrey[i];
                arrey[i] = abs(arrey[i]);
        }
        for (int i = 0; i <= baba; i++)
        {
            if(i==0)continue;

            if (arrey[i] %2==1)
            {
                abra[i] = abra[i - 1] + 1;
            }
        }

        if (arrey[1] % 4 == 0)
            babra[1] = 1;

        for (int i = 2; i <= baba; i++)
        {
            if (arrey[i] % 4 == 0)
            {
                babra[i] = i;
                
            }

            else if (arrey[i] % 2 == 0)
            {
                if (arrey[i - 1] & 1)
                    babra[i] = i - abra[i - 1] - 1;
                else
                    babra[i] += i - 1;
                
            }

            else
            {
                babra[i] += babra[i - 1];
                continue;
            }
        }
        int ans = 0;
        for (int i = 0; i <= baba; i++)
        {
            ans = ans + abra[i];
        }
        for (int i = 0; i <= baba; i++)
        {
            ans = ans + babra[i];
        }
        cout << ans << endl;
    }
}