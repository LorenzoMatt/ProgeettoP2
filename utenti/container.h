#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;

template <class T>
class container;//dichiarazione incompleta


//operatori di output
template <class T>
std::ostream &operator<<(std::ostream &, const container<T> &);
template <class T>
std::ostream &operator<<(std::ostream &, const container<T*> &);

template <class T>
class container
{
private:
    class nodo
    {
    public:
        T info;
        nodo *prev, *next;
        nodo(const T &t = T(), nodo *p = nullptr, nodo *n = nullptr);
        ~nodo();
    };
    nodo *last, *first;
    static nodo *copy(nodo *n, nodo *&l);
public:
    container();
    ~container();//distruttore profondo
    container(const container &c); //copia profonda del container
    container &operator=(const container &c);//assegnazione profonda
    container operator+(const container &c);// somma fra 2 container
    T &operator[](unsigned int i); //non buono in una lista ma presente per comodità di utilizzo
    void push_front(const T &t);
    void push_back(const T &t);
    void insertion_sort(const T &t);// inserisce in modo ordinato dentro alla lista passando un riferimento
    void insertion_sort_pointer(const T *t);// inserisce in modo ordinato dentro alla lista passando un puntatore
    void pop_front();
    void pop_back();
    unsigned int size() const;
    bool empty() const;
    class iterator
    {
        friend class container<T>;
        friend class const_iterator;
    private:
        nodo *ptr;
        bool pTE;// true se è iteratore pastTheEnd
        iterator(nodo *p, bool pte = false); // conversione nodo* => iterator
    public:
        iterator();
        T &operator*() const;
        T *operator->() const;
        iterator &operator++();//operatore di incremento prefisso
        iterator operator++(int);//operatore di incremento postfisso
        iterator &operator--();//operatore di decremento prefisso
        iterator operator--(int);//operatore di decremento postfisso
        bool operator <=(const iterator &i) const;
        bool operator >=(const iterator &i) const;
        bool operator==(const iterator &i) const;
        bool operator!=(const iterator &i) const;
    };
    iterator begin();
    iterator end();
    iterator erase(iterator i);//rimuove il nodo puntato da i e ritorna l'iteratore al nodo successivo
    iterator insert(iterator i, const T &t);//inserisce t prima dell'iteratore puntato da i e ritorna l'iteratore che punta al nuovo nodo creato
    class const_iterator
    {
        friend class container<T>;

    private:
        nodo *ptr;
        bool pTE;// true se è iteratore pastTheEnd
        const_iterator(nodo *p, bool pte = false);

    public:
        const_iterator();
        const_iterator(iterator &i); //conversione da iterator a const_iterator
        const T &operator*() const;
        const T *operator->() const;
        const_iterator &operator++();//operatore di incremento prefisso
        const_iterator operator++(int);//operatore di incremento postfisso
        const_iterator &operator--();//operatore di decremento prefisso
        const_iterator operator--(int);//operatore di decremento postfisso
        bool operator<=(const const_iterator &i) const;
        bool operator>=(const const_iterator &i) const;
        bool operator==(const const_iterator &i) const;
        bool operator!=(const const_iterator &i) const;
    };
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
};

/**************OUTPUT**************/
template <class T>
std::ostream &operator<<(std::ostream &os, const container<T> & c)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        cout << *it << ' ';
    cout <<endl;
    return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const container<T*> &c)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        cout << **it << ' ';
    cout<<endl;
    return os;
}

/**************NODO**************/

template <class T>
container<T>::nodo::nodo(const T &t, container<T>::nodo *p, container<T>::nodo *n) : info(t), prev(p), next(n) {}

template <class T>
container<T>::nodo::~nodo() {
    delete next;
}

/**************CONTAINER**************/

template <class T>
container<T>::container() : last(nullptr), first(nullptr) {}

template <class T>
container<T>::~container()
{
    delete first;
}

template <class T>
typename container<T>::nodo *container<T>::copy(nodo *n, nodo *&l) //da notare che l è passato per riferimento(per poter spostare il last)
{
    if (n == nullptr){
        //lista vuota
        l = nullptr;
        return l;
    }
    //almeno un nodo
    nodo *prec = new nodo(n->info, nullptr, nullptr);
    nodo *succ = prec;
    nodo *start = prec;
    //almeno 2 nodi
    while (n->next != nullptr)
    {
        succ = new nodo(n->next->info, prec, nullptr);
        prec->next = succ;
        n = n->next;
        prec = prec->next;
    }
    l = succ;
    return start;
}

template <class T>
container<T>::container(const container<T> &c) : first(copy(c.first, last)){}

template <class T>
container<T> &container<T>::operator=(const container<T> &c)
{
    if (this != &c)
    {
        delete first;
        first = copy(c.first, last);//copia profonda a partire da first
    }
    return *this;
}

template<class T>
container<T> container<T>::operator+(const container<T> &c)
{
    if(c.size()==0)
        return container<T>(*this);
    if(size()==0)
        return container<T>(c);
    container<T> aux;
    aux.first=copy(first,aux.last);//copiata la prima lista e passato aux.last per incrementare il last
    aux.last->next=copy(c.first,aux.last);
    return aux;
}

