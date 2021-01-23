
#ifndef PROFILO_H
#define PROFILO_H

#include <container.h>
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
    void set_cognome(const string&); 
    void set_email(const string&); 
    void set_competenze(const container<string>&);
    void set_titoli_di_studio(const container<string>&);
    void aggiungi_competenza(const string&); 
    void aggiungi_titolo_di_studio (const string&); 

    string get_nome() const; 
    string get_cognome() const; 
    string get_email() const;
    string competenze_toString() const;
    string titoli_di_studio_toString() const;

    container<string> GetCompetenze() const; 
    container<string> GetTitoliDiStudio() const; 



};

#endif // PROFILO_H

