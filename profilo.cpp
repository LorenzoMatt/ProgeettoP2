#include "profilo.h"


profilo::profilo(){}
profilo::~profilo(){}
profilo::profilo(const string& n,const string& c,const string& e):nome(n),cognome(c),email(e){}

void profilo::SetNome(const string& n){nome=n;}
void profilo::SetCognome(const string& c){cognome=c;}
void profilo::SetEmail(const string& e){email=e;}

void profilo::AggiungiCompetenza(const string& c){
    competenze.insertBack(c);
}

void profilo::AggiungiTitoloDiStudio (const string& t){
    titoli_di_studio.insertBack(t);
}

string profilo::GetNome() const{return nome;}
string profilo::GetCognome() const{return cognome;}
string profilo::GetEmail() const{return email;}

dList<string> profilo::GetCompetenze() const{
   dList<string> aux;
    for(auto it=competenze.cbegin();it!=competenze.cend();++it){
        aux.insertBack(*it);
    }
    return aux;
}

dList<string> profilo::GetTitoliDiStudio() const{
    dList<string> aux;
    for(auto it=titoli_di_studio.cbegin();it!=titoli_di_studio.cend();++it){
        aux.insertBack(*it);
    }
    return aux;
}
std::ostream& operator<<(std::ostream& os,const profilo& p){

   return os<<p.nome<<endl<<p.cognome<<endl<<p.email<<endl<<p.competenze<<p.titoli_di_studio;
}



