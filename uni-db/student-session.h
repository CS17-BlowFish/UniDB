#ifndef STUDENT_SESSION_H
#define STUDENT_SESSION_H


#include <string>


class Student {
    private:
        std::string id;

        void HomeActivity();
        void MainHelper();

        void CourseRegisterActivity();
        void CourseDeregisterActivity();
        void ViewProfileActivity();
        void ChangePasswordActivity();


    public:
        Student();
        void Session();
        ~Student();
};


#endif // STUDENT_SESSION_H