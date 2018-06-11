#include "admin-session.h"
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