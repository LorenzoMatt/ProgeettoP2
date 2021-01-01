#include "database.h"
#include "basic.h"
#include "gold.h"
#include "premium.h"
#include "funzioni_globali.h"

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

        for(auto it=utenti.begin();it!=utenti.end() && !trovato;++it)
            if((*it)->get_credenziali().get_username()==username)
            {
                trovato=true;
                return &(**it);
            }
        if(!trovato)
            throw amico_non_presente();
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

void Database::exportdati()
{
    QFile* file = new QFile("../database.xml");

    try
    {
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

            inp->writeStartElement("domande_e_amici");
            for(auto it=utenti.begin();it!=utenti.end();++it)
            {
                inp->writeStartElement("utente");
                inp->writeTextElement("username",QString::fromStdString(((*it)->get_credenziali()).get_username()));
//                inp->writeStartElement(QString::fromStdString(((*it)->get_credenziali()).get_username()));
                inp->writeTextElement("amici",QString::fromStdString((*it)->get_username_amici()));

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
                        inp->writeTextElement("utente",QString::fromStdString((*c).get_autore()->get_credenziali().get_username()));
                        inp->writeEndElement();// fine commento
                    }

                    inp->writeEndElement();//fine commenti
                    inp->writeEndElement();//fine domanda

                }
                inp->writeEndElement();// fine utente
            }
            inp->writeEndElement();// fine domande_amici

            inp->writeEndDocument();
            file->close();
        }
    }
    catch(std::runtime_error& r)
    {
           cout << r.what() << "\n";
    }

}

void Database::importdati()
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

                Utente* utente=0;
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
}


////////////////
//void DB::load()
//{
//    QFile* file = new QFile("../database.xml");
//        if(file->exists()){
//            if(!file->open(QFile::ReadOnly | QFile::Text)){
//                QMessageBox err;
//                err.setText("Errore nell'apertura del file");
//                err.exec();
//            }
//            else{
//                /*
//                  The QDomDocument class represents an XML document.
//                  The QDomDocument class represents the entire XML document.
//                  Conceptually, it is the root of the document tree, and provides the
//                  primary access to the document's data.
//                */
//                QDomDocument doc;
//                /*
//                  This is an overloaded function.
//                  This function reads the XML document from the IO device dev,
//                  returning true if the content was successfully parsed; otherwise returns false.
//                */
//                if(!doc.setContent(file)){
//                    return;
//                }
//                //The QDomElement class represents one element in the DOM tree.
//                QDomElement docElem = doc.documentElement();
//                /*
//                  The QDomNodeList class is a list of QDomNode objects.
//                  Lists can be obtained by QDomDocument::elementsByTagName() and QDomNode::childNodes().
//                  The Document Object Model (DOM) requires these lists to be "live": whenever you change
//                  the underlying document, the contents of the list will get updated.
//                */
//                QDomNodeList nodes = docElem.elementsByTagName("utente");
//                for(int i=0; i<nodes.count(); ++i)
//                {
//                    QDomElement el = nodes.at(i).toElement();
//                    QDomNode nodo = el.firstChild();
//                    QString n, c, u, e, esp, comp, l, tit, tu, cont;
//                    while (!nodo.isNull()) {
//                        QDomElement elemento = nodo.toElement();
//                        QString tagName = elemento.tagName();

//                        if(tagName=="nome")
//                        {
//                            n=elemento.text();
//                        }
//                        if(tagName=="cognome")
//                        {
//                            c=elemento.text();
//                        }
//                        if(tagName=="username")
//                        {
//                            u=elemento.text();
//                        }
//                        if(tagName=="email")
//                        {
//                            e=elemento.text();
//                        }
//                        if(tagName=="tipoutente")
//                        {
//                            tu=elemento.text();
//                        }
//                        if(tagName=="esperienze")
//                        {
//                            esp=elemento.text();
//                        }
//                        if(tagName=="competenze")
//                        {
//                            comp=elemento.text();
//                        }
//                        if(tagName=="lingue")
//                        {
//                            l=elemento.text();
//                        }
//                        if(tagName=="titolistudio")
//                        {
//                            tit=elemento.text();
//                        }
//                        if(tagName=="contatti")
//                        {
//                            cont=elemento.text();
//                        }
//                        nodo=nodo.nextSibling();
//                    }
//                    Utente* ut = 0;
//                    if(tu == "Utente Basic")
//                    {
//                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
//                        Username us(u.toStdString());
//                        ut=new UtenteBasic(prof, us);

//                        if(esp.size()!=0)
//                           ut->loadEsperienze(esp.toStdString());
//                        if(comp.size()!=0)
//                           ut->loadCompetenze(comp.toStdString());
//                        if(l.size()!=0)
//                           ut->loadLingue(l.toStdString());
//                        if(tit.size()!=0)
//                           ut->loadTitoliStudio(tit.toStdString());
//                        if(cont.size()!=0)
//                           ut->loadContatti(cont.toStdString());
//                    }
//                    if( tu == "Utente Business")
//                    {
//                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
//                        Username us(u.toStdString());
//                        ut=new UtenteBusiness(prof, us);

