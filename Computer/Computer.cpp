#include "Computer.h"
#include "../includes/LuaBridge/LuaBridge.h"
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace luabridge;
using namespace std;

string Computer::getName() {
    return name;
}

string Computer::getPath() {
    return path;
}

void Computer::initialize() {
    // construct path of script file
    string path = "scripts/computers/" + getPath() + ".lua";

    // load the script
    luaState = luaL_newstate();
    luaL_dofile(luaState, path.c_str());
    luaL_openlibs(luaState);

    // set namespace variables
    getGlobalNamespace(luaState)
            .beginNamespace("main")
            // read-only access to computer name
            .addVariable("name", getName().c_str(), false)
    .endNamespace();
}
