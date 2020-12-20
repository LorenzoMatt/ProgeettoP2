#ifndef PUNTATORESMART_H
#define PUNTATORESMART_H
template<class T>
class DeepPtr{
private:
    T* oggetto;
public:
    DeepPtr();
    virtual ~DeepPtr();
    DeepPtr(T*);
    DeepPtr(const DeepPtr<T>&);
    DeepPtr<T> &operator =(const DeepPtr<T>&);
    T& operator*() const;
    T* operator->() const;
};

template<class T>
DeepPtr<T>::DeepPtr():oggetto(nullptr){}

template<class T>
DeepPtr<T>::DeepPtr(T* t):oggetto(t){}

template<class T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& t):oggetto(new T(*t)){}

template<class T>
DeepPtr<T>::~DeepPtr()
{delete oggetto;}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator =(const DeepPtr<T>& d)
{
    if(this!=&d){
        delete oggetto;
        oggetto=new T(d.oggetto);
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
#endif // PUNTATORESMART_H
