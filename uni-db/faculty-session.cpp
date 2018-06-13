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
    std::string course_search = "IN course SELECT course_id, course_name WHERE (faculty_id == <faculty_id>)";
    std::vector<std::vector<std::string> > search_result = SelectQuery(course_search);

    std::cout << "Course in Faculty: " << std::endl;
    for (int i = 0; i < (int) search_result.size(); i++){
        for (int j = 0; j < (int) search_result[i].size(); j++){
            std::cout << std::setw(5) << search_result[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout<< "Please choose the course id: "
    getchar();

    std::string score_show = "IN score SELECT * WHERE course_id == <course_id>)";
    std::vector<std::vector<std::string> > score_result = SelectQuery(score_show);

    for (int i = 0; i < (int) score_result.size(); i++){
        for (int j = 0; j < (int) score_result[i].size(); j++){
            std::cout << std::setw(5) << score_result[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "Please enter student ID to modify score ";
    IO io();
    std::string student_id = io.NextToken();
    std::cout << "Enter the modified score: ";
    double _score = io.NextDouble();
    std::string score_modify = "IN score SetQuery (score = ) WHERE (course_id == <course_id> AND (student_id == <student_id>";

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
 *  @method Run
 *  @return {void}
 *
 *  Run a faculty session
**/
void FacultySession::Run() {}


FacultySession::~FacultySession() {}
