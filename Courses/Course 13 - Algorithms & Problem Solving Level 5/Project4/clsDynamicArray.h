#pragma once
#include <iostream>
#include <utility>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:
    T *_TempArray = nullptr;
    T *_OriginalArray = nullptr;
    int _Size = 0;

public:
    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;
        _Size = Size;

        if (_Size > 0)
            _OriginalArray = new T[_Size];
        else
            _OriginalArray = nullptr;
    }

    ~clsDynamicArray()
    {
        if (_OriginalArray != nullptr)
        {
            delete[] _OriginalArray;
            _OriginalArray = nullptr;
        }
    }

    bool SetItem(int index, T value)
    {
        if (index < 0 || index >= _Size)
            return false;

        _OriginalArray[index] = value;
        return true;
    }

    bool InsertAt(int index, T value)
    {
        if (index < 0 || index > _Size)
            return false;

        _TempArray = new T[_Size + 1];

        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = _OriginalArray[i];
        }

        _TempArray[index] = value;

        for (int i = index; i < _Size; i++)
        {
            _TempArray[i + 1] = _OriginalArray[i];
        }

        delete[] _OriginalArray;
        _OriginalArray = _TempArray;
        _Size++;
        return true;
    }

    bool InsertAtBeginning(T value)
    {
        return InsertAt(0, value);
    }

    bool InsertAtEnd(T value)
    {
        return InsertAt(_Size, value);
    }

    bool InsertBefore(int index, T value)
    {
        return InsertAt(index - 1, value);
    }

    bool InsertAfter(int index, T value)
    {
        return InsertAt(index + 1, value);
    }

    T GetItem(int index)
    {
        if (index < 0 || index >= _Size)
        {
            return T();
        }
        return _OriginalArray[index];
    }

    int Find(T value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (_OriginalArray[i] == value)
                return i;
        }

        return -1;
    }

    bool IsEmpty()
    {
        return _Size == 0;
    }

    int Size()
    {
        return _Size;
    }

    void Resize(int NewSize)
    {
        if (NewSize == _Size)
            return;

        if (NewSize <= 0)
        {
            Clear();
            return;
        }

        _TempArray = new T[NewSize];

        int Steps = (NewSize > _Size) ? _Size : NewSize;

        for (int i = 0; i < Steps; i++)
        {
            _TempArray[i] = _OriginalArray[i];
        }

        delete[] _OriginalArray;
        _OriginalArray = _TempArray;
        _Size = NewSize;
    }

    bool DeleteItemAt(int index)
    {
        if (index < 0 || index >= _Size)
            return false;

        if (_Size == 1)
        {
            Clear();
            return true;
        }

        _TempArray = new T[_Size - 1];

        for (int i = 0; i < index; i++)
        {
            _TempArray[i] = _OriginalArray[i];
        }

        for (int i = index + 1; i < _Size; i++)
        {
            _TempArray[i - 1] = _OriginalArray[i];
        }

        delete[] _OriginalArray;
        _OriginalArray = _TempArray;
        _Size--;
        return true;
    }

    bool DeleteItem(T value)
    {
        int index = Find(value);

        if (index == -1)
            return false;

        return DeleteItemAt(index);
    }

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);
    }

    bool DeleteLastItem()
    {
        return DeleteItemAt(_Size - 1);
    }

    void Reverse()
    {
        for (int i = 0; i < _Size / 2; i++)
        {
            swap(_OriginalArray[i], _OriginalArray[_Size - 1 - i]);
        }
    }

    void Clear()
    {
        if (_OriginalArray != nullptr)
        {
            delete[] _OriginalArray;
            _OriginalArray = nullptr;
        }
        _Size = 0;
    }

    void PrintList()
    {
        for (int i = 0; i < _Size; i++)
        {
            cout << _OriginalArray[i] << " ";
        }
        cout << "\n";
    }
};