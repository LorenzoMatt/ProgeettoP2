
#ifndef PROFILO_H
#define PROFILO_H

#include <string>
#include <iostream>
#include <container.h>
using std::cout;
using std::endl;
using std::string;

class Profilo
{
   friend std::ostream& operator<<(std::ostream& os,const Profilo& u);
private:
    string nome;
    string cognome;
    string email;
    container<string>competenze;
    container<string> titoli_di_studio;



public:
    Profilo()=delete;
    Profilo(const string&,const string&,const string&);
    void set_nome(const string&); // OK
    void set_cognome(const string&); //OK
    void set_email(const string&); //OK
    void set_competenze(const container<string>&);
    void set_titoli_di_studio(const container<string>&);
    void aggiungi_competenza(const string&); //OK
    void aggiungi_titolo_di_studio (const string&); //OK

    string get_nome() const; //OK
    string get_cognome() const; //OK
    string get_email() const;//OK
    string competenze_toString() const;
    string titoli_di_studio_toString() const;

    container<string> GetCompetenze() const; //OK
    container<string> GetTitoliDiStudio() const; //OK



};

#endif // PROFILO_H

