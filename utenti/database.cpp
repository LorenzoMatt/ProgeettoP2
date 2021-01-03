#include "database.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"

Database::Database()
{

}

bool Database::check_presenza(const std::string &username)
{
    bool trovato=false;
    for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
    {
        if((*it)->get_credenziali().get_username()==username)
            trovato=true;
    }
    return trovato;
}

void Database::sistema_amici_seguaci(Utente* utente)
{
        for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
        {
            (*it)->togli_amico_ausiliario(utente);
        }
        for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
        {
            (*it)->togli_seguace_ausiliario(utente);
        }
}

void Database::reverse_seguaci_amici(Utente* utente)
{
        for(auto it=utente->seguaci.begin();it!=utente->seguaci.end();++it)
        {
            (*it)->amici.push_back(utente);
        }
        for(auto it=utente->amici.begin();it!=utente->amici.end();++it)
        {
            (*it)->seguaci.push_back(utente);
        }
}

Database::Database(const container<DeepPtr<Utente> > &u):utenti(u)
{
}

void Database::aggiungi_utente(const DeepPtr<Utente> &utente)
{
    try{
        if(!check_presenza(utente->get_credenziali().get_username()))
            utenti.push_back(utente);
        else
            throw utente_gia_presente();
    }catch(utente_gia_presente)
    {
        std::cerr<<"utente con questo username già presente";
    }

}

void Database::togli_utente(Utente *utente)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                sistema_amici_seguaci(utente);
                utenti.erase(it);
                trovato=true;
            }
        }
        if(!trovato)
        {
            throw amico_non_presente();
        }
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
}

void Database::togli_utente(const std::string & username)
{
        bool trovato=false;
        try
        {
            for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            {
                if((*it)->get_credenziali().get_username()==username)
                {
                    sistema_amici_seguaci(&(**it));
                    utenti.erase(it);
                    trovato=true;
                }
            }
            if(!trovato)
            {
                throw amico_non_presente();
            }
        }catch(amico_non_presente)
        {
            std::cerr<<"utente non presente";
        }
}

Utente* Database::cambia_piano(Utente *utente, const std::string &piano)
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
        {
            if(&(**it)==utente)
            {
                sistema_amici_seguaci(utente);
                trovato=true;
                Profilo pf=(*it)->get_profilo();
                Accesso credenziali=(*it)->get_credenziali();
                container<Domanda*> domande=(*it)->get_domande();
                container<Utente*> amici=(*it)->get_amici();
                container<Utente*> seguaci=(*it)->get_seguaci();
                unsigned int risposte_date=(*it)->get_risposte_date();
                unsigned int punti=(*it)->get_punti();
                if(piano=="Basic")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Basic(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                if(piano=="Gold")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Gold(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                if(piano=="Premium")
                    it=utenti.insert(utenti.erase(it),DeepPtr<Utente>(new Premium(pf,credenziali,amici,seguaci,domande,punti,risposte_date)));
                reverse_seguaci_amici(&(**it));
                return &(**it);
            }
        }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non trovato";
    }
    return nullptr;
}

Utente* Database::check_credenziali(const std::string & username, const std::string & password) const
{
        for(auto it=utenti.begin();it!=utenti.end();++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                if((*it)->get_credenziali().get_password()==password)
                    return &(**it);
                else
                    return 0;
            }
        return 0;
}

const container<DeepPtr<Utente>>& Database::get_utenti() const
{
    return utenti;
}

Utente* Database::get_utente(const string& username) const
{
    bool trovato=false;
    try
    {
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(**it);
            }
        if(!trovato)
            throw amico_non_presente();
    }
    catch(amico_non_presente)
    {
        std::cerr<<"utente "<<username<<" non presente"<<endl;
    }
    return 0;

}

DeepPtr<Utente> *Database::get_utente_deep(const std::string & username)
{
    bool trovato=false;
    try{
        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(*it);
            }
        if(!trovato)
            throw amico_non_presente();
    }catch(amico_non_presente)
    {
        std::cerr<<"utente non presente";
    }
    return 0;
}

