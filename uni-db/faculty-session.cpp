#include "faculty-session.h"
#include "io.h"

/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" Screen
**/
void FacultySession::HomeScreen()
{
    IO c;
    std::string choice = c.NextToken();

    std::cout << "1.Open Course \n";
    std::cout << "2.Summarize Score\n";
    std::cout << "3.Modify Score \n";
    std::cout << "4.Change Password\n";
    std::cout << "5.Help??\n";

    do
    {
        if (choice == "1" || choice == "o" || choice == "oc")
        {
            OpenCourseActivity();
            break;
        }
        else if (choice == "2" || choice == "s" || choice == "sum")
        {
            SummarizeScoreActivity();
            break;
        }
        else if (choice == "3" || choice == "r" || choice == "revise")
        {
            ModifyScoreActivity();
            break;
        }
        else if (choice == "4" || choice == "p" || choice == "passwd")
        {
            ChangePasswordActivity();
            break;
        }
        else if (choice == "5")
        {
            HomeHelper();
            break;
        }
    }
    while(1);
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

FacultySession::~FacultySession() {}
