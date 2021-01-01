//#include "profilo.h"

//profilo::profilo(){}

//void profilo::SetNome(string n){nome=n;}
//void profilo::SetCognome(string c){cognome=c;}
//void profilo::SetEmail(string e){email=e;}

//profilo::nodo::nodo():next(0){}
//profilo::nodo::nodo(int i,nodo* n):info(i),next(n){}

//void profilo::AggiungiLingua(string lingua){
//    lingue.insertBack(lingua);
//}

//void profilo::StampaLingue() const{
//    for(auto it=lingue.cbegin();it!=lingue.cend();++it)
//        cout<<*it<<endl;
//}
/*
#include "profilo.h"


profilo::profilo(){}
profilo::~profilo(){}
profilo::profilo(const string& n,const string& c,const string& e):nome(n),cognome(c),email(e){}

void profilo::SetNome(const string& n){nome=n;}
void profilo::SetCognome(const string& c){cognome=c;}
void profilo::SetEmail(const string& e){email=e;}

void profilo::AggiungiCompetenza(const string& c){
    competenze.insertFront(c);
}
void profilo::AggiungiTitoloDiStudio (const string& t){
    titoli_di_studio.insertFront(t);
}

string profilo::GetNome() const{return nome;}
string profilo::GetCognome() const{return cognome;}
string profilo::GetEmail() const{return email;}

container<string>::const_iterator profilo::GetCompetenze() const{
    auto it=competenze.cbegin();
    return it;
}
container<string>::const_iterator profilo::GetTitoliDiStudio() const{
    auto it=titoli_di_studio.cbegin();
    return it;
}

std::ostream& operator<<(std::ostream& os,const profilo& p){
    os<<"nome: " <<p.GetNome()<<endl<<"cognome: "<<p.GetCognome()<<endl<<"email: "<<p.GetEmail();
    os<<endl<<"competenze: ";
    for(auto it=p.GetCompetenze();it!=p.competenze.cend();++it)
        os<<*it<<"  ";
    os<<endl<<"Titoli di studio: ";
    for(auto it=p.GetTitoliDiStudio();it!=p.titoli_di_studio.cend();++it)
        os<<*it<<"  ";
    return os;

}
*/
#include "profilo.h"


//Profilo::Profilo(){}
Profilo::~Profilo(){}
Profilo::Profilo(const string& n,const string& c,const string& e):nome(n),cognome(c),email(e){}

void Profilo::set_nome(const string& n){nome=n;}
void Profilo::set_cognome(const string& c){cognome=c;}
void Profilo::set_email(const string& e){email=e;}

void Profilo::aggiungi_competenza(const string& c){
    competenze.push_back(c);
}

void Profilo::aggiungi_titolo_di_studio (const string& t){
    titoli_di_studio.push_back(t);
}

string Profilo::get_nome() const{return nome;}
string Profilo::get_cognome() const{return cognome;}
string Profilo::get_email() const{return email;}

std::string Profilo::competenze_toString() const
{
    string c;
    for(container<string>::const_iterator it=competenze.cbegin();it!=competenze.cend();++it)
        c=c+" "+*it;
    return c;
}

std::string Profilo::titoli_di_studio_toString() const
{
    string t;
    for(container<string>::const_iterator it=titoli_di_studio.cbegin();it!=titoli_di_studio.cend();++it)
        t=t+" "+*it;
    return t;
}

container<string> Profilo::GetCompetenze() const{
    return competenze;
}

container<string> Profilo::GetTitoliDiStudio() const{
    return titoli_di_studio;
}
/*
std::ostream& operator<<(std::ostream& os,const profilo& p){

   return os<<p.nome<<endl<<p.cognome<<endl<<p.email<<endl<<p.competenze<<p.titoli_di_studio;
}*/
std::ostream& operator<<(std::ostream& os,const Profilo& p){
    os<<"nome: " <<p.get_nome()<<endl<<"cognome: "<<p.get_cognome()<<endl<<"email: "<<p.get_email();
    os<<endl<<"competenze: "<<p.competenze;
    os<<endl<<"Titoli di studio: "<<p.titoli_di_studio;
    return os;

}




