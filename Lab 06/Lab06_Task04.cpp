
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

void InsertPosition(Node *&head, int value, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty. Inserting at head." << endl;
        InsertAtHead(head, value);
        return;
    }

    Node *temp = head;
    while (temp != NULL && temp->data != pos)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position " << pos << " not found. Inserting at tail." << endl;
        InsertAtTail(head, value);
        return;
    }

    Node *n = new Node(value);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = n;
    }
    temp->next = n;
}

void DeleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL && temp->data != pos)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Node with value " << pos << " not found." << endl;
        return;
    }

    // Deleting head node
    if (temp == head)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    // Deleting tail or middle node
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;

    delete temp;
}

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void Middle(Node*& head){
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "Middle element: " << slow->data << "\n";
}
int main()
{
    Node *head = NULL;

    // Inserting nodes
    InsertAtTail(head, 100);
    InsertAtTail(head, 101);
    InsertAtTail(head, 102);
    InsertAtTail(head, 103);
    InsertAtTail(head, 104);
    InsertAtTail(head, 105);
    Display(head);
    Middle(head);
    system("pause");
    return 0;
}
