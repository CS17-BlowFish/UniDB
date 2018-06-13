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


/**
 *  @method AddUserActivity
 *  @return {void}
 *
 *  Run "Add user" activity
**/
void AdminSession::AddUserActivity() {
    IO io();

    std::string type;
    std::string id;
    std::string query;

    std::string choice;
    do
    {
        std::cout << "1.Student\n";
        std::cout << "2.Faculty\n";

        choice = io.NextToken();

        if (choice == "1")
        {
            type = "student";
            break;
        }
        else if (choice == "2")
        {
            type = "faculty";
            break;
        }
        else
        {
            std::cout << "Try : ";
        }
    }
    while(1);

    std::cout << "Enter your ID: ";
    id = io.NextToken();

    //Check Exist Not Yet

    std::string name, phone, birth, address;
    if (type == "student")
    {
        //insert in user
        query = "IN user INSERT (user_id = id) AND (password = id) AND (user_type = type)";
        InsertQuery(query);

        //add info
        std::cout << "Name | Date of birth | Address: "  << '\n';
        name = io.ReadLine();
        birth = io.ReadLine();
        address = io.ReadLine();

        //insert in student
        query = "IN student INSERT (student_id = id) AND (student_name = name) AND (student_dateofbirth = birth) AND (student_placeofbirth = address)";
        InsertQuery(query);
    }
    else if (type == "faculty")
    {
        //insert in user
        query = "IN user INSERT (user_id = id) AND (password = id) AND (user_type = type)";
        InsertQuery(query);

        //add info
        std::cout << "Name | Date of birth | Phone | Address: "  << '\n';
        name = io.ReadLine();
        birth = io.ReadLine();
        phone = io.ReadLine()
        address = io.ReadLine();

        //insert in faculty
        query = "IN faculty INSERT (faculty_id = id) AND (faculty_name = name) AND (faculty_dateofbirth = birth) AND (teacher_placeofbirth = address)";
        InsertQuery(query);

    }
}


/**
 *  @method DeleteUserActivity
 *  @return {void}
 *
 *  Run "Delete user" activity
**/
void AdminSession::DeleteUserActivity() {
    IO io();
    std::string id, keyword;// enter id  or keyword
    std::string type; //role student or falcuty
    std::string query;
    std::string choice;

    //choose type
    do
    {
        std::cout << "1.Student\n";
        std::cout << "2.Falcuty\n";

        choice = io.NextToken();

        if (choice == "1")
        {
            type = "student";
            break;
        }
        else if (choice == "2")
        {
            type = "faculty";
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
            if (type == "student")
            {
                query = "IN student SELECT*WHERE (user_id == id)";
            }
            else if (type == "teacher")
            {
                query = "IN faculty SELECT*WHERE (user_id == id)";
            }

            break;
        }
        else if (choice == "2")//name
        {
            keyword = io.NextToken();

            if (type == "student")
            {
                query = "IN student SELECT*WHERE (student_name CONTAINS keyword)";
            }
            else if (type == "faculty")
            {
                query = "IN faculty SELECT*WHERE (faculty_name CONTAINS keyword)";
            }

            break;
        }
        else if (choice == "3")//phone
        {
            keyword = io.NextToken();

            //student no phone
            /*if (type == "student")
            {
                query = "IN student SELECT*WHERE ( CONTAINS keyword)";
            }*/
            if (type == "faculty")
            {
                query = "IN faculty SELECT*WHERE (faculty_phonenumber CONTAINS keyword)";
            }

            break;
        }
        else if (choice == "4")//Address
        {
            keyword = io.NextToken();

            if (type == "student")
            {
                query = "IN student SELECT*WHERE (student_placeofbirth CONTAINS keyword)";
            }
            else if (type == "faculty")
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
**/
void AdminSession::ChangePasswordActivity() {
    IO io();

    std::cout << "New password: ";

    std::string new_password = io.NextToken();//User enter new password

    std::string query = "IN user SET (password = new_password) WHERE (user_id == admin_id)";
    query += "In User SET (password = ";
    query += new_password;
    query += ") WHERE (user_id == ";
    query += admin_id;
    query += ")";
    SetQuery(query);

    std::cout << "Password changed.\n";
    std::cout << "Press any key to continue...";
    getchar();
    //return; chac chan return nen khoi
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
