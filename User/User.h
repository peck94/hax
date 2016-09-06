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
     * Initialize user with specified data.
     */
    User(std::string firstname, std::string lastname, std::string username, std::string password);

    /**
     * Standard getters.
     */
    std::string getUserName();
    std::string getFirstName();
    std::string getLastName();
    std::string getPassword();
};


#endif //HAX_USER_H
