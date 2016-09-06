//
// Created by pecky on 9/6/16.
//

#include "Config.h"
#include <fstream>
using namespace std;

std::vector<std::string> Config::getWords() {
    // load the wordlist if we haven't already
    if(words.empty()) {
        ifstream file("data/tech", ios::in);
        if(!file.is_open()) {
            throw runtime_error("Could not open wordlist");
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
