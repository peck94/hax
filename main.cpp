#include <iostream>
#include "Network/Network.h"
using namespace std;

int main() {
    // initialize network
    Network *network = new Network(5);

    // initialize localhost
    Computer* localhost = new Computer("localhost", "ssh");
    localhost->addUser(new User("Jonathan", "Peck", "jpeck", "phoenix"));
    network->addComputer(localhost);

    // connect to localhost
    localhost->initialize();

    // destroy network
    delete network;
}