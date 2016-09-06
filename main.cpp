#include <iostream>
#include "Network/Network.h"
using namespace std;

int main() {
    // initialize network
    Network *network = new Network(500);

    // destroy network
    delete network;
}