template<class T>
T& container<T>::operator[](unsigned int i) //non molto adatto per una lista ma comodo da usare
{
    if(i>size())
        throw std::out_of_range("indice più grande della grandezza della lista");
    container<T>::iterator it=begin();
    for(;it!=end() && i>0;++it,--i)
    {}//corpo vuoto
    return *it;
}

template <class T>
void container<T>::push_front(const T &t)
{
    first = new nodo(t, nullptr, first);
    if (first->next == nullptr)
    { // lista vuota
        last = first;
    }
    else
    {// lista non vuota
        (first->next)->prev = first;
    }
}

template <class T>
void container<T>::push_back(const T &t)
{
    last = new nodo(t, last, nullptr);
    if (last->prev == nullptr)
    {// lista vuota
        first = last;
    }
    else
    {// lista non vuota
        (last->prev)->next = last;
    }
}

template <class T>
void container<T>::insertion_sort(const T &t)
{
    if(empty() || last->info>t)
        push_back(t);
    else
    {// scorro la lista ed inserisco
        bool sent=false;
        for(auto it=begin();it!=end() && !sent;++it)
        {
            if(*it<=t)
            {
                insert(it,t);
                sent=true;
            }
        }
    }
}

template <class T>
void container<T>::insertion_sort_pointer(const T *t)
{
    if(empty() || *(last->info)>**t)
        push_back(*t);
    else
    {// scorro la lista ed inserisco
        bool sent=false;
        for(auto it=begin();it!=end() && !sent;++it)
        {
            if(**it<=**t)
            {
                insert(it,*t);
                sent=true;
            }
        }
    }
}

template <class T>
void container<T>::pop_front()
{
    if (first)// se c'è un nodo di inizio da poter eliminare
    {
        nodo *temp = first;

        if (first->next)
        {//presenti almeno 2 nodi
            first = first->next;
            temp->next = nullptr;
            first->prev = nullptr;
        }
        else
        {//presente un solo nodo
            first = last = nullptr;
        }
        delete temp;
    }
}

template <class T>
void container<T>::pop_back()
{
    if (first)
    {
        nodo *temp = last;
        if (first->next)
        {
            last = last->prev;
            last->next = nullptr;
        }
        else
        {
            first = last = nullptr;
        }
        delete temp;
    }
}

template <class T>
unsigned int container<T>::size() const
{
    unsigned int count=0;
    for (auto i=begin(); i!=end();++i)
        count++;
    return count;
}

template <class T>
bool container<T>::empty() const
{
    return first==nullptr && last==nullptr;//primo ed ultimo nodo non presenti(basterebbe controllare first non presente)
}

/**************ITERATOR**************/

template <class T>
typename container<T>::iterator container<T>::erase(iterator i)
{
    if (i != end())
    {
        if (i == begin())
        {
            ++i;//incremento l'iteratore da ritornare
            pop_front();//elimino in testa
        }
        else if (i == --end()) {//nodo prima del pTE
            nodo* temp = last;
            last = last->prev;
            last->next = nullptr;
            delete temp;
            return end();//pTE=true
        }
        else
        {//inserimento in mezzo alla lista
            nodo * temp = i.ptr;
            ++i;//incremento l'iteratore da ritornare
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            temp->next = nullptr;//isolo il nodo da eliminare
            delete temp;
        }
    }
    return i;
}

template <class T>
typename container<T>::iterator container<T>::insert(iterator i, const T &t)
{
    if ((i.ptr == nullptr) || (i == begin())) //la lista è vuota oppure l'iteratore punta al primo nodo
    {
        push_front(t);//inserisco in testa
        return first;// ritorno l'iteratore al primo nodo(conversione implicita da nodo* ad iterator
    }
    else //lista non vuota
    {
        if (i == end())//iteratore pTE
        {
            push_back(t);
            return --end(); //ritorna l'ultimo nodo(ovvero il nodo che precede il pTE)
        }
        else //inserimento in mezzo alla lista
        {
            nodo *temp = new nodo(t, i.ptr->prev, i.ptr);
            (i.ptr->prev)->next = temp;
            i.ptr->prev = temp;
            return temp;
        }
    }
}
template <class T>
typename container<T>::iterator container<T>::begin()
{
    return first;
}

template <class T>
typename container<T>::iterator container<T>::end()
{
    if (last == nullptr) //lista vuota
        return nullptr;
    return iterator(last + 1, true); // lista ha almeno un nodo ritorna iterator pTE
}

template <class T>
container<T>::iterator::iterator(container<T>::nodo *p, bool pte) : ptr(p), pTE(pte) {}

template <class T>
container<T>::iterator::iterator() : ptr(nullptr), pTE(false) {}

template <class T>
T &container<T>::iterator::operator*() const
{
    return ptr->info;
}

template <class T>
T *container<T>::iterator::operator->() const
{
    return &(ptr->info);
}

template <class T>
typename container<T>::iterator &container<T>::iterator::operator++()
{
    if (ptr != nullptr)
    {
        if (!pTE)
        {
            if (ptr->next == nullptr)
            {//ptr è l'ultimo nodo della lista
                ++ptr;//incremento su un indirizzo di memoria
                pTE = true;
            }//caso generale
            else
            {
                ptr = ptr->next;
            }
        }
    }
    return *this;
}

