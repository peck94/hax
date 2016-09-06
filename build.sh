rm bin/hax
g++ -o bin/hax main.cpp Computer/Computer.cpp Computer/Computer.h Network/Network.cpp Network/Network.h Config/Config.cpp Config/Config.h -llua -fpermissive

