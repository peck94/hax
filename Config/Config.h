#ifndef HAX_CONFIG_H
#define HAX_CONFIG_H

#include <string>
#include <vector>
#include <random>
#include <map>

class Config {
private:
    Config() = default;

    /*
     * Store wordlists.
     * These wordlists are used for all kinds of purposes, such as generating computer names.
     */
    std::map<std::string, std::vector<std::string>> wordlists;

    /**
     * Lazily load a file.
     */
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
    int getMaxUsers();
    std::mt19937_64 getEngine();
    std::pair<std::string, std::string> getRandomFile();
};


#endif //HAX_CONFIG_H
