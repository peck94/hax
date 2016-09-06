#ifndef HAX_USER_H
#define HAX_USER_H

#include <string>

class User {
private:
    /*
     * Personal information of this user.
     */
    std::string firstname;
    std::string lastname;
    std::string username;
    std::string password;

public:
    /**
     * Initialize user with random data.
     */
    User();

    /**
     * Standard getters.
     */
    std::string getName();
};


#endif //HAX_USER_H
