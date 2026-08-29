#pragma once

#include <iostream>
#include "../Project5/clsMyQueueArr.h"

using namespace std;

template <class T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:
    void push(T value)
    {
        clsMyQueueArr<T>::_MyArray.InsertAtBeginning(value);
    }

    T Top()
    {
        return clsMyQueueArr<T>::front();
    }

    T Bottom()
    {
        return clsMyQueueArr<T>::back();
    }

    void InsertAtTop(T value)
    {
        clsMyQueueArr<T>::InsertAtFront(value);
    }

    void InsertAtBottom(T value)
    {
        clsMyQueueArr<T>::InsertAtBack(value);
    }
};