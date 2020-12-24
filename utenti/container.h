#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <type_traits>
using std::cout;
using std::endl;

//operatore di output
template <class T>
class container;

template <class T>
std::ostream &operator<<(std::ostream &, const container<T> &);

template <class T>
class container
{
    friend std::ostream &operator << <T>(std::ostream &, const container <T> &);
private:
    class nodo
    {
    public:
        T info;
        nodo *prev, *next;
        nodo(const T &t = T(), nodo *p = nullptr, nodo *n = nullptr);
        ~nodo();
    };

    nodo *last, *first; // lista vuota iff first==last==nullptr    per garantire inserimento in testa e coda in tempo costante
    static nodo *copy(nodo *p, nodo *&l);
    static bool is_less(nodo *d1, nodo *d2);

public:
    ~container();
    container(const container &d);
    container(unsigned int k, const T &t);
    container();
    container &operator=(const container &d);
    container operator+(const container &d);
    void push_front(const T &t);
    void push_back(const T &t);
    void insertion_sort(const T &t);
    void pop_front();
    void pop_back();
    bool empty() const;
    unsigned int countElements() const;
    bool operator<(const container &d) const;

    class iterator
    {
        friend class container<T>;
        friend class const_iterator; //per accedere a p e pte

    private:
        nodo *ptr;
        bool pastTheEnd;                     // true iff iterator e' "past-the-end"
        iterator(nodo *p, bool pte = false); // conversione nodo* => iterator

    public:
        iterator();
        T &operator*() const;
        T *operator->() const;
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        bool operator==(const iterator &x) const;
        bool operator!=(const iterator &x) const;
        bool operator <=(const iterator &x) const;
        bool operator >=(const iterator &x) const;
    };
    iterator begin();
    iterator end();
    iterator insert(iterator i, const T &t);
    iterator erase(iterator i);

    class const_iterator
    {
        friend class container<T>;

    private:
        nodo *ptr;
        bool pastTheEnd;                           // true iff constiterator e' "past-the-end"
        const_iterator(nodo *p, bool pte = false); // conversione nodo* => const_iterator

    public:
        const_iterator();
        const_iterator(iterator &i); //conversione iterator->const_iterator
        const T &operator*() const;
        const T *operator->() const;
        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator--();
        const_iterator operator--(int);
        bool operator==(const const_iterator &x) const;
        bool operator!=(const const_iterator &x) const;
        bool operator<=(const const_iterator &x) const;
        bool operator>=(const const_iterator &x) const;
    };
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
};

/*********************************************IMPLEMENTAZIONE************************************************/

/**********************************NODO**********************************/

template <class T>
container<T>::nodo::nodo(const T &t, container<T>::nodo *p, container::nodo *n) : info(t), prev(p), next(n) {}

template <class T>
container<T>::nodo::~nodo() {
    delete next;
    //if(std::is_pointer<T>::value)
        //delete info;
}

/**********************************DLIST**********************************/

template <class T>
typename container<T>::nodo *container<T>::copy(nodo *p, nodo *&l) //si passa last per riferimento perché ancora non si sa quale sia l'ultimo nodo (il primo si)
{
    if (p == nullptr) //lista da copiare vuota
        return l = nullptr;
    nodo *prec = new nodo(p->info, nullptr, nullptr); //lista da copiare ha almeno un nodo
    nodo *succ = prec;                                //da inizializzare qui per l=succ
    nodo *start = prec;
    while (p->next != nullptr) // lista da copiare ha almeno 2 nodi
    {
        succ = new nodo(p->next->info, prec, nullptr);
        prec->next = succ;
        p = p->next;
        prec = prec->next;
    }
    l = succ;
    return start;
}

template <class T>
bool container<T>::is_less(nodo *d1, nodo *d2)
{
    if (d2 == nullptr)
        return false;
    // d2 NON e' vuota
    if (d1 == nullptr)
        return true;
    // d1 e d2 NON vuote
    return d1->info < d2->info ||
           (d1->info == d2->info && is_less(d1->next, d2->next));
}

template <class T>
container<T>::container(const container<T> &d) : first(copy(d.first, last)) // first è ritornato dalla funzione, last viene modificato da copy
{                                                               //grazie all'aliasing
    // first=copy(d.first,last);
}

template <class T>
container<T> &container<T>::operator=(const container<T> &d)
{
    if (this != &d)
    {
        delete first;
        first = copy(d.first, last);
    }
    return *this;
}

