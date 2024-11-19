#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Destructor
    ~Stack() {
        clear(); 
    }

    // Push
    void push(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    // Pop
    void pop() {
        if (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp; // Free memory
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // Peek Return the top
    int peek() const {
        if (!isEmpty()) {
            return top->data;
        } else {
            cout << "Stack is empty." << endl;
            throw runtime_error("Empty stack");
        }
    }

    // Clear
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    
    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    // Create a stack of integers
    Stack stack;


    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Peek 
    cout << "Top element: " << stack.peek() << endl;

    // Pop 
    stack.pop();
    cout << "After pop, top element: " << stack.peek() << endl;

    // Clear the stack
    stack.clear();
    if (stack.isEmpty()) {
        cout << "Stack is empty after clearing." << endl;
    }
    system("pause");
    return 0;
}
