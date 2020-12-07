#ifndef PROFILO_H
#define PROFILO_H

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;


class profilo
{
    class nodo;
    string nome;
    string cognome;
    string email;
    nodo* lingue;
    //nodo* competenze;
    //nodo* titoli_di_studio;
    class nodo{
    public:
        int info;
        nodo* next;
        nodo();
        nodo(int,nodo* n=0);
    };

public:
    profilo();
    void SetNome(string);
    void SetCognome(string);
    void SetEmail(string);
    //i metodi Aggiungi aggiungono in coda
    void AggiungiLingua(int* l,int dim);
    //void AggiungiCompetenza(string);
    //void AggiungiTitoloDiStudio(string);
    void StampaProfilo() const;
};

#endif // PROFILO_H
