#include<iostream>

using namespace std;

class Stack{

    private:
        static const int max_size = 10;
        int arr[max_size];
        int top = -1;
    
    public:

       Stack(){
         top = -1;
       }
        
        // push operation
        void push(int val){

            if(top > max_size){

                cout << "Overflow stack is full" << endl;
            } else{

                arr[++top] = val;
            }
        }

        // pop operation
        void pop(){

            if(top == -1){
                cout << "Underflow stack is empty" << endl;
            } else{
                top--;
            }
        }

        void peek(){
            
            if(top == -1){
                cout << "Underflow stack is empty" << endl;
            } else{
                cout << endl << arr[top] << endl;
            }
        }

        void display(){

            if(top == -1){
                cout << "Underflow stack is empty" << endl;
            } else{

                for(int i = 0; i <= top; i++){

                    cout << arr[i] << " ";
                }
            }
        }
};



int main(){

    Stack stk1;

    stk1.push(10);
    stk1.push(20);
    stk1.push(30);
    stk1.push(40);
    stk1.push(50);
    stk1.pop();
    stk1.pop();
    stk1.peek();
    stk1.display();

    Stack stk2;

    stk2.push(1);
    stk2.push(2);
    stk2.push(3);
    stk2.push(4);
    stk2.push(5);
    stk2.pop();
    stk2.pop();
    stk2.peek();
    stk2.display();
 

    return 0;
}