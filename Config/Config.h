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

public:
    Config(Config const&)               = delete;
    void operator=(Config const&)       = delete;

    static Config& get() {
        static Config config;

        return config;
    }

    std::vector<std::string> getWords();
};


#endif //HAX_CONFIG_H
