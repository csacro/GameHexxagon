/**
 * @author Carolin Schindler
 */

#ifndef GAMEHEXXAGON_USER_H
#define GAMEHEXXAGON_USER_H


#include <string>

/**
 * struct for User data
 */
struct User {
    std::string userId; //id of User
    std::string userName; //name of User
    bool isConnected = false; //true if connected to server, else false
};

//TODO

#endif //GAMEHEXXAGON_USER_H
