#include "student-session.h"


/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" activity
**/
void StudentSession::HomeScreen()
{
     std::cout << "1. Change password [p]        \n"
               << "2. View my Coureses [c]       \n"
               << "3. Search Course [scn]        \n"
               << "4. Join Course [j]            \n"
               << "5. Logout [l]                 \n"
               << "6. Exit [q]                   \n"
               << "7. Help? [h]                  \n" << std::endl;

    std::cout << "Your choice : ";
}


/**
 *  @method HomeHelper
 *  @return {void}
 *
 *  Show the student's home helper.
 *  Activities to choose:
 *  1. Register for a course
 *  2. Deregister a course
 *  3. View profile
 *  4. Change password
**/
void StudentSession::HomeHelper()
{
    std::cout << "*Change Password            [p]    [passwd]  \n\n"
              << "*View all course            [c]             \n\n"
              << "|___View all student        [v]             \n"
              << "    in course                               \n\n"
              << "*Search course              [s]    [sc]      \n\n"
              << "|___Search course by name   [sfn]  [stn]     \n"
              << "|___Search course           [sct]           \n"
              << "    by faculty              [scf]  [sct]     \n\n"
              << "*Join course                [j]    [jc]      \n\n"
              << "*Summarize score            [s]    [sum]     \n\n";

    std::cout << "Press enter to continue ......";
    getchar();
}


/**
 *  @method CourseRegisterActivity
 *  @return {void}
 *
 *  Run "Register for a course" activity
**/
void StudentSession::CourseRegisterActivity() {

}


/**
 *  @method CourseDeregisterActivity
 *  @return {void}
 *
 *  Run "Deregister for a course" activity
**/
void StudentSession::CourseDeregisterActivity() {

}


/**
 *  @method ViewProfileActivity
 *  @return {void}
 *
 *  Run "View profile" activity
**/
void StudentSession::ViewProfileActivity() {

}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void StudentSession::ChangePasswordActivity() {

}


/* ==================== PUBLIC METHODS  ==================== */


StudentSession::StudentSession() {}


/**
 *  @method Run
 *  @return {void}
 *
 *  Run a student session
**/
void StudentSession::Run() {

}


StudentSession::~StudentSession() {}
