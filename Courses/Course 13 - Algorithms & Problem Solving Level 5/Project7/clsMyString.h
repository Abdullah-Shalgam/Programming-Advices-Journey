#pragma once

#include <iostream>
#include <string>
#include "../Project6/clsMyStackArr.h"

using namespace std;

class clsMyString
{
private:
    clsMyStackArr<string> _MyStack;
    clsMyStackArr<string> _RedoStack;

public:
    clsMyString() {}

    clsMyString(const string &Value)
    {
        SetValue(Value);
    }

    void SetValue(const string &Value)
    {
        _MyStack.push(Value);
        _RedoStack.Clear();
    }

    string GetValue()
    {
        if (!_MyStack.IsEmpty())
            return _MyStack.Top();

        return "";
    }

    bool Undo()
    {
        if (_MyStack.IsEmpty())
            return false;

        _RedoStack.push(_MyStack.Top());
        _MyStack.pop();
        return true;
    }

    bool Redo()
    {
        if (_RedoStack.IsEmpty())
            return false;

        _MyStack.push(_RedoStack.Top());
        _RedoStack.pop();
        return true;
    }
};