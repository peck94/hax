#ifndef HAX_COMPUTER_H
#define HAX_COMPUTER_H

#include <string>
#include "../Network/Network.h"
#include "../User/User.h"
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
     * Map of users that can login to this server.
     */
    std::map<std::string, User*> users;

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
    std::map<std::string, User*> getUsers();

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
     * Add a user to this computer.
     */
    void addUser(User* user);

    /**
     * Other functions, to be used by scripts.
     */
    bool ping(std::string name);
    bool connect(std::string name);
    bool rpc(std::string name, std::string command);
    void run(std::string command);

    /**
     * Computer dtor.
     * This deletes all users.
     */
    ~Computer();
};


#endif //HAX_COMPUTER_H
