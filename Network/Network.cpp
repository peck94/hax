#include "Network.h"
#include "../Config/Config.h"
#include <vector>
#include <random>
using namespace std;

Network::Network(int size) {
    vector<string> words = Config::get().getWords();
    uniform_int_distribution<unsigned long> dist(0, words.size());
    default_random_engine engine;
    for(int i = 0; i < size; i++) {
        string name = words[dist(engine)];
        Computer *c = new Computer(name, "script");
        addComputer(c);
    }
}

Network::~Network() {
    // delete all computers
    for(auto p: computers) {
        delete(p.second);
    }
}

std::map<std::string, Computer*> Network::getComputers() {
    return computers;
}

void Network::addComputer(Computer *c) {
    computers[c->getName()] = c;
    c->setNetwork(this);
}

