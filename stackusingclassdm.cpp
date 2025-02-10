#include<iostream>

using namespace std;

class Stack{

    private:
        
        int *arr;
        int top = -1;
        int cap = 0;

        void resize(){

            int newcap = cap * 2;
            int *newarr = new int[newcap];


            for(int i = 0; i < cap; i++){

                newarr[i] = arr[i];
            }

            delete[] arr;
            arr = newarr;
            cap = newcap;
        }
    
    public:

       Stack(int size = 2){
         top = -1;
         cap = size;
         arr = new int[cap];
       }
        
        // push operation
        void push(int val){
                if(top >= cap -1) resize();
                arr[++top] = val;
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
    stk1.push(60);
    stk1.push(70);
    stk1.push(80);
    stk1.pop();
    stk1.pop();
    stk1.peek();
    stk1.display();

   
 

    return 0;
}