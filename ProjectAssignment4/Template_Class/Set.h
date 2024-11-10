//
// Created by Jordan Daudu on 21/08/2024.
//

#ifndef S_2_PROJECTASSIGNMENT4_2_SET_H
#define S_2_PROJECTASSIGNMENT4_2_SET_H
#include <iostream>
using namespace std;

template <class T>
class Set
        {
        private:
            T *arr;
            int size;
        public:
            Set();
            Set(T *arr, int size);
            Set(const Set &s);
            ~Set();
            Set &operator=(const Set &s);
            Set operator+(const Set &s) const;
            Set operator-(const Set &s) const;
            Set operator*(const Set &s) const;
            bool operator==(const Set &s) const;
            bool in(T other) const;
            template<class U>
                friend ostream &operator<<(ostream &os, const Set<U> &s);
        };

template<class T>
Set<T>::Set()
{
    arr = nullptr;
    size = 0;
}

template<class T>
Set<T>::Set(T *arr, int size)
{
    this->size = size;
    this->arr = arr;
}

template<class T>
Set<T>::Set(const Set<T> &s)
{
    size = s.size;
    if(size != 0)
    {
        arr = new T[size];
        for(int i = 0; i < size; i++)
            arr[i] = s.arr[i];
    }
    else
        arr = nullptr;
}

template<class T>
Set<T>::~Set()
{
    delete[] arr;
}
template<class T>
Set<T> &Set<T>::operator=(const Set<T> &s)
{
    if(this != &s)
    {
        delete[] arr;
        size = s.size;
        arr = new T[size];
        for(int i = 0; i < size; i++)
            arr[i] = s.arr[i];
    }
    return *this;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T> &s) const
{
    int p = 0, newSize = size;
    bool found;
    for(int i = 0; i < s.size; i++)
    {
        found = false;
        for(int j = 0; j < size; j++)
        {
            if(s.arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if(!found)
            newSize++;
    }
    T *newArr = new T[newSize];
    for(int i = 0; i < size; i++)
        newArr[p++] = arr[i];
    for(int i = 0; i < s.size; i++)
    {
        found = false;
        for(int j = 0; j < size; j++)
        {
            if(s.arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if(!found)
            newArr[p++] = s.arr[i];
    }
    return Set(newArr, newSize);
}

template<class T>
Set<T> Set<T>::operator-(const Set<T> &s) const
{
    int p = 0, newSize;
    bool found;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < s.size; j++)
            if(arr[i] == s.arr[j])
                p++;
    newSize = size - p;
    T *newArr = new T[newSize];
    p = 0;
    for(int i = 0; i < size; i++)
    {
        found = false;
        for(int j = 0; j < s.size; j++)
            if(arr[i] == s.arr[j])
            {
                found = true;
                break;
            }
        if(!found)
            newArr[p++] = arr[i];
    }
    return Set(newArr, newSize);
}
template<class T>
Set<T> Set<T>::operator*(const Set &s) const
{
    int p = 0, newSize = 0;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < s.size; j++)
            if(arr[i] == s.arr[j])
            {
                newSize++;
                break;
            }
    if(newSize == 0)
        return Set();
    T *newArr = new T[newSize];
    for(int i = 0; i < size; i++)
        for(int j = 0; j < s.size; j++)
            if(arr[i] == s.arr[j])
            {
                newArr[p++] = arr[i];
                break;
            }
    return Set(newArr, newSize);
}
template<class T>
bool Set<T>::operator==(const Set<T> &s) const
{
    if (size != s.size)
        return false;
    for(int i = 0; i < size; i++)
        if(!in(s.arr[i]))
            return false;
    return true;
}
template<class T>
bool Set<T>::in(const T other) const
{
    for(int i = 0; i < size; i++)
        if(arr[i] == other)
            return true;
    return false;
}

template<class T>
ostream &operator<<(ostream &os, const Set<T> &s)
{
    if(s.size == 0)
        return os;
    for(int i = 0; i < s.size-1; i++)
        os << s.arr[i] << " ";
    os << s.arr[s.size-1];
    return os;
}
#endif //S_2_PROJECTASSIGNMENT4_2_SET_H
