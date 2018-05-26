#ifndef FACULTY_H
#define FACULTY_H


#include <string>


class Faculty {
    private:
        std::string id;

        void HomeActivity();
        void MainHelper();

        void OpenCourseActivity();
        void SummarizeScoreActivity();
        void ModifyScoreActivity();
        void ChangePasswordActivity();


    public:
        Faculty();
        void Session();
        ~Faculty();
};


#endif // FACULTY_H
