#include "Network.h"
#include "../Config/Config.h"
#include <random>
using namespace std;

Network::Network(int size) {
    vector<string> words = Config::get().getWords();
    uniform_int_distribution<unsigned long> dist(0, words.size()-1);

    vector<string> scripts = Config::get().getScripts();
    uniform_int_distribution<unsigned long> dist2(0, scripts.size()-1);

    uniform_int_distribution<int> dist3(0, Config::get().getMaxUsers());

    mt19937_64 engine = Config::get().getEngine();
    string prev;
    for(int i = 0; i < size; i++) {
        string name;
        do {
            name = words[dist(engine)];
        }while(computers.find(name) != computers.end());

        string s = scripts[dist2(engine)];
        Computer *c = new Computer(name, s);
        for(int j = 0; j < dist3(engine); j++) {
            c->addUser(new User());
        }

        addComputer(c);
        if(prev.length() > 0) {
            c->addConnection(computers[prev]);
            computers[prev]->addConnection(c);
        }
        prev = name;
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

