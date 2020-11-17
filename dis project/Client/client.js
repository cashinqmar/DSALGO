const grpc = require("grpc");
const protoLoader = require("@grpc/proto-loader");
const { task } = require('folktale/concurrency/task');
const { resolve } = require("path");

const packageDef = protoLoader.loadSync("../file.proto", {});

const grpcObject = grpc.loadPackageDefinition(packageDef);
const filePackage = grpcObject.filePackage;

const ip = 'localhost';
const port = '4000';

const getClient = server => new filePackage.File(server.ip+":"+server.port, grpc.credentials.createInsecure());

const concatWithNewLine = xs => xs.reduce((res, x) => res != "" ? res+"\n"+x : x, "")

const command = async (cmd) => {
    const server = {ip, port}
    return new Promise((resolve, reject) => {
        getClient(server).command({cmd}, (err, res) => {
            if (err) {
                reject(err);
            } else {
                resolve(res.data)
            }
        })
    })
}

module.exports = {command}