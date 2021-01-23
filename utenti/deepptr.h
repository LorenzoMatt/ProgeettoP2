#ifndef DEEPPTR_H
#define DEEPPTR_H
template<class T>
class DeepPtr{
private:
    T* oggetto;
public:
    ~DeepPtr();
    DeepPtr(const T* =nullptr);
    DeepPtr(const DeepPtr<T>&);
    DeepPtr<T> &operator =(const DeepPtr<T>&);
    T& operator*() const;
    T* operator->() const;
};

template<class T>
DeepPtr<T>::DeepPtr(const T *t):oggetto(t ? t->clone() : nullptr){}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& t):oggetto(t.oggetto ? (t.oggetto)->clone() : 0){}

template<class T>
DeepPtr<T>::~DeepPtr()
{
    if(oggetto)
        delete oggetto;
}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator =(const DeepPtr<T>& d)
{
    if(this!=&d){
        if(oggetto)
            delete oggetto;
        oggetto=d.oggetto ? (d.oggetto)->clone() : 0;
    }
    return *this;
}

template<class T>
T& DeepPtr<T>::operator*() const
{
    return *oggetto;
}

template<class T>
T* DeepPtr<T>:: operator->() const{
    return oggetto;
}
#endif // DEEPPTR_H
