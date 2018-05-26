#ifndef STUDENT_H
#define STUDENT_H


#include <string>


class Student {
    private:
        std::string id;

        void HomeActivity();
        void MainHelper();

        void CourseRegisterActivity();
        void CourseUnregisterActivity();
        void ViewProfileActivity();
        void ChangePasswordActivity();


    public:
        Student();
        void Session();
        ~Student();
};


#endif // STUDENT_H
