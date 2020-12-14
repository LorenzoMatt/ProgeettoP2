//#ifndef PROFILO_H
//#define PROFILO_H

//#include <string>
//#include <iostream>
//#include "container.h"
//using std::cout;
//using std::endl;
//using std::string;


//class profilo
//{
//    //class nodo;
//    string nome;
//    string cognome;
//    string email;
//    container<string> lingue;
//    //nodo* competenze;
//    //nodo* titoli_di_studio;
//    class nodo{
//    public:
//        int info;
//        nodo* next;
//        nodo();
//        nodo(int,nodo* n=0);
//    };

//public:
//    profilo();
//    void SetNome(string);
//    void SetCognome(string);
//    void SetEmail(string);
//    //i metodi Aggiungi aggiungono in coda
//    void AggiungiLingua(string);
//    //void AggiungiCompetenza(string);
//    //void AggiungiTitoloDiStudio(string);
//    void StampaLingue() const;
//};

//#endif // PROFILO_H
#ifndef PROFILO_H
#define PROFILO_H

#include <string>
#include <iostream>
#include <list>
#include "container.h"
using std::cout;
using std::endl;
using std::string;
using std::list;


class profilo
{
   friend std::ostream& operator<<(std::ostream& os,const profilo& u);
    string nome;
    string cognome;
    string email;
    container<string>competenze;
    container<string> titoli_di_studio;
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
    container<string>::const_iterator GetCompetenze() const;
    container<string>::const_iterator GetTitoliDiStudio() const;


};

#endif // PROFILO_H


