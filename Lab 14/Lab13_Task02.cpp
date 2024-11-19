#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
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
    void push(char item) {
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

    // Peek
    char peek() const {
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

    // isEmpty
    bool isEmpty() const {
        return top == nullptr;
    }
};

// Function to reverse 
string reverseString(const string& str) {
    Stack stack;

    // Push each character
    for (int i = 0; i < str.length(); ++i) {
        stack.push(str[i]);
    }

    // Pop characters 
    string reversed;
    while (!stack.isEmpty()) {
        reversed += stack.peek();
        stack.pop();
    }

    return reversed;
}

int main() {
    string str;

    cout << "Enter a string to reverse: ";
    getline(cin, str);

    // Call the reverseString function
    string reversed = reverseString(str);

    // Display the reversed string
    cout << "Reversed string: " << reversed << endl;
    system("pause");
    return 0;
}
