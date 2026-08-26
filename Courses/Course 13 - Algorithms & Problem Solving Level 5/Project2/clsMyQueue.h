#pragma once

#include <iostream>
#include "../Project1/clsDblLinkedList.h"

using namespace std;

template <class T>
class clsMyQueue
{
protected:
    clsDblLinkedList<T> _MyList;

public:
    void push(T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    int Size()
    {
        return _MyList.Size();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T front()
    {
        if (IsEmpty())
            throw out_of_range("Queue is Empty!");

        return _MyList.GetItem(0);
    }

    T back()
    {
        if (IsEmpty())
            throw out_of_range("Queue is Empty!");

        return _MyList.GetItem(Size() - 1);
    }

    void InsertAtFront(T value)
    {
        _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void InsertAfter(int index, T value)
    {
        _MyList.InsertAfter(index, value);
    }

    T GetItem(int index)
    {
        return _MyList.GetItem(index);
    }

    bool UpdateItem(int index, T NewValue)
    {
        return _MyList.UpdateItem(index, NewValue);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    void Clear()
    {
        _MyList.Clear();
    }

    void Print()
    {
        _MyList.PrintList();
    }
};