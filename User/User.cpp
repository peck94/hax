#include "User.h"
#include "../Config/Config.h"
#include <random>
using namespace std;

User::User() {
    vector<string> firstnames = Config::get().getFirstNames();
    vector<string> lastnames = Config::get().getLastNames();
    vector<string> usernames = Config::get().getUsernames();
    vector<string> passwords = Config::get().getPasswords();
    uniform_int_distribution<unsigned long> dist1(0, firstnames.size());
    uniform_int_distribution<unsigned long> dist2(0, lastnames.size());
    uniform_int_distribution<unsigned long> dist3(0, usernames.size());
    uniform_int_distribution<unsigned long> dist4(0, passwords.size());
    default_random_engine engine;

    firstname = firstnames[dist1(engine)];
    lastname = lastnames[dist2(engine)];
    username = usernames[dist3(engine)];
    password = passwords[dist4(engine)];
}

std::string User::getName() {
    return username;
}
