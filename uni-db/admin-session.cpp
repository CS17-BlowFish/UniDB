#include "admin-session.h"
#include <string>

/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  The home screen
**/
void AdminSession::HomeScreen()
{
    std::cout << "1. Show User              \n"
              << "2. Search User            \n"
              << "3. Add User               \n"
              << "4. Delete User [dt] [ds]  \n"
              << "5. Logout [l]             \n"
              << "6. Exit [q]               \n"
              << "7. Help?? [h]             \n" << std::endl;

    std::cout << "Your choice : ";
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
