#include "admin-session.h"
#include "db.h"
#include "io.h"
#include "screen.h"

#include <stdio.h>
#include <iostream>
#include <string>


/* ==================== PRIVATE METHODS ==================== */


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
    screen::PrintLine("Choose an activity: please input a number");
    screen::PrintLine("1. Add User");
    screen::PrintLine("2. Delete User");
    screen::PrintLine("3. Change Password");
    // screen::PrintLine("4. Help");
    screen::PrintLine("4. Log Out");
    screen::PrintLine("5. Exit");
}


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  The home screen
**/
void AdminSession::HomeScreen() {

    while (true) {
        HomeHelper();
        screen::PadCommand();
        std::cout << "Next activity: ";

        std::string cmd = io::NextToken();
        if (cmd == "1") {
            AddUserActivity();
            break;
        }
        else if (cmd == "2") {
            DeleteUserActivity();
            break;
        }
        else if (cmd == "3") {
            ChangePasswordActivity();
            break;
        }
        else if (cmd == "4") {
            is_logged_in = false;
            return;
        }
        else if (cmd == "5") {
            exit(0);
        }
        else {
            screen::Pad();
            screen::ErrorMessage("Invalid choice.");
            screen::Pend();
            screen::Clear();
        }
    }
}


void AdminSession::AddFaculty() {
    // Get info of Faculty
    screen::Print("Name: ");
    std::string faculty_name = io::ToUpperCase(io::ReadLine());

    screen::Print("Date of birth: ");
    std::string faculty_dateofbirth = io::NextToken();

    screen::Print("Phone number: ");
    std::string faculty_phonenumber = io::NextToken();

    screen::Print("Place of birth: ");
    std::string faculty_placeofbirth = io::ReadLine();

    // Generate faculty_id
    std::string faculty_id = db::AutoIncrementFacultyID();

    // Insert new user to "user" table
    std::string add_user_query = "";

    add_user_query += "IN user INSERT (user_id = ";
    add_user_query += faculty_id;
    add_user_query += ") AND (password = ";
    add_user_query += faculty_id;
    add_user_query += ") AND (user_type = faculty)";

    db::InsertQuery(add_user_query);

    // Insert new faculty to "faculty" table
    std::string add_faculty_query = "";

    add_faculty_query += "IN faculty INSERT (faculty_id = ";
    add_faculty_query += faculty_id;
    add_faculty_query += ") AND (faculty_name = ";
    add_faculty_query += faculty_name;
    add_faculty_query += ") AND (faculty_dateofbirth = ";
    add_faculty_query += faculty_dateofbirth;
    add_faculty_query += ") AND (faculty_phonenumber = ";
    add_faculty_query += faculty_phonenumber;
    add_faculty_query += ") AND (faculty_placeofbirth = ";
    add_faculty_query += faculty_placeofbirth;
    add_faculty_query += ")";

    db::InsertQuery(add_faculty_query);

    screen::AddEmptyLines(2);
    screen::PrintLine("New faculty added!\n");
    screen::Pad(); std::cout << "* Faculty ID: " << faculty_id << '\n';
    screen::Pad(); std::cout << "* Password: " << faculty_id << '\n';

    screen::Pend();
    screen::Clear();
}


void AdminSession::AddStudent() {
    // Get info of student
    screen::Print("Name: ");
    std::string student_name = io::ToUpperCase(io::ReadLine());

    screen::Print("Date of birth: ");
    std::string student_dateofbirth = io::NextToken();

    screen::Print("Place of birth: ");
    std::string student_placeofbirth = io::ReadLine();

    // Generate new student_id
    std::string student_id = db::AutoIncrementStudentID();

    // Insert new user to "user" table
    std::string add_user_query = "";

    add_user_query += "IN user INSERT (user_id = ";
    add_user_query += student_id;
    add_user_query += ") AND (password = ";
    add_user_query += student_id;
    add_user_query += ") AND (user_type = student)";

    db::InsertQuery(add_user_query);

    // Insert new student to "student" table
    std::string add_student_query = "";

    add_student_query += "IN student INSERT (student_id = ";
    add_student_query += student_id; // NEXTSTUDENTID will be added later
    add_student_query += ") AND (student_name = ";
    add_student_query += student_name;
    add_student_query += ") AND (student_dateofbirth = ";
    add_student_query += student_dateofbirth;
    add_student_query += ") AND (student_placeofbirth = ";
    add_student_query += student_placeofbirth;
    add_student_query += ")";

    db::InsertQuery(add_student_query);

    screen::AddEmptyLines(2);
    screen::PrintLine("New student added!\n");
    screen::Pad(); std::cout << "* Student ID: " << student_id << '\n';
    screen::Pad(); std::cout << "* Password: " << student_id << '\n';

    screen::Pend();
    screen::Clear();
}


