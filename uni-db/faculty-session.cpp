#include "faculty-session.h"
#include "task.h"
#include <iomanip>

/* ==================== PRIVATE METHODS ==================== */


/**
 *  @method HomeScreen
 *  @return {void}
 *
 *  Run "Home" Screen
**/
void FacultySession::HomeScreen() {

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
    std::string score_modify = "IN score SET (score = ) WHERE (course_id == <course_id> AND (student_id == <student_id>";

}


/**
 *  @method ChangePasswordActivity
 *  @return {void}
 *
 *  Run "Change password" activity
**/
void FacultySession::ChangePasswordActivity() {
	std::string password;
	std::cout << "New password: ";
	std::cin >> password;
	Task _task;
	_task.replace_data(0, id, 1, password);
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
