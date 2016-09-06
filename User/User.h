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
};


#endif //HAX_USER_H