template<class T>
container<T> container<T>::operator+(const container<T> &d)
{
    if(d.countElements()==0)
        return container<T>(*this);
    if(this->countElements()==0)
        return container<T>(d);
    container<T> aux;
    aux.first=copy(this->first,aux.last);
    aux.last->next=copy(d.first,aux.last);
    aux.last=d.last;
    return aux;

}


template <class T>
void container<T>::push_front(const T &t)
{
    first = new nodo(t, nullptr, first);
    if (first->next == nullptr)
    {
        // lista di invocazione era vuota
        last = first;
    }
    else
    {
        // lista di invocazione NON era vuota
        (first->next)->prev = first;
    }
}

template <class T>
void container<T>::push_back(const T &t)
{
    last = new nodo(t, last, nullptr);
    if (last->prev == nullptr)
    {
        // lista di invocazione era vuota
        first = last;
    }
    else
    {
        // lista di invocazione NON era vuota
        (last->prev)->next = last;
    }
}

template <class T>
void container<T>::insertion_sort(const T &t)
{
    if(empty() || t<this->last->info)
        push_back(t);
    else
    {
        bool sent=false;
        for(auto it=this->begin();it!=this->end() && !sent;++it)
        {
            if(t>=*it)
            {
                insert(it,t);
                sent=true;
            }
        }
    }
}


