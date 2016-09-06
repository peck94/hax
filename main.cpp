#include <iostream>
#include "Network/Network.h"
#include <random>
using namespace std;

int main() {
    // initialize network
    Network *network = new Network(5);

    // initialize localhost
    Computer* localhost = new Computer("localhost", "ssh");
    localhost->addUser(new User("Jonathan", "Peck", "jpeck", "phoenix"));

    default_random_engine engine;
    uniform_int_distribution<unsigned long> dist(0, network->getComputers().size());
    auto itr = network->getComputers().begin();
    std::advance(itr, dist(engine));
    localhost->addConnection(itr->second);
    network->addComputer(localhost);

    // connect to localhost
    localhost->initialize();

    // destroy network
    delete network;
}