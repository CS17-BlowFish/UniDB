#include "io.h"
#include "student-session.h"

#include <iostream>

/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" activity
**/
void StudentSession::HomeScreen() {
    IO io;

    do {

        std::string choice = io.NextToken();

        std::cout << "1.Course Register\n";
        std::cout << "2.Course Deregister \n";
        std::cout << "3.Change Password\n";
        std::cout << "4.Help??\n";

        if (choice == "1" || choice == "af" || choice == "at") {
            CourseRegisterActivity();
        }
        else if (choice == "2" || choice == "df" || choice == "dt" || choice == "ds") {
            CourseDeregisterActivity();
        }
        else if (choice == "3" || choice == "p" || choice == "passwd") {
            ChangePasswordActivity();
        }
        else if (choice == "4") {
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
void StudentSession::HomeHelper() {
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
    std::string course_check = "IN score SELECT course_id WHERE (semester_id == <semester_id> AND (student_id == <student_id>";
    std::vector<std::vector<std::string> > check_result = SelectQuery(course_check);
    if (check_result[0][0] > 20){
        std::cout << "Unable to register more course for this semester " << std::endl;
    }
    std::string available_course = "IN course SELECT * WHERE (semester_id == <semester_id>)";
    std::vector<std::vector<std::string> > available_result = SelectQuery(available_course);

    std::cout << "Course available this semester " << std::endl;
    for (int i = 0; i < (int) available_result.size(); i++){
        for (int j = 0; j < (int) available_result[i].size(); j++){
            std::cout << std::setw(5) << available_result[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Please enter the course ID to choose the course ";
    IO io();
    std::string course_id = io.NextToken();

    std::string chosen_course = "IN score SELECT course_id WHERE (course_id == <course_id> AND student_id == <student_id>)";
    std::vector<std::vector<std::string> > chosen_result = SelectQuery(chosen_course);
    if (chosen_result[0][0] == course_id){
        std::cout << "You have already registered that course" << std::endl;
        std::cout << "Press any key to continue " << std::endl;
    }

    std::string new_course = "IN score INSERT (course_id == <course_id>) AND (student_id == <student_id>) AND (score = -1)";

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