/**
 *  @method AddUserActivity
 *  @return {void}
 *
 *  Run "Add user" activity
 *  Code of Trai (has been fixed 1 time)
**/
void AdminSession::AddUserActivity() {
    screen::PrintTitle("ADD USER ACTIVITY");
    screen::PrintLine("Choose account type to add: please input a number");
    screen::PrintLine("1. Faculty");
    screen::PrintLine("2. Student");

    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::string cmd = io::NextToken();

    if (cmd == "1") {
        AddFaculty();
    }
    else if (cmd == "2") {
        AddStudent();
    }
    else {
        screen::ErrorMessage("Invalid choice");
        screen::Pend();
        screen::Clear();
        return;
    }
}


void AdminSession::SearchFaculty() {
    screen::PrintLine("Search Faculty: Choose search method: input a number");
    screen::PrintLine("1. By id");
    screen::PrintLine("2. By name");
    screen::PrintLine("3. By date of birth");
    screen::PrintLine("4. By phone number");
    screen::PrintLine("5. By place of birth");

    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::string cmd = io::NextToken();

    screen::AddEmptyLines(1);
    screen::Pad(); std::cout << "Insert keyword: ";
    std::string keyword = io::NextToken();

    if (cmd == "1") {
        std::string search_query;
        search_query += "IN faculty SEARCH * WHERE faculty_id CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("faculty");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "2") {
        std::string search_query;
        search_query += "IN faculty SEARCH * WHERE faculty_name CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("faculty");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "3") {
        std::string search_query;
        search_query += "IN faculty SEARCH * WHERE faculty_dateofbirth CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("faculty");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "4") {
        std::string search_query;
        search_query += "IN faculty SEARCH * WHERE faculty_phonenumber CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("faculty");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "5") {
        std::string search_query;
        search_query += "IN faculty SEARCH * WHERE faculty_placeofbirth CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("faculty");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else {
        screen::ErrorMessage("Invalid choice");
        screen::Pend();
        screen::Clear();
        return;
    }
}


void AdminSession::SearchStudent() {
    screen::PrintLine("Search Student: Choose search method: input a number");
    screen::PrintLine("1. By id");
    screen::PrintLine("2. By name");
    screen::PrintLine("3. By date of birth");
    screen::PrintLine("4. By place of birth");

    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::string cmd = io::NextToken();

    screen::AddEmptyLines(1);
    screen::Pad(); std::cout << "Insert keyword: ";
    std::string keyword = io::NextToken();

    if (cmd == "1") {
        std::string search_query;
        search_query += "IN student SEARCH * WHERE student_id CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("student");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "2") {
        std::string search_query;
        search_query += "IN student SEARCH * WHERE student_name CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("student");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "3") {
        std::string search_query;
        search_query += "IN student SEARCH * WHERE student_dateofbirth CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("student");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else if (cmd == "4") {
        std::string search_query;
        search_query += "IN student SEARCH * WHERE student_placeofbirth CONTAINS ";
        search_query += keyword;
        std::vector<std::vector<std::string> > query_result = db::SearchQuery(search_query);
        std::vector<std::string> table_headers = db::TableHeaders("student");
        screen::AddEmptyLines(1);
        screen::PrintTable(table_headers, query_result);
    }
    else {
        screen::ErrorMessage("Invalid choice");
        screen::Pend();
        screen::Clear();
        return;
    }
}

void AdminSession::SearchUser() {
    screen::PrintLine("Choose account type to search: please input a number");
    screen::PrintLine("1. Faculty");
    screen::PrintLine("2. Student");

    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::string cmd = io::NextToken();

    if (cmd == "1") {
        SearchFaculty();
    }
    else if (cmd == "2") {
        SearchStudent();
    }
    else {
        screen::ErrorMessage("Invalid choice.");
        screen::Pend();
        screen::Clear();
        return;
    }
}


void AdminSession::DeleteFaculty() {
    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::cout << "Faculty ID: ";
    std::string faculty_id = io::NextToken();

    std::string check_query = "";
    check_query += "IN faculty SELECT * WHERE (faculty_id == ";
    check_query += faculty_id;
    check_query += ")";
    std::vector<std::vector<std::string> > check_query_result = db::SelectQuery(check_query);
    std::vector<std::string> table_headers = db::TableHeaders("faculty");

    screen::Pad();
    if (check_query_result.size() > 0) {
        // Verification
        std::cout << "The program found 1 result:\n";
        screen::PrintTable(table_headers, check_query_result);
        screen::AddEmptyLines(2);

        screen::PrintLine("Are you sure you want to delete this account?");
        screen::PrintLine("1. YES");
        screen::PrintLine("2. NO");
        screen::PadCommand();
        std::string cmd = io::NextToken();
        if (cmd == "2") {
            return;
        }

        // Delete from "user" table
        std::string delete_user_query = "";
        delete_user_query += "IN user REMOVE WHERE (user_id == ";
        delete_user_query += faculty_id;
        delete_user_query += ")";
        db::DeleteQuery(delete_user_query);

        // Delete from "faculty" table
        std::string delete_faculty_query = "";
        delete_faculty_query += "IN faculty REMOVE WHERE (faculty_id == ";
        delete_faculty_query += faculty_id;
        delete_faculty_query += ")";
        db::DeleteQuery(delete_faculty_query);
    }
    else {
        screen::ErrorMessage("faculty_id not found.");
        screen::Pend();
        screen::Clear();
        return;
    }
}


