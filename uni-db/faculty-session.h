#ifndef FACULTY_SESSION_H
#define FACULTY_SESSION_H


#include <string>


class FacultySession {
    private:
        std::string id;

        void HomeScreen();
        void HomeHelper();

        void OpenCourseActivity();
        void SummarizeScoreActivity();
        void ModifyScoreActivity(){
            std::string faculty_id;
            std::string course_id;
            std::string student_id;
        };
        void ChangePasswordActivity();


    public:
        FacultySession();
        void Run();
        ~FacultySession();
};


#endif // FACULTY_SESSION_H
