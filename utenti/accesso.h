#ifndef ACCESSO_H
#define ACCESSO_H
#include <string>
using std::string;
class Accesso
{
private:
    string username;
    string password;
public:
    Accesso()=delete;
    Accesso(string,string);
    void set_username(string);
    void set_password(string);
    string get_username() const;
    string get_password() const;
};

#endif // ACCESSO_H

//ciao ranzato dacci un bel voto ti conviene