void AdminSession::DeleteStudent() {
    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::cout << "Student ID: ";
    std::string student_id = io::NextToken();

    std::string check_query = "";
    check_query += "IN student SELECT * WHERE (student_id == ";
    check_query += student_id;
    check_query += ")";
    std::vector<std::vector<std::string> > check_query_result = db::SelectQuery(check_query);
    std::vector<std::string> table_headers = db::TableHeaders("student");

    screen::Pad();
    if (check_query_result.size() > 0) {
        // Verification
        std::cout << "The program found 1 result:\n";
        screen::PrintTable(table_headers, check_query_result);
        screen::AddEmptyLines(2);

        screen::PrintLine("Are you sure you want to delete this account?");
        screen::PrintLine("1. YES");
        screen::PrintLine("2. NO");
        screen::PadCommand();
        std::string cmd = io::NextToken();
        if (cmd == "2") {
            return;
        }

        // Delete from "user" table
        std::string delete_user_query = "";
        delete_user_query += "IN user REMOVE WHERE (user_id == ";
        delete_user_query += student_id;
        delete_user_query += ")";
        db::DeleteQuery(delete_user_query);

        // Delete from "student" table
        std::string delete_student_query = "";
        delete_student_query += "IN student REMOVE WHERE (student_id == ";
        delete_student_query += student_id;
        delete_student_query += ")";
        db::DeleteQuery(delete_student_query);
    }
    else {
        screen::ErrorMessage("student_id not found.");
        screen::Pend();
        screen::Clear();
        return;
    }
}


void AdminSession::DeleteUser() {
    screen::PrintLine("Choose account type to delete: please input a number");
    screen::PrintLine("1. Faculty");
    screen::PrintLine("2. Student");

    screen::AddEmptyLines(1);
    screen::PadCommand();
    std::string cmd = io::NextToken();

    if (cmd == "1") {
        DeleteFaculty();
    }
    else if (cmd == "2") {
        DeleteStudent();
    }
    else {
        screen::ErrorMessage("Invalid choice");
        screen::Pend();
        screen::Clear();
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
    screen::PadWidth(20);
    screen::PrintTitle("DELETE USER ACTIVITY");

    while (true) {
        screen::PrintLine("Do you want to:\n");
        screen::PrintLine("1. Search for the user first\n");
        screen::PrintLine("2. Delete without searching (can only delete by user_id)\n");
        screen::PrintLine("3. Go back to Home Screen\n");

        screen::PadCommand();
        std::string cmd = io::NextToken();

        if (cmd == "1") {
            SearchUser();
        }
        else if (cmd == "2") {
            DeleteUser();
        }
        else if (cmd == "3") {
            return;
        }
        else {
            screen::ErrorMessage("Invalid choice");
            screen::Pend();
            screen::Clear();
            return;
        }
    }
}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
 *  Code of Trai
**/
void AdminSession::ChangePasswordActivity() {

    // Let user enter new password
    screen::PrintLine("New password: ");
    std::string new_password = io::NextToken();

    screen::PrintLine("Confirm new password: ");
    std::string confirmation = io::NextToken();

    if (new_password != confirmation) {
        screen::Pad();
        std::cout << "Incorrect password confirmation. Please try again later.\n";
        screen::Pend();
        screen::Clear();
        return;
    }

    std::string query = "";
    query += "IN user SET (password = ";
    query += new_password;
    query += ") WHERE (user_id == ";
    query += admin_id;
    query += ")";
    db::SetQuery(query);

    screen::PrintLine("Password changed successfully");
    screen::Pend();
    screen::Clear();
    return;
}


/* ==================== PUBLIC METHODS  ==================== */


AdminSession::AdminSession(std::string _admin_id) {
    admin_id = _admin_id;
    is_logged_in = true;
}


/**
 *  @method Run
 *  @return {void}
 *
 *  Run an administrator session
**/
void AdminSession::Run() {
    HomeScreen();
}


AdminSession::~AdminSession() {}