template <class T>
void container<T>::pop_front()
{
    if (first) //se la lista ha almeno un elemento
    {
        nodo *temp = first;

        if (first->next) //se la lista ha almeno 2 elementi
        {
            first = first->next;
            temp->next = nullptr;
            first->prev = nullptr;
        }
        else //la lista ha esattamente un elemento
        {
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
bool container<T>::empty() const
{
    return (first==nullptr && last==nullptr);
}

template <class T>
unsigned int container<T>::countElements() const
{
    unsigned int cont=0;
    for (auto i=begin(); i!=end();++i)
        cont++;
    return cont;
}

template <class T>
typename container<T>::iterator container<T>::insert(iterator i, const T &t) //inserisce t prima del nodo puntato da i e ritorna l'iteratore che punta al nuovo nodo
{
    if (i.ptr == nullptr) //la lista è vuota
    {
        push_front(t);
        return begin();
    }
    else //lista non vuota
    {
        if (i == end()) //iteratore past the end
        {
            push_back(t);
            return --end(); //cerca il past the end della lista aggiornata e ne ritorna il precedente (ultimo)
        }
        else if (i == begin()) //iteratore primo elemento
        {
            push_front(t);
            return begin(); //ritorna il primo, avendo inserito t prima del primo (che diventa quindi il primo)
        }
        else //caso generale
        {
            nodo *temp = new nodo(t, i.ptr->prev, i.ptr);
            (i.ptr->prev)->next = temp;
            i.ptr->prev = temp;
            return temp;
        }
    }
}

template <class T>
typename container<T>::iterator container<T>::erase(iterator i) //rimuove il nodo puntato da i iteratore valido, restituisce l'iteratore al nodo successivo
{
    if (i != end())
    {
        if (i == begin())
        {
            ++i;
            pop_front();
        }
        else if (i == --end())
        {
            ++i;
            pop_back();
        }
        else
        {
            nodo * temp = i.ptr; //nodo da eliminare
            ++i;                //iteratore da restituire
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            temp->next = nullptr;
            delete temp;
        }
    }
    return i;
}

template <class T>
container<T>::container(unsigned int k, const T &t) : last(nullptr), first(nullptr)
{
    for (unsigned int i = 0; i < k; ++i)
        push_front(t);
}
template <class T>
container<T>::container() : last(nullptr), first(nullptr) {}

template <class T>
container<T>::~container()
{
    delete first;
}

template <class T>
bool container<T>::operator<(const container<T> &d) const
{
    return is_less(first, d.first);
}

/**********************************CONST_ITERATOR**********************************/

template <class T>
typename container<T>::const_iterator container<T>::begin() const
{
    return first;
}

template <class T>
typename container<T>::const_iterator container<T>::end() const
{
    if (last == nullptr) //dList vuota ritorna 0
        return nullptr;
    return const_iterator(last + 1, true); // dList ha almeno un nodo ritorna iterator pte
}

template <class T>
typename container<T>::const_iterator container<T>::cbegin() const
{
    return first;
}

template <class T>
typename container<T>::const_iterator container<T>::cend() const
{
    if (last == nullptr) //dList vuota ritorna 0
        return nullptr;
    return const_iterator(last + 1, true); // dList ha almeno un nodo ritorna iterator pte
}

template <class T>
container<T>::const_iterator::const_iterator(container<T>::nodo *p, bool pte) : ptr(p), pastTheEnd(pte) {}

template <class T>
container<T>::const_iterator::const_iterator() : ptr(nullptr), pastTheEnd(false) {}

template <class T>
container<T>::const_iterator::const_iterator(iterator &i) : ptr(i.ptr), pastTheEnd(i.pastTheEnd) {}

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
        if (!pastTheEnd)
        {
            if (ptr->next == nullptr)
            {
                ++ptr; //chiamata al ++ prefisso sugli interi: ptr è un indirizzo
                pastTheEnd = true;
            }
            else
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
        if (!pastTheEnd)
        {
            if (ptr->next == nullptr)
            {
                ++ptr; //chiamata al ++ prefisso sugli interi: ptr è un indirizzo
                pastTheEnd = true;
            }
            else
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
        if (pastTheEnd)
        {
            --ptr;
            pastTheEnd = false;
        }
        else
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
      if (pastTheEnd)
      {
          --ptr;
          pastTheEnd = false;
      }
      else
          ptr = ptr->prev;
  }
  return aux;
}
template <class T>
bool container<T>::const_iterator::operator==(const container<T>::const_iterator &x) const
{
    return ptr == x.ptr;
}

template <class T>
bool container<T>::const_iterator::operator!=(const container<T>::const_iterator &x) const
{
    return ptr != x.ptr;
}
template <class T>
bool container<T>::const_iterator::operator<=(const container<T>::const_iterator &x) const
{
    return ptr <= x.ptr;
}
template <class T>
bool container<T>::const_iterator::operator>=(const container<T>::const_iterator &x) const
{
    return ptr >= x.ptr;
}

/**********************************ITERATOR**********************************/

template <class T>
typename container<T>::iterator container<T>::begin()
{
    return first;
}

template <class T>
typename container<T>::iterator container<T>::end()
{
    if (last == nullptr) //dList vuota ritorna 0
        return nullptr;
    return iterator(last + 1, true); // dList ha almeno un nodo ritorna iterator pte
}

template <class T>
container<T>::iterator::iterator(container<T>::nodo *p, bool pte) : ptr(p), pastTheEnd(pte) {}

template <class T>
container<T>::iterator::iterator() : ptr(nullptr), pastTheEnd(false) {}

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
        if (!pastTheEnd)
        {
            if (ptr->next == nullptr)
            {
                ++ptr; //chiamata al ++ prefisso sugli interi: ptr è un indirizzo
                pastTheEnd = true;
            }
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
      if (!pastTheEnd)
      {
          if (ptr->next == nullptr)
          {
              ++ptr; //chiamata al ++ prefisso sugli interi: ptr è un indirizzo
              pastTheEnd = true;
          }
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
        if (pastTheEnd)
        {
            --ptr;
            pastTheEnd = false;
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
      if (pastTheEnd)
      {
          --ptr;
          pastTheEnd = false;
      }
      else
          ptr = ptr->prev;
  }
  return aux;
}

template <class T>
bool container<T>::iterator::operator==(const container<T>::iterator &x) const
{
    return ptr == x.ptr;
}

template <class T>
bool container<T>::iterator::operator!=(const container<T>::iterator &x) const
{
    return ptr != x.ptr;
}
template <class T>
bool container<T>::iterator::operator<=(const container<T>::iterator &x) const
{
    return ptr <= x.ptr;
}

template <class T>
bool container<T>::iterator::operator>=(const container<T>::iterator &x) const
{
    return ptr >= x.ptr;
}


template <class T> //dichiarazione perché è necessario che compaia quando viene dichiarata l'amicizia su trialbero
std::ostream &operator<<(std::ostream &os, const container<T> &l)
{
    for (typename container<T>::const_iterator c = l.cbegin(); c != l.cend(); ++c)
        std::cout << *c << ' ';
    std::cout << std::endl;
    return os;
}


/*
DONE:
- iteratori
- inserimento dato l'iteratore (bug)
- pop front e pop back
- eliminazione ad iteratore
TODO (forse):
    - eliminazione ad iteratore
    - eccezioni all'inserimento e modifica?
    - input e output?
    questi due non presenti in stl::list
*/

#endif // CONTAINER_H
