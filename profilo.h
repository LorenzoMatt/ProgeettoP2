#ifndef PROFILO_H
#define PROFILO_H

#include <string>
#include <iostream>
#include <Container.h>

using std::cout;
using std::endl;
using std::string;
using container::dList;

class profilo
{
   friend std::ostream& operator<<(std::ostream& os,const profilo& u);

    string nome;
    string cognome;
    string email;
    dList<string>competenze;
    dList<string> titoli_di_studio;
    profilo();

public:
    profilo(const string&,const string&,const string&);
    ~profilo();
    void SetNome(const string&);
    void SetCognome(const string&);
    void SetEmail(const string&);
    void AggiungiCompetenza(const string&);
    void AggiungiTitoloDiStudio (const string&);

    string GetNome() const;
    string GetCognome() const;
    string GetEmail() const;

    dList<string> GetCompetenze() const;
    dList<string> GetTitoliDiStudio() const;



};

#endif // PROFILO_H
