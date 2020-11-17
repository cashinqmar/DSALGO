const { Command } = require("commander");
const inquirer = require("inquirer");
const client = require("./client");
const readline = require('readline');
const { async } = require("rxjs");

const program = new Command();
program.version("0.0.1");

program
    .command("pwd")
    .description("Current directory on remote")
    .action(async () => {
        const res = await client.command("pwd")
        console.log(res);
    });

program
    .command('rm <path>')
    .description("Remove file from remote.")
    .action(async (path) => {
         const res = await client.command("rm " + path);
         console.log(res);
    });

program
    .command('ls [path]')
    .description("list files and folder from remote.")
    .action(async (path) => {
        path = !path ? './' : path;
        const res = await client.command("ls "+path)
        console.log(res);
    });

program
    .command('cat [filename]')
    .description('read the content of a file')
    .action(async (file) => {
        if (!file) {
            console.log("File name required.")
            return;
        }
        const res = await client.command('cat '+file);
        console.log(res);
    });    

program
    .command('cp [source] [destination]')
    .description('copy file from source to destination.')
    .action( async (source, destination) => {
        if (!source || !destination) {
            console.log("Source or destination is missing");
            return;
        } else {
            const res = await client.command('cp ' + source + " " + destination);
            console.log(res);
        }
    })

program
    .command('mkdir [dirName]')
    .description('create a folder')
    .action(async (dirName) => {
        if (dirName) {
            const res = await client.command('mkdir ' + dirName);
            console.log(res);
        } else {
            console.log("Please specify the folder name.")
        }
    });  

program.parse(process.argv);




