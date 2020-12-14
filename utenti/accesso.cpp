#include "accesso.h"

accesso::accesso(string username, string password) : username(username),password(password)
{
}

void accesso::set_username(string username)
{
    this->username=username;
}

void accesso::set_password(string password)
{
    this->password=password;
}

std::string accesso::get_username() const
{
    return username;
}

std::string accesso::get_password() const
{
    return password;
}
