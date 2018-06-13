#include "admin-session.h"
#include "io.h"

#include <stdio.h>
#include <iostream>
#include <string>


/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  The home screen
**/
void AdminSession::HomeScreen() {
    IO io();

    do {
        std::string choice = io.NextToken();

        std::cout << "1.Add User\n";
        std::cout << "2.Delete User\n";
        std::cout << "3.Change password \n";
        std::cout << "4.Help??\n";

        if (choice == "1" || choice == "af" || choice == "at") {
            AddUserActivity();
        }
        else if (choice == "2" || choice == "df" || choice == "dt" || choice == "ds") {
            DeleteUserActivity();
        }
        else if (choice == "3" || choice == "p" || choice == "passwd") {
            ChangePasswordActivity();
        }
        else if (choice == "4") {
            HomeHelper();
        }
    } while(1);
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


void AdminSession::AddStudent() {
    // Get info of student
    std::cout << "Name: ";
    std::string student_name = io.ToUpperCase(io.ReadLine());

    std::cout << "Date of birth: ";
    std::string student_dateofbirth = io.NextToken();

    std::cout << "Place of birth: ";
    std::string student_placeofbirth = io.ReadLine();


    // Insert new user to "user" table
    std::string add_user_query = "";

    add_user_query += "IN user INSERT (user_id = ";
    add_user_query += NEXTSTUDENTID; // NEXTSTUDENTID will be added later
    add_user_query += ") AND (password = ";
    add_user_query += NEXTSTUDENTID; // NEXTSTUDENTID will be added later
    add_user_query += ") AND (user_type = student)";

    InsertQuery(add_user_query);

    // Insert new student to "student" table
    std::string add_student_query = "";

    add_student_query += "IN student INSERT (student_id = ";
    add_student_query += NEXTSTUDENTID; // NEXTSTUDENTID will be added later
    add_student_query += ") AND (student_name = ";
    add_student_query += student_name;
    add_student_query += ") AND (student_dateofbirth = ";
    add_student_query += student_dateofbirth;
    add_student_query += ") AND (student_placeofbirth = ";
    add_student_query += student_placeofbirth;

    InsertQuery(add_student_query);
}


void AdminSession::AddFaculty() {
    // Get info of Faculty
    std::cout << "Name: ";
    std::string faculty_name = io.ToUpperCase(io.ReadLine());

    std::cout << "Date of birth: ";
    std::string faculty_dateofbirth = io.NextToken();

    std::cout << "Phone number: ";
    std::string faculty_phonenumber = io.NextToken();

    std::cout << "Place of birth: ";
    std::string faculty_placeofbirth = io.ReadLine();


    // Insert new user to "user" table
    std::string add_user_query = "";

    add_user_query += "IN user INSERT (user_id = ";
    add_user_query += NEXTFACULTYID; // NEXTFACULTYID will be added later
    add_user_query += ") AND (password = ";
    add_user_query += NEXTFACULTYID; // NEXTFACULTYID will be added later
    add_user_query += ") AND (user_type = faculty)";

    InsertQuery(add_user_query);

    // Insert new faculty to "faculty" table
    std::string add_faculty_query = "";

    add_faculty_query += "IN faculty INSERT (faculty_id = ";
    add_faculty_query += NEXTFACULTYID; // NEXTFACULTYID will be added later
    add_faculty_query += ") AND (faculty_name = ";
    add_faculty_query += faculty_name;
    add_faculty_query += ") AND (faculty_dateofbirth = ";
    add_faculty_query += faculty_dateofbirth;
    add_faculty_query += ") AND (faculty_phonenumber = ";
    add_faculty_query += faculty_phonenumber;
    add_faculty_query += ") AND (faculty_placeofbirth = ";
    add_faculty_query += faculty_placeofbirth;

    InsertQuery(add_faculty_query);
}


/**
 *  @method AddUserActivity
 *  @return {void}
 *
 *  Run "Add user" activity
 *  Code of Trai (has been fixed 1 time)
**/
void AdminSession::AddUserActivity() {
    IO io();

    std::cout << "1.Student\n";
    std::cout << "2.Faculty\n";

    std::string choice = io.NextToken();

    if (choice == "1") {
        AddStudent();
    }
    else if (choice == "2") {
        AddFaculty();
    }
    else {
        std::cout << "Invalid choice. Press any key to continue...";
        getchar();
        return;
    }
}


/**
 *  @method DeleteUserActivity
 *  @return {void}
 *
 *  Run "Delete user" activity
 *  Code from Trai (has not been fixed)
**/
void AdminSession::DeleteUserActivity() {
    IO io();
    std::string id, keyword;// enter id  or keyword
    std::string user_type; //role student or falcuty
    std::string query;
    std::string choice;

    //choose user_type
    do {
        std::cout << "1.Student\n";
        std::cout << "2.Falcuty\n";

        choice = io.NextToken();

        if (choice == "1")
        {
            user_type = "student";
            break;
        }
        else if (choice == "2")
        {
            user_type = "faculty";
            break;
        }
        else
        {
            std::cout << "Try : ";
        }
    }
    while(1);

    //choose the way user id, by name, by phone number, by address
    do
    {
        std::cout << "\n1.Delete by User ID\n";
        std::cout << "2.Delete by Name\n";
        std::cout << "3.Delete by Phone number\n";
        std::cout << "4.Delete by Address\n";

        choice = io.NextToken();

        if (choice == "1")//Id
        {
            id = io.NextToken();
            if (user_type == "student")
            {
                query = "IN student SELECT*WHERE (user_id == id)";
            }
            else if (user_type == "teacher")
            {
                query = "IN faculty SELECT*WHERE (user_id == id)";
            }

            break;
        }
        else if (choice == "2")//name
        {
            keyword = io.NextToken();

            if (user_type == "student")
            {
                query = "IN student SELECT*WHERE (student_name CONTAINS keyword)";
            }
            else if (user_type == "faculty")
            {
                query = "IN faculty SELECT*WHERE (faculty_name CONTAINS keyword)";
            }

            break;
        }
        else if (choice == "3")//phone
        {
            keyword = io.NextToken();

            //student no phone
            /*if (user_type == "student")
            {
                query = "IN student SELECT*WHERE ( CONTAINS keyword)";
            }*/
            if (user_type == "faculty")
            {
                query = "IN faculty SELECT * WHERE (faculty_phonenumber CONTAINS keyword)";
            }

            break;
        }
        else if (choice == "4")//Address
        {
            keyword = io.NextToken();

            if (user_type == "student")
            {
                query = "IN student SELECT*WHERE (student_placeofbirth CONTAINS keyword)";
            }
            else if (user_type == "faculty")
            {
                query = "IN faculty SELECT*WHERE (faculty_placeofbirth CONTAINS keyword)";
            }
            break;
        }
        else
        {
            std::cout << "Try: ";
        }

    }
    while(1);

    std::vector< std::vector<std::string> > query_result = SelectQuery(query);

    //display , take id , remove in 2 query user and  falcuty or student
}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
 *  Code of Trai
**/
void AdminSession::ChangePasswordActivity() {
    IO io();

    // Let user enter new password
    std::cout << "New password: ";
    std::string new_password = io.NextToken();

    std::string query = "";
    query += "IN user SET (password = ";
    query += new_password;
    query += ") WHERE (user_id == ";
    query += admin_id;
    query += ")";
    SetQuery(query);

    std::cout << "Password changed.\n";
    std::cout << "Press any key to continue...";
    getchar();
    return;
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