void Database::exportdati() const
{


    try
    {
        QFile* file = new QFile("../database.xml");
        if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        {
            throw std::runtime_error("il file non è stato aperto");
            //       QMessageBox err;
            //       err.setText("Errore nell'apertura del file");
            //       err.exec();
        }
        else
        {
            QXmlStreamWriter* inp = new QXmlStreamWriter;
            inp->setAutoFormatting(true);
            inp->setDevice(file);
            inp->writeStartDocument();
            inp->writeStartElement("campi_dati_utenti"); // inizio dei campi dati utenti
            for(auto it=utenti.begin();it!=utenti.end();++it)
            {
                inp->writeStartElement("utente");// inizio singolo utente
                if(dynamic_cast<Basic*>(&**it))
                {
                    inp->writeTextElement("tipoutente", QString::fromStdString("Basic"));
                }
                if(dynamic_cast<Gold*>(&**it))
                {
                    inp->writeTextElement("tipoutente", QString::fromStdString("Gold"));
                }
                if(dynamic_cast<Premium*>(&**it))
                {
                    inp->writeTextElement("tipoutente", QString::fromStdString("Premium"));
                }
                inp->writeTextElement("username",QString::fromStdString(((*it)->get_credenziali()).get_username()));
                inp->writeTextElement("password",QString::fromStdString(((*it)->get_credenziali()).get_password()));
                inp->writeTextElement("nome", QString::fromStdString(((*it)->get_profilo()).get_nome()));
                inp->writeTextElement("cognome", QString::fromStdString(((*it)->get_profilo()).get_cognome()));
                inp->writeTextElement("email", QString::fromStdString(((*it)->get_profilo()).get_email()));
                inp->writeTextElement("competenze", QString::fromStdString(((*it)->get_profilo()).competenze_toString()));
                inp->writeTextElement("titoli_di_studio", QString::fromStdString(((*it)->get_profilo()).titoli_di_studio_toString()));
                inp->writeTextElement("punti", QString::fromStdString(std::to_string(((*it)->get_punti()))));
                inp->writeTextElement("risposte_date", QString::fromStdString(std::to_string(((*it)->get_risposte_date()))));
                inp->writeEndElement();// fine di un utente
            }
            inp->writeEndElement();// fine campi dati degli utenti

            inp->writeEndDocument();
            file->close();
        }

            ////// file per gli amici e le domande
            QFile* file2 = new QFile("../database_domande_e_amici.xml");
            if(!file2->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                throw std::runtime_error("il file non è stato aperto");
                //       QMessageBox err;
                //       err.setText("Errore nell'apertura del file");
                //       err.exec();
            }
            else
            {
                QXmlStreamWriter* inp = new QXmlStreamWriter;
                inp->setAutoFormatting(true);
                inp->setDevice(file2);
                inp->writeStartDocument();
                inp->writeStartElement("domande_e_amici");
            for(auto it=utenti.begin();it!=utenti.end();++it)
            {
                inp->writeStartElement("utente");
                inp->writeTextElement("username",QString::fromStdString(((*it)->get_credenziali()).get_username()));
//                inp->writeStartElement(QString::fromStdString(((*it)->get_credenziali()).get_username()));
                inp->writeTextElement("amici",QString::fromStdString((*it)->get_username_amici()));
//                inp->writeStartElement("domande");
                for(auto d=(*it)->get_domande().begin();d!=(*it)->get_domande().end();++d)
                {
                    inp->writeStartElement("domanda");
                    inp->writeTextElement("priorita",QString::fromStdString(std::to_string((*d)->get_priorita())));
                    inp->writeTextElement("testo",QString::fromStdString(((*d)->get_testo())));
                    inp->writeStartElement("commenti");
                    container<Commento> commenti=(*d)->get_commenti();
                    for(auto c=commenti.begin();c!=commenti.end();++c)
                    {
                        inp->writeStartElement("commento");// inizio commento
                        inp->writeTextElement("testo",QString::fromStdString(((*c).get_testo())));
                        inp->writeTextElement("autore_commento",QString::fromStdString((*c).get_autore()->get_credenziali().get_username()));
                        inp->writeEndElement();// fine commento
                    }
//                    inp->writeEndElement();// fine delle domande
                    inp->writeEndElement();//fine commenti
                    inp->writeEndElement();//fine domanda

                }
                inp->writeEndElement();// fine utente
            }
            inp->writeEndElement();// fine domande_amici

            inp->writeEndDocument();
            file2->close();
        }
    }
    catch(std::runtime_error& r)
    {
           cout << r.what() << "\n";
    }

}



