//
// Created by pecky on 9/6/16.
//

#include "Config.h"
#include <fstream>
using namespace std;

std::vector<std::string> Config::getWords() {
    return loadFile("tech");
}

std::vector<std::string> Config::getFirstNames() {
    return loadFile("iraniannames.txt");
}

std::vector<std::string> Config::getLastNames() {
    return loadFile("arabicnames.txt");
}

std::vector<std::string> Config::getUsernames() {
    return loadFile("usernames.txt");
}

std::vector<std::string> Config::getPasswords() {
    return loadFile("passwords.txt");
}

std::vector<std::string> Config::loadFile(std::string name) {
    // load the wordlist if we haven't already
    if(words.empty()) {
        ifstream file("data/" + name, ios::in);
        if(!file.is_open()) {
            throw runtime_error("Could not open wordlist: " + name);
        }

        while(!file.eof()) {
            string line;
            getline(file, line);
            words.push_back(line);
        }

        file.close();
    }

    // wordlist is loaded, just return it
    return words;
}

std::vector<std::string> Config::getScripts() {
    return vector<string>{
            "shell", "ssh"
    };
}

int Config::getMaxUsers() {
    return 10;
}
