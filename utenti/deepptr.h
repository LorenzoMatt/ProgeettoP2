
//template<class T>
#ifndef DEEP_PTR_H
#define DEEP_PTR_H

#include <iostream>
template<class T>
class DeepPtr
{
    T* m_ptr;
public:
    DeepPtr(T* ptr = nullptr) : m_ptr(ptr){}
    ~DeepPtr()
    {
        delete m_ptr;
    }
    // Copy constructor
    DeepPtr(const DeepPtr& a) = delete;
    // Move constructor
    DeepPtr(DeepPtr&& a) : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
    }
    // Copy assignment
    DeepPtr& operator=(const DeepPtr& a) = delete;
    // Move assignment
    DeepPtr& operator=(DeepPtr&& a)
    {
        if (&a == this)
            return *this;
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
#endif // DEEP_PTR_H
