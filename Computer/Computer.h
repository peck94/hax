#ifndef HAX_COMPUTER_H
#define HAX_COMPUTER_H

#include <string>
#include "../Network/Network.h"
#include "../User/User.h"
#include "../FileSystem/FileSystem.h"
#include "../includes/selene.h"

class Network;
class FileSystem;

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

    /*
     * Local file system.
     */
    FileSystem* fs;

    /**
     * Initialize the computer.
     * This function will load the script associated with this computer and initialize storage.
     */
    void initialize();

public:
    /**
     * Computer ctors.
     */
    Computer(std::string name, std::string path);
    Computer(std::string name, std::string path, int numUsers);

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
     * Add a user to this computer.
     */
    void addUser(User* user);

    /**
     * Add a network connection.
     */
    void addConnection(Computer* computer);

    /**
     * Other functions, to be used by scripts.
     */
    bool ping(std::string name);
    bool connect(std::string name);
    bool rpc(std::string name, std::string command);
    void run(std::string command);

    /**
     * Run the main function of this computer.
     */
    void main();

    /**
     * Computer dtor.
     * This deletes all users.
     */
    ~Computer();
};


#endif //HAX_COMPUTER_H
