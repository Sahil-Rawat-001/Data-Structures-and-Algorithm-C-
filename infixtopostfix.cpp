#include <iostream>
using namespace std;

class Stack {
private:
    char *arr;
    int topInd;
    int cap;

    void resize() {
        int newcap = cap * 2;
        char *newarr = new char[newcap];

        for (int i = 0; i < cap; i++) {
            newarr[i] = arr[i];
        }

        delete[] arr;
        arr = newarr;
        cap = newcap;
    }

public:
    Stack(int n = 5) {
        cap = n;
        topInd = -1;
        arr = new char[cap];
    }

    void push(char val) {
        if (topInd == cap - 1) { // Corrected resize condition
            resize();
        }
        arr[++topInd] = val;
    }

    void pop() {
        if (topInd == -1) {
            cout << "Underflow: empty stack pop" << endl;
            return;
        }
        topInd--;
    }

    char top() {
        if (topInd == -1) {
            cout << "Underflow: empty stack top" << endl;
            return '\0';
        }
        return arr[topInd];
    }

    bool isEmpty() {
        return topInd == -1;
    }
};

// Function to return operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; 
}

int main() {
    Stack stk;
    string infix, postfix;

    cout << "Enter an infix expression: ";
    cin >> infix;

    cout << "Infix expression: " << infix << endl;

    for (int i = 0; i < infix.size(); i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            postfix += ch;
        } 
        else if (ch == '(') { // Push '(' onto stack
            stk.push(ch);
        } 
        else if (ch == ')') { // Pop until '(' is found
            while (!stk.isEmpty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop(); // Pop '('
        } 
        else { // If operator (+, -, *, /)
            while (!stk.isEmpty() && precedence(stk.top()) >= precedence(ch)) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (!stk.isEmpty()) {
        postfix += stk.top();
        stk.pop();
    }

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
