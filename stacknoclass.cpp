// here we implementing stack without class in cpp

/*
 
 stack works on LIFO (Last In First Out) principal

  Push(): This operation insert data inside stack;
  Pop() : This operation deletes data from stack
  top() : show or display top element
  size(): display size of stack
  peek():

  Overflow: It is a condition when stack is full and someone perform push ops
  Underflow: It is a condition when stack is empty and someone perform pop ops
*/

#include<iostream>
using namespace std;

// n is the size of stack
#define n 10


int stack[n]; // this is stack
int top = -1; // this is top initially has -1 value which means stack is empty


// push operation function
void push(int x){
 
 // check before pushing is stack has enough space or not
 if(top == n - 1){

    cout << "Overflow !!! : stack is full" << endl;
 } else {

    top++; // increase top first
    stack[top] = x;
 }
}

void pop(){

    if(top ==  -1){

        cout << "Underflow !!! : stack is empty" << endl;
    } else {
        top--; // decrease top
    }
}

void peek(){
     
    if(top == -1)
    cout << "Underflow !!! : stack is empty" << endl; 
    else
    cout << "The current top element is: " << stack[top] << endl;
}

void display(){

    if(top == -1)
    cout << "Stack is empty" << endl;

    for(int i = 0; i <= top; i++){

        cout << stack[i] << " ";
    }
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