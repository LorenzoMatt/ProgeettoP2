
#include "profilo.h"

 int Profilo::numeroelementi=0;

Profilo::Profilo(const string& n,const string& c,const string& e):nome(n),cognome(c),email(e){numeroelementi++;}
void Profilo::set_nome(const string& n){nome=n;}
void Profilo::set_cognome(const string& c){cognome=c;}
void Profilo::set_email(const string& e){email=e;}

void Profilo::set_competenze(const container<std::string> &c)
{
    competenze=c;
}

void Profilo::set_titoli_di_studio(const container<std::string> &t)
{
    titoli_di_studio=t;
}

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

std::ostream& operator<<(std::ostream& os,const Profilo& p){
    os<<"nome: " <<p.get_nome()<<endl<<"cognome: "<<p.get_cognome()<<endl<<"email: "<<p.get_email();
    os<<endl<<"competenze: "<<p.competenze;
    os<<endl<<"Titoli di studio: "<<p.titoli_di_studio;
    return os;

}




