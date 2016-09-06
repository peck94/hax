#include "Computer.h"
using namespace sel;
using namespace std;

Computer::Computer(std::string name, std::string path) {
    this->name = name;
    this->path = path;
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

