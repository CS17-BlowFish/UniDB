#include "faculty-session.h"
#include "task.h"

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
