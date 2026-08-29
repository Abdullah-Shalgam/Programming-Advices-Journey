#pragma once

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class clsMyString
{
private:
    stack<string> _UndoStack;
    stack<string> _RedoStack;
    string _Value;

public:
    clsMyString() {}

    clsMyString(const string &Value)
    {
        SetValue(Value);
    }

    void SetValue(const string &Value)
    {
        while (!_RedoStack.empty())
        {
            _RedoStack.pop();
        }

        _UndoStack.push(_Value);
        _Value = Value;
    }

    string GetValue()
    {
        return _Value;
    }

    bool Undo()
    {
        if (!_UndoStack.empty())
        {
            _RedoStack.push(_Value);
            _Value = _UndoStack.top();
            _UndoStack.pop();
            return true;
        }
        return false;
    }

    bool Redo()
    {
        if (!_RedoStack.empty())
        {
            _UndoStack.push(_Value);
            _Value = _RedoStack.top();
            _RedoStack.pop();
            return true;
        }
        return false;
    }
};