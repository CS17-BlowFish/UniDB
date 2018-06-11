#include "admin-session.h"
#include "io.h"

/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  The home screen
**/
void AdminSession::HomeScreen()
{
    IO io;

    do
    {

        std::string choice = io.NextToken();

        std::cout << "1.Add User\n";
        std::cout << "2.Delete User\n";
        std::cout << "3.Change password \n";
        std::cout << "4.Help??\n";

        if (choice == "1" || choice == "af" || choice == "at")
        {
            AddUserActivity();
        }
        else if (choice == "2" || choice == "df" || choice == "dt" || choice == "ds")
        {
            DeleteUserActivity();
        }
        else if (choice == "3" || choice == "p" || choice == "passwd")
        {
            ChangePasswordActivity();
        }
        else if (choice == "4")
        {
            HomeHelper();
        }
    }
    while(1);
}


/**
 *  @method HomeHelper
 *  @return {void}
 *
 *  Show the administrator's .
 *  Activities to choose:
 *  1. Add user
 *  2. Delete user
 *  3. Change password
**/
void AdminSession::HomeHelper()
{
    std::cout << "*Change Password            [p]   [passwd]\n"
              << "\n*Show User\n"
              << "|___Show faculty            [f]   [t]     [1 1]  \n"
              << "|___Show Student            [s]           [1 1]  \n"
              << "\n*Search User by name\n"
              << "|___Search Faculty by name  [sfn] [stn]   [2 1]  \n"
              << "|___Search Student by name  [ssn]         [2 2]   \n"
              << "\n*Add User\n"
              << "|___Add Faculty             [af]  [at]    [3 1]    \n"
              << "|___Add Studdent            [as]          [2 2]    \n"
              << "\n*Delete User\n"
              << "|___Delete Falculty         [df]  [dt]    [4 1]     \n"
             << "|___Delete Student          [ds]          [4 2]      \n";

    std::cout << "Press enter to continue ......";
    getchar();
}

/**
 *  @method AddUserActivity
 *  @return {void}
 *
 *  Run "Add user" activity
**/
void AdminSession::AddUserActivity() {

}


/**
 *  @method DeleteUserActivity
 *  @return {void}
 *
 *  Run "Delete user" activity
**/
void AdminSession::DeleteUserActivity() {

}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void AdminSession::ChangePasswordActivity() {

}


/* ==================== PUBLIC METHODS  ==================== */


AdminSession::AdminSession(std::string _admin_id) {
    admin_id = _admin_id;
}


/**
 *  @method Run
 *  @return {void}
 *
 *  Run an administrator session
**/
void AdminSession::Run() {

}


AdminSession::~AdminSession() {}
