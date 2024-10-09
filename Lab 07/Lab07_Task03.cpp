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
void deleteAtHead(Node *&head)
{
    cout<<"Delete Function Called";
    if (head == NULL)
    {
        cout<<"Empty";
        return;
    }

    Node *todel = head;
    if (head->next==head)
    {
        delete todel;
        head=NULL;
        return;
    }
    Node *temp = head;
    
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head = head->next;
    delete todel;
}

void deleteAtTail(Node *&head)
{
    if (head == NULL)
    {
        cout<<"Empty";
        return;
    }
    Node * temp = head;
    while (temp->next->next !=head)
    {
        temp = temp -> next;
    }
    Node * todelte = temp->next;
    temp->next=head;
    delete todelte;
}
void deleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout<<"Empty";
        return;
    }
    if (head->data==pos)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    while (temp->next->data !=pos )
    {
        temp=temp->next;
    }
    Node*todel=temp->next;
    temp->next=temp->next->next;
    delete todel;
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
    deleteNode(head,20);
    cout<<endl<<"After Deleting Node: ";
    display(head);
    system("pause");
}