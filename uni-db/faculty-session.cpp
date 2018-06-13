#include "faculty-session.h"
#include "io.h"

#include <stdio.h>
#include <iostream>
#include <string>


/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" Screen
 *  Code from Trai
**/
void FacultySession::HomeScreen() {
    IO io;

    do {
        std::string choice = io.NextToken();

        std::cout << "1.Open Course \n";
        std::cout << "2.Summarize Score\n";
        std::cout << "3.Modify Score \n";
        std::cout << "4.Change Password\n";
        std::cout << "5.Help??\n";

        if (choice == "1" || choice == "o" || choice == "oc") {
            OpenCourseActivity();
        }
        else if (choice == "2" || choice == "s" || choice == "sum") {
            SummarizeScoreActivity();
        }
        else if (choice == "3" || choice == "r" || choice == "revise") {
            ModifyScoreActivity();
        }
        else if (choice == "4" || choice == "p" || choice == "passwd") {
            ChangePasswordActivity();
        }
        else if (choice == "5") {
            HomeHelper();
        }
    } while(1);
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
 *
 *  Code from Trai
**/
void FacultySession::HomeHelper() {
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
    //Check if the faculty has reached the maximum number of courses this semester (5 courses)
IO io();

    std::cout << "Enter semester: ";
        semester_id = io.NextToken();

    std::string search_faculty_query  = "";
                search_faculty_query += "IN course SELECT faculty_id WHERE";
                search_faculty_query += "(semester_id == ";
                search_faculty_query += semester_id;
                search_faculty_query += ")";
            
    std::vector<std::vector<std::string> > search_faculty_result = SelectQuery(search_faculty_query);

    if (search_faculty_result.size() >= 5)
    {
        std::cout << "Reach maximum of courses";
        return;
    }
    
    else
    //Insert new course into "course" table
    
    //string, 6 digits, auto-increment	
    std::cout << "Enter the course ID: "; //100% no need 
    course_id = io.NextToken(); 			
	
    //2 letters + 2 digits
    std::cout << "Enter the course code: ";
    course_code = io.NextToken();
    
    std::cout << "Course's name: ";
    std::string course_name = io.ToUpperCase(io.ReadLine());
    
    //3 digits
    std::cout << "Enter the semester id: ";
    semester_id = io.NextToken();
    
    //less than or equal to slots
    std::cout << "Enter the registered: ";
    std::string registered = io.NextInt();
    
    std::cout << "Number of slots: ";
    std::string slots = io.NextInt();
    
    std::string add_course_query  = "";
                add_course_query += "IN course INSERT (course_id = ";
                add_course_query += course_id;
                add_course_query += ")" AND "(course_code = ";
                add_course_query += course_code;
                add_course_query += ")" AND "(course_name = ";
                add_course_query += course_name;
                add_course_query += ")" AND "(faculty_id = ";
                add_course_query += faculty_id;
                add_course_query += ")" AND "(semester_id = ";
                add_course_query += semester_id;
                add_course_query += ")" AND "(registered = ";
                add_course_query += registered;
                add_course_query += ")" AND "(slots = ";
                add_course_query += slots;
	        add_course_query += ")";
            
    InsertQuery(add_course_query);
}


/**
 *  @method SummarizeScoreActivity
 *  @return {void}
 *
 *  Run "Summarize scores of a course" activity
**/
void FacultySession::SummarizeScoreActivity() {
IO io();
    //Search all courses of the faculty
    std::string search_course_query  = "";
                search_course_query += "IN course SELECT course_id, course_name ";
                search_course_query += "WHERE (faculty_id == ";
                search_course_query += faculty_id;
                search_course_query += ")";

    std::vector<std::vector<std::string> > search_course_result = SelectQuery(search_course_query);

    std::cout << "Course(s) of faculty: " << std::endl;

    for (int i = 0; i < (int) search_course_result.size(); i++){
        for (int j = 0; j < (int) search_course_result[i].size(); j++){
            std::cout << std::setw(5) << search_course_result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    //Let the faculty choose the course by id and show scores
    std::cout<< "Choose the course's id: "
    std::string course_id = io.NextToken();

    std::string show_score_query  = "";
                show_score_query += "IN score SELECT student_id, score WHERE (course_id == ";
                show_score_query += course_id;
                show_score_query += ")";
    std::vector<std::vector<std::string> > show_score_result = SelectQuery(show_score_query);

    for (int i = 0; i < (int) show_score_result.size(); i++){
        for (int j = 0; j < (int) show_score_result[i].size(); j++){
            std::cout << std::setw(5) << show_score_result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/**
 *  @method ModifyScoreActivity
 *  @return {void}
 *
 *  Run "Modify scores of a course" activity
 *  Code of Tuan
**/
void FacultySession::ModifyScoreActivity() {
    IO io();
    //Search all courses of the faculty
    std::string course_search_query = "";
    course_search_query += "IN course SELECT course_id, course_name ";
    course_search_query += "WHERE (faculty_id == ";
    course_search_query += faculty_id;
    course_search_query += ")";

    std::vector<std::vector<std::string> > search_result = SelectQuery(course_search_query);
   
    std::cout << "Course of Faculty: " << std::endl;

    for (int i = 0; i < (int) search_result.size(); i++){
        for (int j = 0; j < (int) search_result[i].size(); j++){
            std::cout << std::setw(5) << search_result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    //Let the faculty choose the course by id and show scores:
    std::cout<< "Please choose the course id: "
    std::string course_id = io.NextToken();

    std::string score_show_query = "";
    score_show_query += "IN score SELECT * WHERE (course_id == ";
    score_show_query += course_id;
    score_show_query += ")";
    std::vector<std::vector<std::string> > score_result = SelectQuery(score_show_query);

    for (int i = 0; i < (int) score_result.size(); i++){
        for (int j = 0; j < (int) score_result[i].size(); j++){
            std::cout << std::setw(5) << score_result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //Let the faculty input the student id and the modified score
    std::cout << "Please enter student ID to modify score ";
    std::string student_id = io.NextToken();

    std::cout << "Enter the modified score: ";
    double new_score = io.NextDouble();

    std::string score_modify_query = "";
    score_modify_query += "IN score SET (score = ";
    score_modify_query += std::to_string(new_score);
    score_modify_query += ") WHERE (course_id == ";
    score_modify_query += course_id;
    score_modify_query += ") AND (student_id == ";
    score_modify_query += student_id;
    score_modify_query += ")";

    SetQuery(score_modify_query);
}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void FacultySession::ChangePasswordActivity() {
    IO io;

    std::cout << "New password: ";
    string  new_password = io.NextToken();//User enter new password

    std::string query = "IN user SET (password = new_password) WHERE (user_id == id)";

    SetQuery(query);

}


/* ==================== PUBLIC METHODS  ==================== */


FacultySession::FacultySession() {}


/**
 *  @method Run
 *  @return {void}
 *
 *  Run a faculty session
**/
void FacultySession::Run() {}


FacultySession::~FacultySession() {}
