#ifndef HAX_CONFIG_H
#define HAX_CONFIG_H

#include <string>
#include <vector>

class Config {
private:
    Config() = default;

    /*
     * Store wordlist.
     * This wordlist is used for all kinds of purposes, such as generating computer names.
     */
    std::vector<std::string> words;

    std::vector<std::string> loadFile(std::string name);

public:
    Config(Config const&)               = delete;
    void operator=(Config const&)       = delete;

    static Config& get() {
        static Config config;

        return config;
    }

    std::vector<std::string> getWords();
    std::vector<std::string> getFirstNames();
    std::vector<std::string> getLastNames();
    std::vector<std::string> getUsernames();
    std::vector<std::string> getPasswords();
    std::vector<std::string> getScripts();
};


#endif //HAX_CONFIG_H
