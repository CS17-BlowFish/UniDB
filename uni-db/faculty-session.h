#ifndef FACULTY_SESSION_H
#define FACULTY_SESSION_H


#include <string>


class FacultySession {
    private:
        std::string faculty_id;

        void HomeScreen();
        void HomeHelper();

        void OpenCourseActivity();
        void SummarizeScoreActivity();
        void ModifyScoreActivity(){};
        void ChangePasswordActivity();


    public:
        FacultySession();
        void Run();
        ~FacultySession();
};


#endif // FACULTY_SESSION_H
