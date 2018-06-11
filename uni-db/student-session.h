#ifndef STUDENT_SESSION_H
#define STUDENT_SESSION_H


#include <string>


class StudentSession {
    private:
        std::string id;

        void HomeActivity();
        void MainHelper();

        void CourseRegisterActivity();
        void CourseDeregisterActivity();
        void ViewProfileActivity();
        void ChangePasswordActivity();


    public:
		StudentSession();
       // void Session();
        ~StudentSession();
};


#endif // STUDENT_SESSION_H