#ifndef STUDENT_SESSION_H
#define STUDENT_SESSION_H


#include <string>


class StudentSession {
    private:
        std::string student_id;

        void HomeScreen();
        void HomeHelper();

        void CourseRegisterActivity();
        void CourseDeregisterActivity();
        void ViewProfileActivity();
        void ChangePasswordActivity();


    public:
        StudentSession();
        void Run();
        ~StudentSession();
};


#endif // STUDENT_SESSION_H
