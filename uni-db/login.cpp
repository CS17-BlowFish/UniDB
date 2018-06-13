#include "db.h"
#include "io.h"

#include <stdio.h>
#include <iostream>
#include <string>


bool LoginScreen(std::string &user_id, std::string &password, std::string &user_type) {
    IO io();

    std::cout << "UserID: ";
    user_id = io.NextToken();

    std::cout << "Password: ";
    password = io.NextToken();

    std::string query = "IN user SELECT user_id, password, user_type WHERE";
    query += "(user_id == ";
    query += user_id;
    query += ") AND (password == ";
    query += password;
    query += ")";

    std::vector<std::vector<std::string> > query_result = SelectQuery(query);
    // Each element of the outer vector is a vector with three elements:
    // user_id, password, user_type (this is defined after the "SELECT" keyword)

    if (query_result.size() == 0) {
        std::cout << "\n Login failed! Please try again...\n";
        std::cout << "Press any key to continue";
        getchar();
        return false; // login failed
    }

    user_type = query_result[0][2];

    std::cout << "\n Logged in succesfully!\n";
    std::cout << "Press any key to continue";
    getchar();

    return true;
}