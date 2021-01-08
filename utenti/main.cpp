
#include <QApplication>
#include "utente.h"
#include "database.h"
#include "deepptr.h"

#include "vista_utente.h"
#include "vista_domanda.h"
#include "controller.h"
#include "account.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include "log.h"
//#include "vista_amministratore.h"



int main(int argc ,char** argv)
{

   QApplication x(argc, argv);
   Login v;

   v.show();
   return x.exec();

   // creo degli utenti amicizie e domande

    //vengono creati 6 utenti
//       Database m;
//       m.aggiungi_utente(new Premium("Pikachu","dioboia","pikachu","porco","dio"));
//       m.aggiungi_utente(new Gold("Lorenzo","stronzo","lorenzo","porco","dio"));
//       m.aggiungi_utente(new Basic("Elton","diocan","elton","porco","dio"));
//       m.aggiungi_utente(new Gold("Francesca","diobestia","francesca","porco","dio"));
//       m.aggiungi_utente(new Premium("Mirko","dioluamaro","mirko","porco","dio"));
//       m.aggiungi_utente(DeepPtr<Utente>(new Basic("Giorgia","giorgia","diostronzo","porco","dio")));


//       Utente* Lorenzo=m.get_utente("Lorenzo");
//       Utente* Elton=m.get_utente("Elton");
//       Utente* Francesca=m.get_utente("Francesca");
//       Utente* Mirko=m.get_utente("Mirko");
//       Utente* Giorgia=m.get_utente("Giorgia");
//       Utente* Pikachu=m.get_utente("Pikachu");

//       Pikachu->aggiungi_amico(Lorenzo);
//       Pikachu->AggiungiCompetenza("farsi le seghe");
//       Pikachu->AggiungiCompetenza("prendere a pugni i barboni");
//       Pikachu->AggiungiCompetenza("vendere la droga");
//       Pikachu->AggiungiTitoloDiStudio("Laurea in bere vino");
//       Pikachu->AggiungiTitoloDiStudio("Laurea in dinosauri con il cazzo lungo");
//       Lorenzo->aggiungi_amico(Pikachu);
//       Pikachu->aggiungi_amico(Elton);
//       Pikachu->aggiungi_amico(Mirko);
//       Pikachu->aggiungi_amico(Giorgia);
//       Giorgia->AggiungiCompetenza("masturbarsi");
//       Giorgia->AggiungiCompetenza("masturbarsi");

//       Domanda* domanda1=new Domanda("sono grande?",Lorenzo,2);
//       Domanda* domanda2=new Domanda("sono bello?",Lorenzo,2);
//       Domanda* domanda3=new Domanda("sono magnanime?",Lorenzo,2);
//       Domanda* domanda4=new Domanda("sono Mirko?",Lorenzo,2);
//       Domanda* domanda5=new Domanda("sono Lorenzo?",Lorenzo,2);

//       Lorenzo->fai_domanda(domanda1);
//       Lorenzo->fai_domanda(domanda2);
//       Lorenzo->fai_domanda(domanda3);
//       Lorenzo->fai_domanda(domanda4);
//       Lorenzo->fai_domanda(domanda5);
//       Pikachu->scrivi_commento(domanda1,"dio porco");
//       Pikachu->scrivi_commento(domanda1,"la madonna");
//       Pikachu->scrivi_commento(domanda1,"gesu");
//       Pikachu->fai_domanda(new Domanda("prova a fare una domanda",Pikachu,2));
//       Pikachu->fai_domanda(new Domanda("prova a fare una domanda",Pikachu,2));
//       Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));
//       Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));
//       Giorgia->fai_domanda(new Domanda("prova a fare una domanda",Giorgia,1));

//       Giorgia->scrivi_commento(domanda1,"prova per un commento");
//       Giorgia->scrivi_commento(domanda1,"prova per un commento");
//       Giorgia->scrivi_commento(domanda1,"prova per un commento");
//       Giorgia->scrivi_commento(domanda2,"prova per un commento");
//       Giorgia->scrivi_commento(domanda3,"prova per un commento");
//       Giorgia->scrivi_commento(domanda2,"prova per un commento");
//       m.exportdati();




//       m.import();

}
