#include "accesso.h"

Accesso::Accesso(string username, string password) : username(username),password(password)
{
}

void Accesso::set_username(string username)
{
    this->username=username;
}

void Accesso::set_password(string password)
{
    this->password=password;
}

string Accesso::get_username() const
{
    return username;
}

string Accesso::get_password() const
{
    return password;
}
