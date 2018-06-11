#ifndef ADMIN_SESSION_H
#define ADMIN_SESSION_H


class AdminSession {
    private:
        std::string admin_id;

        void HomeScreen();
        void HomeHelper();

        void AddUserActivity();
        void DeleteUserActivity();
        void ChangePasswordActivity();

    public:
        AdminSession(std::string _admin_id);
        void Run();
        ~AdminSession();
};


#endif // ADMIN_SESSION_H