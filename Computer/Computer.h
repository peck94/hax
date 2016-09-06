#ifndef HAX_COMPUTER_H
#define HAX_COMPUTER_H

#include <string>
#include "../Network/Network.h"
#include "../includes/selene.h"

class Network;

class Computer {
private:
    /*
     * Pretty name for the computer.
     * This name will be what the computer calls itself.
     */
    std::string name;

    /*
     * Path to the computer's script file.
     */
    std::string path;

    /*
     * Lua state for the computer's script.
     */
    sel::State state{true};

    /*
     * Network connection.
     */
    Network* network;

public:
    /**
     * Computer ctor.
     */
    Computer(std::string name, std::string path);

    /**
     * Standard getters.
     */
    std::string getName();
    std::string getPath();
    Network* getNetwork();

    /**
     * Standard setters.
     */
    void setNetwork(Network* network);

    /**
     * Initialize the computer.
     * This function will load the script associated with this computer and initialize storage.
     */
    void initialize();

    /**
     * Other functions, to be used by scripts.
     */
    bool ping(std::string name);
    bool connect(std::string name);
};


#endif //HAX_COMPUTER_H
