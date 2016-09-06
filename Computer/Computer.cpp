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

    // initialize state
    state = new State(true);

    // load script
    state->Load(path);
}

