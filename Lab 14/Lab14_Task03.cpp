#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Queue {
    Node *front, *rear;
    int size;
    int capacity;  

public:
    
    Queue(int cap) {
        front = rear = NULL;
        size = 0;
        capacity = cap;
    }

    bool isFull() {
        return size == capacity;  
    }

    bool isEmpty() {
        return front == NULL;  
    }

    
    void Enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot enqueue " << data << " as the queue is full." << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;  
        } else {
            rear->next = newNode;  
            rear = newNode;  
        }

        size++;  // Increment the size after adding an element
    }

   
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";  
            temp = temp->next;
        }
        cout << endl;
    }

   
    int count() {
        return size;
    }

  
    void clear() {
        while (!isEmpty()) {
            Dequeue(); 
        }
        cout << "Queue has been cleared!" << endl;
    }

   
    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;  

        size--;  

        if (front == NULL) {  
            rear = NULL;
        }
    }
};

int main() {
    int capacity;
    
    
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    
    Queue q1(capacity);

    
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        if (q1.isFull()) {
            cout << "Queue is full! Do you want to continue adding more elements? (y/n): ";
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                break;
            }
            
        } else {
            int data;
            cout << "Enter a number to enqueue: ";
            cin >> data;
            q1.Enqueue(data);
            cout << "Queue after Enqueueing: ";
            q1.display();
        }

        cout << "Do you want to add another element to the queue? (y/n): ";
        cin >> choice;
    }

    cout << "Final state of the queue: ";
    q1.display();

    cout << "Number of elements in the queue: " << q1.count() << endl;


    char clearChoice;
    cout << "Do you want to clear the queue? (y/n): ";
    cin >> clearChoice;

    if (clearChoice == 'y' || clearChoice == 'Y') {
        q1.clear();
    }
    system("pause");
    return 0;
}
