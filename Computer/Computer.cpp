#include "Computer.h"
#include <functional>
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
    state["GetName"] = [this]() { return this->getName(); };
    state["Ping"] = [this](string name) { return this->ping(name); };

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

