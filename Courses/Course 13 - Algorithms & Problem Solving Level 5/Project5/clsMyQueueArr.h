#pragma once

#include <iostream>
#include "../Project4/clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray<T> _MyArray;

public:
    void push(T value)
    {
        _MyArray.InsertAtEnd(value);
    }

    void pop()
    {
        _MyArray.DeleteFirstItem();
    }

    int Size()
    {
        return _MyArray.Size();
    }

    bool IsEmpty()
    {
        return _MyArray.IsEmpty();
    }

    T front()
    {
        if (IsEmpty())
            throw out_of_range("Queue is Empty!");

        return _MyArray.GetItem(0);
    }

    T back()
    {
        if (IsEmpty())
            throw out_of_range("Queue is Empty!");

        return _MyArray.GetItem(Size() - 1);
    }

    void InsertAtFront(T value)
    {
        _MyArray.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyArray.InsertAtEnd(value);
    }

    void InsertAfter(int index, T value)
    {
        _MyArray.InsertAfter(index, value);
    }

    T GetItem(int index)
    {
        return _MyArray.GetItem(index);
    }

    bool UpdateItem(int index, T NewValue)
    {
        return _MyArray.SetItem(index, NewValue);
    }

    void Reverse()
    {
        _MyArray.Reverse();
    }

    void Clear()
    {
        _MyArray.Clear();
    }

    void Print()
    {
        _MyArray.PrintList();
    }
};