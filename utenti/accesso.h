#ifndef ACCESSO_H
#define ACCESSO_H
#include <iostream>
using std::string;
class accesso
{
private:
    string username;
    string password;
    accesso();
public:
    accesso(string,string);
    void set_username(string);
    void set_password(string);
    string get_username() const;
    string get_password() const;
};

#endif // ACCESSO_H
