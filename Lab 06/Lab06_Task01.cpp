#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        next = NULL;
        prev = NULL;
        data = value;
    }
};

void InsertAtTail(Node *&head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void InsertAtHead(Node *&head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}
void DeleteNodeAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}


void InsertPosition(Node *&head, int value, int pos)
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }
    if (pos == head->data)
    {
        InsertAtHead(head, value);
    }
    Node *temp = head;
    while (temp->data != pos)
    {
        temp = temp->next;
    }
    Node *n = new Node(value);

    if (temp->next != NULL)
    {
        Node *pointer = temp->next;
        n->prev = temp;
        temp->next = n;
        n->next = pointer;
        pointer->prev = n;
    }
    else
    {
        temp->next = n;
        n->prev = temp;
    }
}


void DeleteNodeAtTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    delete temp;
}

void DeleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == pos)
    {
        DeleteNodeAtHead(head);
        return;
    }

    Node *temp = head;
    while (temp->data != pos)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        DeleteNodeAtTail(head);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    InsertAtTail(head, 100);
    InsertAtTail(head, 101);
    InsertAtTail(head, 102);
    InsertAtTail(head, 103);
    Display(head);
    
    cout << "Insert At Head" << endl;
    InsertAtHead(head, 111);
    Display(head);
    
    cout << "Insert At Tail" << endl;
    InsertAtTail(head, 222);
    Display(head);
    
    cout << "Insert At Specific Location" << endl;
    InsertPosition(head, 104, 103);
    Display(head);
    
    cout << "Delete At Head" << endl;
    DeleteNodeAtHead(head);
    Display(head);
    
    cout << "Delete At Specific Location" << endl;
    DeleteNode(head, 103);
    Display(head);
    
    cout << "Delete At Tail" << endl;
    DeleteNodeAtTail(head);
    Display(head);
    
    system("pause");
    return 0;
}
