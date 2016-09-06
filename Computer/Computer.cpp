#include <fstream>
#include "Computer.h"
using namespace sel;
using namespace std;

Computer::Computer(std::string name, std::string path) {
    this->name = name;
    this->path = path;
    this->fs = new FileSystem();
}

Computer::Computer(std::string name, std::string path, int numUsers) {
    this->name = name;
    this->path = path;
    this->fs = new FileSystem();
    for(int i = 0; i < numUsers; i++) {
        addUser(new User());
    }
}

string Computer::getName() {
    return name;
}

string Computer::getPath() {
    return path;
}

void Computer::initialize() {
    // construct path of script file
    string path = "scripts/computers/" + getPath() + ".lua";

    // load script
    state.Load(path);

    // register functions
    state["GetName"] = [this]() { return getName(); };
    state["Ping"] = [this](string name) { return ping(name); };
    state["Connect"] = [this](string name) { return connect(name); };
    state["RPC"] = [this](string name, string command) { return rpc(name, command); };
    state["GetUser"] = [this](string name) {
        if(users.find(name) != users.end()) {
            state["User"].SetObj(*users[name],
                                 "getUserName", &User::getUserName,
                                 "getFirstName", &User::getFirstName,
                                 "getLastName", &User::getLastName,
                                 "getPassword", &User::getPassword
            );
            return true;
        }else{
            return false;
        }
    };
    state["Run"] = [this](string name) {
        string path = "scripts/tools/" + name + ".lua";
        ifstream file(path);
        if(!file.is_open()) {
            return false;
        }

        string contents;
        while(!file.eof()) {
            string line;
            getline(file, line);
            contents += line;
        }
        file.close();

        state(contents.c_str());
        return true;
    };

    // register variables
    state["FileSystem"].SetObj(*fs,
                               "cd", &FileSystem::cd,
                               "ls", &FileSystem::ls,
                               "pwd", &FileSystem::pwd,
                               "cat", &FileSystem::cat
    );

    // execute script
    state["main"]();
}

void Computer::setNetwork(Network *network) {
    this->network = network;
}

Network *Computer::getNetwork() {
    return network;
}

bool Computer::ping(std::string name) {
    return network->getComputers().find(name) != network->getComputers().end();
}

bool Computer::connect(std::string name) {
    if(ping(name)) {
        network->getComputers()[name]->initialize();
        return true;
    }else{
        return false;
    }
}

bool Computer::rpc(std::string name, std::string command) {
    if(ping(name)) {
        network->getComputers()[name]->run(command);
        return true;
    }else{
        return false;
    }
}

void Computer::run(std::string command) {
    state(command.c_str());
}

Computer::~Computer() {
    delete fs;
    for(auto p: users) {
        delete p.second;
    }
}

void Computer::addUser(User *user) {
    users[user->getUserName()] = user;
    fs->getRoot()->getDirs()["/home"]->addDirectory(new Directory(user->getUserName()));
}

std::map<std::string, User*> Computer::getUsers() {
    return users;
}