template <class T>
typename container<T>::iterator container<T>::iterator::operator++(int)
{
  iterator aux=*this;
  if (ptr != nullptr)
  {
      if (!pTE)
      {
          if (ptr->next == nullptr)
          {//ptr è l'ultimo nodo della lista
              ++ptr;//incremento su un indirizzo di memoria
              pTE = true;
          }//caso generale
          else
          {
              ptr = ptr->next;
          }
      }
  }
  return aux;
}

template <class T>
typename container<T>::iterator &container<T>::iterator::operator--()
{
    if (ptr != nullptr)
    {
        if (pTE)
        {
            --ptr;//decremento su un indirizzo di memoria
            pTE = false;
        }
        else
            ptr = ptr->prev;
    }
    return *this;
}
template <class T>
typename container<T>::iterator container<T>::iterator::operator--(int)
{
  iterator aux=*this;
  if (ptr != nullptr)
  {
      if (pTE)
      {
          --ptr;
          pTE = false;
      }
      else
          ptr = ptr->prev;
  }
  return aux;
}

template <class T>
bool container<T>::iterator::operator==(const container<T>::iterator &i) const
{
    return ptr == i.ptr;
}

template <class T>
bool container<T>::iterator::operator!=(const container<T>::iterator &i) const
{
    return ptr != i.ptr;
}
template <class T>
bool container<T>::iterator::operator<=(const container<T>::iterator &i) const
{
    return ptr <= i.ptr;
}

template <class T>
bool container<T>::iterator::operator>=(const container<T>::iterator &i) const
{
    return ptr >= i.ptr;
}

/**************CONST_ITERATOR**************/

template <class T>
typename container<T>::const_iterator container<T>::begin() const
{
    return first;
}

template <class T>
typename container<T>::const_iterator container<T>::end() const
{
    if (last == nullptr) //lista vuota
        return nullptr;
    return const_iterator(last + 1, true); // lista con almeno un nodo
}

template <class T>
typename container<T>::const_iterator container<T>::cbegin() const
{
    return first;
}

template <class T>
typename container<T>::const_iterator container<T>::cend() const
{
    if (last == nullptr) //lista vuota
        return nullptr;
    return const_iterator(last + 1, true); // lista ha almeno un nodo
}

template <class T>
container<T>::const_iterator::const_iterator(container<T>::nodo *p, bool pte) : ptr(p), pTE(pte) {}

template <class T>
container<T>::const_iterator::const_iterator() : ptr(nullptr), pTE(false) {}

template <class T>
container<T>::const_iterator::const_iterator(iterator &i) : ptr(i.ptr), pTE(i.pTE) {}

template <class T>
const T &container<T>::const_iterator::operator*() const
{
    return ptr->info;
}

template <class T>
const T *container<T>::const_iterator::operator->() const
{
    return &(ptr->info);
}


template <class T>
typename container<T>::const_iterator &container<T>::const_iterator::operator++()
{
    if (ptr != nullptr)
    {
        if (!pTE)
        {
            if (ptr->next == nullptr)//ptr è l'ultimo nodo della lista
            {
                ++ptr;
                pTE = true;
            }
            else//caso generale
            {
                ptr = ptr->next;
            }
        }
    }
    return *this;
}

template <class T>
typename container<T>::const_iterator container<T>::const_iterator::operator++(int)
{
    iterator aux=*this;
    if (ptr != nullptr)
    {
        if (!pTE)
        {
            if (ptr->next == nullptr)//ptr è l'ultimo nodo della lista
            {
                ++ptr;
                pTE = true;
            }
            else//caso generale
            {
                ptr = ptr->next;
            }
        }
    }
    return aux;
}

template <class T>
typename container<T>::const_iterator &container<T>::const_iterator::operator--()
{
    if (ptr != nullptr)
    {
        if (pTE)//ptr è l'ultimo nodo della lista
        {
            --ptr;
            pTE = false;
        }
        else//caso generale
            ptr = ptr->prev;
    }
    return *this;
}

template <class T>
typename container<T>::const_iterator container<T>::const_iterator::operator--(int)
{
  iterator aux=*this;
  if (ptr != nullptr)
  {
      if (pTE)//ptr è l'ultimo nodo della lista
      {
          --ptr;
          pTE = false;
      }
      else//caso generale
          ptr = ptr->prev;
  }
  return aux;
}
template <class T>
bool container<T>::const_iterator::operator==(const container<T>::const_iterator &i) const
{
    return ptr == i.ptr;
}

template <class T>
bool container<T>::const_iterator::operator!=(const container<T>::const_iterator &i) const
{
    return ptr != i.ptr;
}
template <class T>
bool container<T>::const_iterator::operator<=(const container<T>::const_iterator &i) const
{
    return ptr <= i.ptr;
}
template <class T>
bool container<T>::const_iterator::operator>=(const container<T>::const_iterator &i) const
{
    return ptr >= i.ptr;
}

#endif // CONTAINER_H
