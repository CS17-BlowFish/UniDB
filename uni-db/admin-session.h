#ifndef ADMIN_SESSION_H
#define ADMIN_SESSION_H

#include <string>
#include <iostream>
#include <stdio.h>


class AdminSession {
    private:
        std::string admin_id;

        void HomeScreen();
        void HomeHelper();

        void AddFaculty();
        void AddStudent();
        void AddUserActivity();

        void SearchFaculty();
        void SearchStudent();
        void SearchUser();

        void DeleteFaculty();
        void DeleteStudent();
        void DeleteUser();
        void DeleteUserActivity();

        void ChangePasswordActivity();

    public:
        bool is_logged_in = false;

        AdminSession(std::string _admin_id);
        void Run();
        ~AdminSession();
};


#endif // ADMIN_SESSION_H
