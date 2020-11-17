const { task } = require('folktale/concurrency/task');
const fs = require('fs');
const Shell = require('node-powershell');

const ps = new Shell({
    executionPolicy: 'Bypass',
    noProfile: true
});

const command = cm => task( resolver => {
    ps.addCommand(cm)
    ps.invoke()
    .then(resolver.resolve)
    .catch(resolver.reject)
});


module.exports = {command};