//                        if(esp.size()!=0)
//                           ut->loadEsperienze(esp.toStdString());
//                        if(comp.size()!=0)
//                           ut->loadCompetenze(comp.toStdString());
//                        if(l.size()!=0)
//                           ut->loadLingue(l.toStdString());
//                        if(tit.size()!=0)
//                           ut->loadTitoliStudio(tit.toStdString());
//                        if(cont.size()!=0)
//                           ut->loadContatti(cont.toStdString());
//                    }
//                    if( tu == "Utente Executive")
//                    {
//                        Profilo prof(n.toStdString(), c.toStdString(), e.toStdString());
//                        Username us(u.toStdString());
//                        ut=new UtenteExecutive(prof, us);

//                        if(esp.size()!=0)
//                           ut->loadEsperienze(esp.toStdString());
//                        if(comp.size()!=0)
//                           ut->loadCompetenze(comp.toStdString());
//                        if(l.size()!=0)
//                           ut->loadLingue(l.toStdString());
//                        if(tit.size()!=0)
//                           ut->loadTitoliStudio(tit.toStdString());
//                        if(cont.size()!=0)
//                           ut->loadContatti(cont.toStdString());
//                    }

//                    db.push_back(ut);
//                }
//                file->close();
//            }
//      }
//}

//void  DB::load(){

//    QString filename("../DB.xml");
//    QFile file(filename);
//    if (!file.open(QFile::ReadOnly | QFile::Text))
//     std::cerr << "Error: Cannot read file " << qPrintable(filename)<< ": " << qPrintable(file.errorString())<< std::endl;

//    QDomDocument doc;
//    if(!doc.setContent(&file))
//        return;
//    //salvo la radice del documento
//    QDomElement docElem = doc.documentElement();
//    // creo una lista dei nodi utenti identificati dal tag "user"
//    QDomNodeList nodes = docElem.elementsByTagName("Utente");
//    // scorro la lista nodo per nodo
//    for(int i=0; i<nodes.count(); ++i){

//        //salvo l'elemento contenuto nel nodo, in posizione i, in un oggetto xml
//        QDomElement el = nodes.at(i).toElement();
//        // mi sposto sul primo figlio
//        QDomNode nodo = el.firstChild();
//        // creo le variabili per l'oggetto user
//        QString n, s, un, pw, l,lc,fs,ep, d, t;
//        // scorro tutti i tag del nodo e li salvo nelle rispettive variabili
//        vector<Username> contacts;
//        while (!nodo.isNull()) {
//            QDomElement elemento = nodo.toElement();
//            QString tagName = elemento.tagName();
//            if(tagName=="Nome"){
//                n=elemento.text();
//            }
//            if(tagName=="Cognome"){
//                s=elemento.text();
//            }
//            if(tagName=="Username"){
//                un=elemento.text();
//            }
//            if(tagName=="Password"){
//                pw=elemento.text();
//            }
//            if(tagName=="Data_di_Nascita"){
//                d=elemento.text();
//            }
//            if(tagName=="Luogo_di_Nascita"){
//                l=elemento.text();
//            }
//            if(tagName=="Lingue_conosciute"){
//                lc=elemento.text();
//            }
//            if(tagName=="Formazione_Scolastica"){
//                fs=elemento.text();
//            }
//            if(tagName=="Esperienze_Professionali"){
//                ep=elemento.text();
//            }
//            if(tagName=="Tipo_di_Utente"){
//                t=elemento.text();
//            }
//            if(tagName=="Rete_Contatti"){
//               {QDomNode nodocontact = elemento.firstChild();
//                  while (!nodocontact.isNull())
//                  {QDomElement el = nodocontact.toElement();
//                   contacts.push_back(Username(el.text().toStdString()));
//                   nodocontact=nodocontact.nextSibling();}
//               }
//            }
//             //mi sposto sul tag successivo
//            nodo=nodo.nextSibling();
//        }
//        Utente* u;
//        Info in(n.toStdString(),s.toStdString(),d.toStdString(),l.toStdString(),lc.toStdString(),fs.toStdString(),ep.toStdString());
//        if (t=="Utente Basic")
//         u=new UtenteBasic(Username(un.toStdString(),pw.toStdString()),in);
//       if (t=="Utente Business")
//         u=new UtenteBusiness(Username(un.toStdString(),pw.toStdString()),in);
//       if (t=="Utente Executive")
//         u=new UtenteExecutive(Username(un.toStdString(),pw.toStdString()),in);
//       u->getRete()->setvector(contacts);

//       db.push_back(u);
//    }
//    file.close();

//}

