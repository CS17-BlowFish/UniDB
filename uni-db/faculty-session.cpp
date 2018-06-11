#include "faculty-session.h"


/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" Screen
**/
void TeacherSession::HomeScreen()
{
    std::cout << "1. Change password [p]            \n"
              << "2. View my courses [c]            \n"
              << "3. Search courses [scn]           \n"
              << "4. Open course [o] [a]            \n"
              << "5. Summarize Score [s] [sum]      \n"
              << "6. Revise Score [r]               \n"
              << "7. Logout [l]                     \n"
              << "8. Exit [q]                       \n"
              << "9. Help?? [h]                     \n" << std::endl;

    std::cout << "Your choice : ";
}


/**
 *  @method HomeHelper
 *  @return {void}
 *
 *  Show the faculty's home helper.
 *  Activities to choose:
 *  1. Open a course
 *  2. Summarize scores of a course
 *  3. Modify scores of a course
 *  4. Change password
**/
void FacultySession::HomeHelper()
{
    std::cout << "*Change\n\n"
              << "|___ Password             [p]    [passwd]\n\n"
              << "|___ Address              [ca]            \n\n"
              << "|___ Phone                [cp]            \n\n"
              << "*View all course          [c]             \n\n"
              << "|__View all student       [v]              \n"
              << "   in course                               \n"
              << "*Search course            [s]     [sc]      \n"
              << "|__Search course by name  [scn]           \n"
              << "|__Search course          [scn]            \n"
              << "   by falculty            [scf]   [sct]    \n\n"
              << "*Open course              [o]     [oc]      \n\n"
              << "*Summarize score          [s]     [sum]     \n\n"
              << "*Revise score             [r]     [revise]   \n\n";

    std::cout << "Press enter to continue ......";

    getchar();

}

/**
 *  @method OpenCourseActivity
 *  @return {void}
 *
 *  Run "Open a course" activity
**/
void FacultySession::OpenCourseActivity() {

}


/**
 *  @method SummarizeScoreActivity
 *  @return {void}
 *
 *  Run "Summarize scores of a course" activity
**/
void FacultySession::SummarizeScoreActivity() {

}


/**
 *  @method ModifyScoreActivity
 *  @return {void}
 *
 *  Run "Modify scores of a course" activity
**/
void FacultySession::ModifyScoreActivity() {

}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void FacultySession::ChangePasswordActivity() {

}


/* ==================== PUBLIC METHODS  ==================== */


FacultySession::FacultySession() {}


/**
 *  @method Session
 *  @return {void}
 *
 *  Run a faculty session
**/
void FacultySession::Session() {

}


FacultySession::~FacultySession() {}