void Database::importa_dati_utenti()
{
    QFile* file=new QFile("../database.xml");
    if (!file->open(QFile::ReadOnly | QFile::Text))
    {
        throw std::runtime_error("errore nell'apertura del file");
    }
    else
    {
        QDomDocument documento;
        if(!documento.setContent(file)){
            return;
        }
        QDomElement root = documento.documentElement();//salvo la radice del file
        QDomNodeList nodes = root.elementsByTagName("utente");
        for(int i=0; i<nodes.count(); ++i)
        {
            QDomElement el = nodes.at(i).toElement();
            QDomNode nodo = el.firstChild();
            QString tipo,user, psw, nome, cognome,email, comp, titoli, punti, risposte;
            while (!nodo.isNull()) {
                QDomElement elemento = nodo.toElement();
                QString tagName = elemento.tagName();
                if(tagName=="tipoutente")
                {
                    tipo=elemento.text();
                }
                if(tagName=="username")
                {
                    user=elemento.text();
                }
                if(tagName=="password")
                {
                    psw=elemento.text();
                }
                if(tagName=="nome")
                {
                    nome=elemento.text();
                }
                if(tagName=="cognome")
                {
                    cognome=elemento.text();
                }
                if(tagName=="email")
                {
                    email=elemento.text();
                }
                if(tagName=="competenze")
                {
                    comp=elemento.text();
                }
                if(tagName=="titoli_di_studio")
                {
                    titoli=elemento.text();
                }
                if(tagName=="punti")
                {
                    punti=elemento.text();
                }
                if(tagName=="risposte_date")
                {
                    risposte=elemento.text();
                }
                nodo=nodo.nextSibling();
            }
            Utente* utente;
            unsigned short int punt=std::stoi(punti.toStdString());
            unsigned short int risp=std::stoi(risposte.toStdString());
            if(tipo=="Basic")
                utente=new Basic(user.toStdString(),psw.toStdString(),nome.toStdString(),
                                 cognome.toStdString(),email.toStdString(),punt,risp);

            if(tipo=="Gold")
                utente=new Gold(user.toStdString(),psw.toStdString(),nome.toStdString(),
                                 cognome.toStdString(),email.toStdString(),punt,risp);
            if(tipo=="Premium")
                utente=new Premium(user.toStdString(),psw.toStdString(),nome.toStdString(),
                                 cognome.toStdString(),email.toStdString(),punt,risp);

            if(comp.size()!=0)
               utente->carica_competenze(comp.toStdString());
            if(titoli.size()!=0)
               utente->carica_titoli(titoli.toStdString());
            aggiungi_utente(utente);
        }
        file->close();
    }
    importa_amici_utenti();
}




//void Database::importa_amici_utenti()
//{
//    QFile file("../database_domande_e_amici.xml");
//    try
//    {
//        if (file.open(QFile::ReadOnly | QFile::Text))
//        {
//            QXmlStreamReader xmlInput(&file);
//            if (xmlInput.readNextStartElement())
//            {
//                if(xmlInput.name() == "domande_e_amici")
//                {
//                    if(xmlInput.readNextStartElement())
//                    {
//                        string username,amici;
//                        container<Domanda*> domande;
//                        while (xmlInput.readNextStartElement())
//                        {
//                            xmlInput.readNextStartElement();
//                            if (xmlInput.name() != QString::fromStdString("username"))
//                                throw new std::runtime_error("errore durante il parsing del documento");
//                            username=xmlInput.readElementText().toStdString();

//                            xmlInput.readNextStartElement();
//                            if (xmlInput.name() != QString::fromStdString("amici"))
//                                throw new std::runtime_error("errore durante il parsing del documento");
//                            if(!(xmlInput.readElementText().isEmpty()))
//                                amici=xmlInput.readElementText().toStdString();
//                            get_utente(username)->carica_amici(amici,*this);
//                            xmlInput.skipCurrentElement();
//                            //                        xmlInput.readNextStartElement();
//                            //                        while(xmlInput.name() == "domanda")
//                            //                        {

//                            //                        }

//                        }
//                    }
//                    else
//                        throw new std::runtime_error("errore durante il parsing del documento");

//                }
//                else
//                    throw new std::runtime_error("errore durante il parsing del documento");
//            }
////            else
////                throw new std::runtime_error("errore durante il parsing del documento");
//        }
//        else
//            throw new std::runtime_error("errore durante il parsing del documento");
//    }catch(std::runtime_error r)
//    {
//        std::cerr<<r.what();
//    }
//}




