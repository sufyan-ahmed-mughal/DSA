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
void insertAtHead(Node *&head, int value)
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
    temp->next=n;
    n->next=head;
    head = n;
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
    insertNodeAtTail(head, 10);
    insertNodeAtTail(head, 20);
    insertNodeAtTail(head, 30);
    display(head);
    cout<<endl<<"After Inserting Node at Head: ";
    insertAtHead(head, 999);
    display(head);
    system("pause");
}