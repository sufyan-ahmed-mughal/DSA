#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertNodeAtTail(Node *&head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        head = n;
        n->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(Node *&head)
{
    if (head==NULL)
    {
        cout<<"emtpy";
        return;
    }
    
    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node *head = NULL;
    cout<<"After inserting Node at End: ";
    insertNodeAtTail(head, 10);
    insertNodeAtTail(head, 20);
    insertNodeAtTail(head, 30);
    insertNodeAtTail(head, 40);
    insertNodeAtTail(head, 50);
    insertNodeAtTail(head, 60);
    display(head);
    system("pause");
}