#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
};

void InsertAtBeginning(Node *&head, int value)
{

    /*
        1-Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.
    */

    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void InsertAtEnd(Node *&head, int Value)
{
    Node *new_node = new Node();
    new_node->value = Value;
    new_node->next = NULL;

    if (head == NULL)
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    new_node->prev = current;
    current->next = new_node;
}

void InsertAfter(Node *prev_node, int Value)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return;
    }

    Node *new_node = new Node();
    new_node->next = prev_node->next;
    new_node->value = Value;
    new_node->prev = prev_node;

    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;

    prev_node->next = new_node;
}

Node *Find(Node *head, int Value)
{
    while (head != NULL)
    {
        if (head->value == Value)
            return head;
        else
            head = head->next;
    }

    return NULL;
}

void PrintNodeDetails(Node *head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";
}

// Print the linked list
void PrintListDetails(Node *head)

{
    cout << "\n\n";
    while (head != NULL)
    {
        PrintNodeDetails(head);
        head = head->next;
    }
}

// Print the linked list
void PrintList(Node *head)

{
    cout << "NULL <--> ";
    while (head != NULL)
    {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    Node *head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);

    cout << "\n\n";
    InsertAfter(Find(head, 3), 7);
    PrintList(head);

    cout << "\n\n";
    InsertAtEnd(head, 500);
    PrintList(head);

    return 0;
}