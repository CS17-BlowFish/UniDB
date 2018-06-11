#include "io.h"
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
    IO io;

    do
    {

        std::string choice = io.NextToken();

        std::cout << "1.Course Register\n";
        std::cout << "2.Course Deregister \n";
        std::cout << "3.Change Password\n";
        std::cout << "4.Help??\n";

        if (choice == "1" || choice == "af" || choice == "at")
        {
            CourseRegisterActivity();
        }
        else if (choice == "2" || choice == "df" || choice == "dt" || choice == "ds")
        {
            CourseDeregisterActivity();
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
	std::string password;
	std::cout << "New password: ";
	std::cin >> password;
	Task _task;
	_task.replace_data(0, id, 1, password);
}


/* ==================== PUBLIC METHODS  ==================== */


StudentSession::StudentSession() {}


/**
 *  @method Run
 *  @return {void}
 *
 *  Run a student session
**/
//void StudentSession::Run() {

//}


StudentSession::~StudentSession() {}
