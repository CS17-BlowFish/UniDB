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
 *
 *  Code of Trai
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
 *  Code of Tuan
**/
void StudentSession::CourseRegisterActivity() {
    std::string check_num_courses_query = "";
    check_num_courses_query += "IN score SELECT course_id ";
    check_num_courses_query += "WHERE (semester_id == ";
    check_num_courses_query += SEMESTER_ID;
    check_num_courses_query += "AND (student_id == ";
    check_num_courses_query += student_id;
    check_num_courses_query += ")";

    std::vector<std::vector<std::string> > check_num_courses_result = SelectQuery(check_num_courses_query);
    if (check_num_courses_result.size() > 20){
        std::cout << "Unable to register for more course this semester!\n";
        std::cout << "\n Press any key to continue...";
        getchar();
        return;
    }

    std::string check_available_courses_query = "";
    check_available_courses_query += "IN course SELECT * ";
    check_available_courses_query += "WHERE (semester_id == ";
    check_available_courses_query += SEMESTER_ID;
    std::vector<std::vector<std::string> > check_available_courses_result = SelectQuery(check_available_courses_query);

    std::cout << "Courses available this semester:\n";
    for (int i = 0; i < (int) check_available_courses_result.size(); i++){
        for (int j = 0; j < (int) check_available_courses_result[i].size(); j++){
            std::cout << std::setw(5) << check_available_courses_result[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Please enter the course ID to choose the course ";
    IO io();
    std::string course_id = io.NextToken();

    std::string check_course_query = "";
    check_course_query += "IN score SELECT course_id ";
    check_course_query += "WHERE (course_id == ";
    check_course_query += course_id;
    check_course_query += ") AND student_id == ";
    check_course_query += student_id;
    check_course_query += ")";

    std::vector<std::vector<std::string> > check_course_result = SelectQuery(check_course_query);
    if (check_course_result.size() > 0){
        std::cout << "You have already registered for that course" << std::endl;
        std::cout << "\nPress any key to continue" << std::endl;
        getline();
        return;
    }

    std::string register_query = "";
    register_query += "IN score INSERT (course_id = ";
    register_query += ") AND (student_id = ";
    register_query += student_id;
    register_query += ") AND (score = -1)";
    InsertQuery(register_query);
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
    IO io;

    std::cout << "New password: ";

    string  new_password = io.NextToken();//User enter new password

    std::string query = "IN user SET (password = new_password) WHERE (user_id == id)";

    SetQuery(query);
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
