#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node *next;
};

void InsertAtBeginning(Node *&head, int value)
{
    // Allocate memory to a node
    Node *new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;
}

Node *Find(Node *head, int Value)
{

    while (head != NULL)
    {

        if (head->value == Value)
            return head;

        head = head->next;
    }

    return NULL;
}

// Insert a node after a node
void InsertAfter(Node *prev_node, int Value)
{

    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->value = Value;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void InsertAtEnd(Node *&head, int Value)
{
    Node *new_node = new Node();
    new_node->value = Value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    else
    {
        Node *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }
}

void DeleteNode(Node *&head, int Value)
{
    Node *Current = head, *Prev = head;

    if (head == NULL)
    {
        return;
    }

    if (Current->value == Value)
    {
        head = Current->next;
        delete Current; // free from memory
        return;
    }

    // Find the key to be deleted
    while (Current != NULL && Current->value != Value)
    {
        Prev = Current;
        Current = Current->next;
    }

    // If the value is not present
    if (Current == NULL)
        return;

    // Remove the node
    Prev->next = Current->next;
    delete Current; // free from memory
}

void DeleteFirstNode(Node *&head)
{
    if (head == NULL)
        return;

    Node *current = head;
    head = current->next;
    delete current;
}

void DeleteLastNode(Node *&head)
{
    Node *current = head, *Prev = head;

    if (head == NULL)
        return;

    if (current->next == NULL)
    {
        head = NULL;
        delete current;
        return;
    }

    while (current != NULL && current->next != NULL)
    {
        Prev = current;
        current = current->next;
    }

    Prev->next = NULL;
    delete current;
}

// Print the linked list
void PrintList(Node *head)

{
    cout << "\n";
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    PrintList(head);
    Node *N1 = NULL;

    N1 = Find(head, 2);

    InsertAfter(N1, 500);

    PrintList(head);

    N1 = Find(head, 500);
    InsertAfter(N1, 600);
    PrintList(head);

    InsertAtEnd(head, 300);
    PrintList(head);

    DeleteNode(head, 3);
    PrintList(head);

    DeleteFirstNode(head);
    PrintList(head);

    DeleteLastNode(head);
    PrintList(head);

    return 0;
}