#ifndef ACCESSO_H
#define ACCESSO_H
#include <iostream>
using std::string;
class Accesso
{
private:
    string username;
    string password;
    Accesso();
public:
    Accesso(string,string);
    void set_username(string);
    void set_password(string);
    string get_username() const;
    string get_password() const;
};

#endif // ACCESSO_H
