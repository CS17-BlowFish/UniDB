#ifndef ADMIN_H
#define ADMIN_H


class Admin {
    private:
        void HomeActivity();
        void MainHelper();

        void AddUserActivity();
        void DeleteUserActivity();
        void ChangePasswordActivity();

    public:
        Admin();
        void Session();
        ~Admin();
};


#endif // ADMIN_H
