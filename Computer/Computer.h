#ifndef HAX_COMPUTER_H
#define HAX_COMPUTER_H

#include <string>

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
    lua_State* luaState;

public:
    /**
     * Standard getters.
     */
    std::string getName();
    std::string getPath();

    /**
     * Initialize the computer.
     * This function will load the script associated with this computer and initialize storage.
     */
    void initialize();
};


#endif //HAX_COMPUTER_H
