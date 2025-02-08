#include<iostream>
using namespace std;

#define n 10

struct Stack {
    int arr[n]; // Stack array
    int top;    // Top index

    Stack() { top = -1; }  // Constructor to initialize top

    void push(int x) {
        if (top == n - 1) {
            cout << "Overflow !!! : Stack is full" << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Underflow !!! : Stack is empty" << endl;
        } else {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    void peek() {
        if (top == -1) {
            cout << "Underflow !!! : Stack is empty" << endl;
        } else {
            cout << "The current top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.peek();
    s.display();
    
    return 0;
}
