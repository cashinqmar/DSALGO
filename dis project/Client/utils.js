const { registeredServers } = require("./authClient");
const inquirer = require('inquirer');
const {setItem} = require('./fileStore');

const parseServerChoice = (server) => {
    const [ip, port] = server.split(":");
    return {ip, port};
}

const chooseFileServer = () => new Promise( async(res, rej) =>  {
    const servers = await registeredServers()
    questions = [{type: 'list', name: 'selectServer', message: "Choose server", choices: servers.map(s => s.ip+":"+s.port)}]
    inquirer.prompt(questions)
    .then(async (ans) => {
        await setItem('server', parseServerChoice(ans.selectServer));
        res();
    }).catch((e) => rej(e));
});

module.exports = {chooseFileServer};