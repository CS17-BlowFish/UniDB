#include "admin-session.h"
#include "task.h"
#include <string>


/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  The home screen
**/
void AdminSession::HomeScreen() {
    
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
void AdminSession::HomeHelper() {

}


/**
 *  @method AddUserActivity
 *  @return {void}
 *
 *  Run "Add user" activity
**/
void AdminSession::AddUserActivity() {
	Task _task;
	_task.add_user();
}


/**
 *  @method DeleteUserActivity
 *  @return {void}
 *
 *  Run "Delete user" activity
**/
void AdminSession::DeleteUserActivity() {
	Task _task;
	_task.remove_user();
}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void AdminSession::ChangePasswordActivity() {
	std::string password;
	std::cout << "New password: ";
	std::cin >> password;
	Task _task;
	_task.replace_data(0, admin_id, 1, password);
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