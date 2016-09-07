//
// Created by pecky on 9/6/16.
//

#include "Config.h"
#include <fstream>
#include <random>
using namespace std;

std::vector<std::string> Config::getWords() {
    return loadFile("words");
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
    if(wordlists.find(name) == wordlists.end()) {
        ifstream file("data/" + name, ios::in);
        if(!file.is_open()) {
            throw runtime_error("Could not open wordlist: " + name);
        }

        wordlists[name] = vector<string>{};
        while(!file.eof()) {
            string line;
            getline(file, line);
            wordlists[name].push_back(line);
        }

        file.close();
    }

    // wordlist is loaded, just return it
    return wordlists[name];
}

std::vector<std::string> Config::getScripts() {
    return vector<string>{
            "ssh"
    };
}

int Config::getMaxUsers() {
    return 10;
}

mt19937_64 Config::getEngine() {
    random_device r;
    return mt19937_64(r());
}

pair<string, string> Config::getRandomFile() {
    vector<string> categories{
            "business", "entertainment", "politics", "sport", "tech"
    };
    vector<unsigned long> counts{
            510, 386, 417, 511, 401
    };

    uniform_int_distribution<unsigned long> dist1(0, categories.size() - 1);
    mt19937_64 engine = getEngine();
    unsigned long category = dist1(engine);

    uniform_int_distribution<unsigned long> dist2(1, counts[category]);
    unsigned long number = dist2(engine);

    string num = to_string(number);
    if(number < 100) {
        num = "0" + num;
    }
    if(number < 10) {
        num = "0" + num;
    }

    vector<string> lines = loadFile(categories[category] + "/" + num + ".txt");
    string contents;
    for(string line: lines) {
        contents += line + "\n";
    }

    vector<string> words = getWords();
    uniform_int_distribution<unsigned long> dist3(0, words.size() - 1);
    string word = words[dist3(engine)];
    return pair<string, string>(word, contents);
}
