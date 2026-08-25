#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList
{
public:
    class Node
    {
    public:
        T value;
        Node *next;
        Node *prev;
    };

protected:
    Node *_head = NULL;
    Node *_tail = NULL;
    int _Size = 0;

public:
    void InsertAtBeginning(T value)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = _head;
        newNode->prev = NULL;

        if (_head != NULL)
        {
            _head->prev = newNode;
        }

        else
        {
            _tail = newNode;
        }

        _head = newNode;
        _Size++;
    }

    void InsertAtEnd(T value)
    {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = _tail;

        if (_head == NULL)
        {
            _head = new_node;
            _tail = new_node;
        }

        else
        {
            _tail->next = new_node;
            _tail = new_node;
        }

        _Size++;
    }

    void InsertAfter(Node *prev_node, T value)
    {
        if (prev_node == NULL)
            return;

        Node *new_node = new Node();
        new_node->next = prev_node->next;
        new_node->value = value;
        new_node->prev = prev_node;

        if (prev_node->next != NULL)
            prev_node->next->prev = new_node;

        prev_node->next = new_node;

        if (prev_node == _tail)
            _tail = new_node;

        _Size++;
    }

    bool InsertAfter(int index, T value)
    {
        Node *ItemNode = GetNode(index);

        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }

        return false;
    }

    void DeleteFirstNode()
    {
        if (_head == NULL)
            return;

        Node *Temp = _head;
        _head = _head->next;

        if (_head != NULL)
        {
            _head->prev = NULL;
        }

        else
        {
            _tail = NULL;
        }

        delete Temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        if (_head == NULL)
            return;

        Node *Temp = _tail;

        if (_head == _tail)
        {
            _head = NULL;
            _tail = NULL;
        }

        else
        {
            _tail = _tail->prev;
            _tail->next = NULL;
        }

        delete Temp;
        _Size--;
    }

    void DeleteNode(Node *&NodeToDelete)
    {
        if (_head == NULL || NodeToDelete == NULL)
            return;

        if (_tail == NodeToDelete)
            _tail = NodeToDelete->prev;

        if (_head == NodeToDelete)
            _head = NodeToDelete->next;

        if (NodeToDelete->prev != NULL)
            NodeToDelete->prev->next = NodeToDelete->next;

        if (NodeToDelete->next != NULL)
            NodeToDelete->next->prev = NodeToDelete->prev;

        delete NodeToDelete;
        NodeToDelete = NULL;
        _Size--;
    }

    Node *Find(T value)
    {
        Node *current = _head;

        while (current != NULL)
        {
            if (current->value == value)
                return current;
            else
                current = current->next;
        }

        return NULL;
    }

    int Size() { return _Size; }

    bool IsEmpty() { return _Size == 0; }

    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node *current = _head;
        Node *Temp = NULL;

        while (current != NULL)
        {
            Temp = current->prev;
            current->prev = current->next;
            current->next = Temp;
            current = current->prev;
        }

        Temp = _tail;
        _tail = _head;
        _head = Temp;
    }

    Node *GetNode(int index)
    {
        if (index < 0 || index >= _Size)
            return NULL;

        Node *current = NULL;

        if (index > _Size / 2)
        {
            current = _tail;
            index = _Size - index - 1;

            for (int i = 0; i < index; i++)
            {
                current = current->prev;
            }
        }

        else
        {
            current = _head;

            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
        }

        return current;
    }

    T GetItem(int index)
    {
        Node *ItemNode = GetNode(index);

        if (ItemNode == NULL)
            throw out_of_range("Index out of range!");

        return ItemNode->value;
    }

    bool UpdateItem(int index, T NewValue)
    {
        Node *ItemNode = GetNode(index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }

        return false;
    }

    void PrintList()
    {
        Node *current = _head;

        while (current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
};