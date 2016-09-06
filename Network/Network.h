#ifndef HAX_NETWORK_H
#define HAX_NETWORK_H

#include <map>
#include "../Computer/Computer.h"

class Network {
private:
    /*
     * Dictionary of computers in this network.
     * The key is the name of the computer; the content is a pointer to the computer.
     */
    std::map<std::string, Computer*> computers;

public:
    /*
     * Network ctor.
     * This will randomly generate a network with the chosen parameters.
     */
    Network(int size);

    /**
     * Add a computer to the network.
     */
    void addComputer(Computer* c);

    /**
     * Get all computers in this network.
     */
    std::map<std::string, Computer*> getComputers();

    /*
     * Network dtor.
     * This will delete all computers in this network.
     */
    ~Network();
};


#endif //HAX_NETWORK_H
