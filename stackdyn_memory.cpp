#include<iostream>
using namespace std; 

int* stack = NULL;
int top = -1; 
int cap = 0; // capacity of the stack

// push operation function
void push(int x){
    // If stack is full or doesn't exist, resize
    if (top + 1 >= cap) {
        int newCap = (cap == 0) ? 1 : cap * 2;  // Double the size (or 1 if first time)
        int* temp = (int*)malloc(newCap * sizeof(int));

        if (!temp) {
            cout << "Memory allocation failed!" << endl;
            return;
        }

        // Copy old elements if stack is not NULL
        for (int i = 0; i <= top; i++) {
            temp[i] = stack[i];
        }

        free(stack);
        stack = temp;
        cap = newCap;
    }

    stack[++top] = x; // Increase top and insert element
}

void pop(){
    if (top == -1) {
        cout << "Underflow !!! : stack is empty" << endl;
        return;
    }

    top--; // Remove the top element

    // If stack is empty, free memory
    if (top == -1) {
        free(stack);
        stack = NULL;
        cap = 0;
    }
}

void peek(){
    if (top == -1) {
        cout << "Underflow !!! : stack is empty" << endl; 
    } else {
        cout << "The current top element is: " << stack[top] << endl;
    }
}

void display(){
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }

    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    pop();

    peek();

    display();

    return 0;
}
