#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int counter = 0;

void insertAtEnd(Node **head, int newData)
{
    counter++;
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}


void findMiddleDirectly(Node *head)
{
    int middle = counter / 2;  // Find the middle index
    int count = 0;
    Node *temp = head;
    while (count != middle)    
    {
        temp = temp->next;
        count++;
    }
    cout << "The Middle (Direct) is: " << temp->data << endl;
}

void findMiddle(Node *head)
{
    if (head == NULL)
    {
        cout << "The list is Empty";
        return;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "The middle element is: " << slow->data << endl;
}
void printList(Node *head)
{
    if (head == NULL)
    {
        cout << "List is Empty!...";
        return;
    }

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL; // Created Null Node
    int n, value;      // Two Variables for Size and the Value
    cout << "How Many Values do you want to insert in the list? ";
    cin >> n; // Gettint the Nodes Size how many should be add
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Value: " << i + 1 << " :";
        cin >> value;              // Getting Value from User
        insertAtEnd(&head, value); // Passing the value to Function
    }
    // Print the Node list
    printList(head);
    //Find Middle 
    findMiddle(head);

    findMiddleDirectly(head);
    system("pause");

    return 0;
}