void Database::importa_amici_utenti()
{
    /********import domande e amici********/
    QFile* file=new QFile("../database_domande_e_amici.xml");
    if (!file->open(QFile::ReadOnly | QFile::Text))
    {
        throw std::runtime_error("errore nell'apertura del file");
    }
    else
    {
        QDomDocument documento;
        if(!documento.setContent(file)){
            file->close();
            return;
        }
        QDomElement root = documento.documentElement();//salvo la radice del file
        QDomNodeList nodi_utenti = root.elementsByTagName("utente");
        for(int i=0; i<nodi_utenti.count(); ++i)
        {
            QDomElement el = nodi_utenti.at(i).toElement();
            QDomNode nodo = el.firstChild();
            QString user,amici;
            container<Domanda*> domande_utente;
            while (!nodo.isNull()) {
                QDomElement elemento = nodo.toElement();
                QString tagName = elemento.tagName();
                if(tagName=="amici")
                {
                    amici=elemento.text();
                }
                if(tagName=="username")
                {
                    user=elemento.text();
                }
                if(tagName=="domanda")
                {
                    QDomNode domande=elemento.firstChild();//elementi della domanda
                    QString testo_domanda,priorita;
                    container<Commento> commenti_totali;
                    while(!domande.isNull())
                    {
                        QDomElement elemento_domande = domande.toElement();
                        QString tagNameDomande = elemento_domande.tagName();
                        if(tagNameDomande=="priorita")
                        {
                            priorita=elemento_domande.text();
                        }
                        if(tagNameDomande=="testo")
                        {
                            testo_domanda=elemento_domande.text();
                        }
                        if(tagNameDomande=="commenti")
                        {
                            QDomElement commenti=elemento_domande.toElement();
                            QDomNodeList lista_commenti =commenti.elementsByTagName("commento");
                            for(int x=0; x<lista_commenti.count(); ++x)
                            {
//                                    QDomElement commento=elemento_domande.firstChild(); //che è comento
                                QDomElement commento= lista_commenti.at(x).toElement();
                                QString testo_commento, autore_commento;
                                QDomNode elementi_del_commento=commento.firstChild();
                                while (!elementi_del_commento.isNull())
                                {
                                    QDomElement elemento_commento=elementi_del_commento.toElement(); //che è comento
                                    QString tagNameCommento = elemento_commento.tagName();
                                    if(tagNameCommento=="testo")
                                    {
                                        testo_commento=elemento_commento.text();
                                    }
                                    if(tagNameCommento=="autore_commento")
                                    {
                                        autore_commento=elemento_commento.text();
                                    }
                                    elementi_del_commento=elementi_del_commento.nextSibling();
                               }
                                commenti_totali.push_back(Commento(testo_commento.toStdString(),get_utente(autore_commento.toStdString())));
                        }
                    }
                        domande=domande.nextSibling();
                }
                    Domanda* domanda=0;
                    domanda=new Domanda(testo_domanda.toStdString(),get_utente(user.toStdString())
                                                 ,std::stoi(priorita.toStdString()));
                    domanda->set_commenti(commenti_totali);
                    domande_utente.push_back(domanda);
            }//fine singolo utente
                nodo=nodo.nextSibling();
            }
            Utente* utente;
            utente=get_utente(user.toStdString());
            aggiungi_amici_ad_utente(amici.toStdString(),user.toStdString());
            utente->set_domande(domande_utente);
        }//fine ciclo for
        file->close();
    }
}

void Database::aggiungi_amici_ad_utente(const string& amici, const string& user)
{
    container<string> a=Utente::split(amici," ");
    Utente* utente=get_utente(user);
    for(auto it=a.begin();it!=a.end();++it)
    {
        utente->aggiungi_amico(get_utente(*it));
    }
}

//void Database::importa_amici()
//{
//    QFile* file=new QFile("../database_domande_e_amici.xml");
//    if (!file->open(QFile::ReadOnly | QFile::Text))
//    {
//        throw std::runtime_error("errore nell'apertura del file");
//    }
//    else
//    {
//        QDomDocument documento;
//        if(!documento.setContent(file)){
//            file->close();
//            return;
//        }
//        QDomElement root = documento.documentElement();//salvo la radice del file
//        QDomNodeList nodi_utenti = root.elementsByTagName("utente");
//        for(int i=0; i<nodi_utenti.count(); ++i)
//        {
//            QDomElement el = nodi_utenti.at(i).toElement();
//            QDomNode nodo = el.firstChild();
//            QString user,amici;
////            container<Domanda*> domande_utente;
//            while (!nodo.isNull())
//            {
//                QDomElement elemento = nodo.toElement();
//                QString tagName = elemento.tagName();
//                if(tagName=="username")
//                    user=elemento.text();
//                if(tagName=="amici")
//                    amici=elemento.text();
//                nodo=nodo.nextSibling();
//            }
//            aggiungi_amici_ad_utente(amici.toStdString(), user.toStdString());
//        }
//    }
//    file->close();
//}


