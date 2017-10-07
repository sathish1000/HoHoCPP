/******************************************************************************

Stack revisited.

*******************************************************************************/

#include <iostream>
using namespace std;

class Stack {
    //Data members.
    protected:
        static const int sz = 5;
        int arry[sz];
        int size;
    
    //Function members.    
    public:
        Stack():size(0) {
            for (int i=0; i<sz; i++) {
                arry[i] = 0;
            }
        }
    
        void Push(int val) {
            arry[size++] = val;
        }
        
        int Pop() {
            int val = arry[--size];
            return val;
        }
        
        void Display() {
            for (int i=0; i<size; i++) {
                cout << "Value of Stack in position " << i << " is " << arry[i] << endl;
            }            
        }
};

class StackOverflow : public Stack {
    
    public:
        StackOverflow() {
            Stack();
        }
        
        void Push(int val) {
            if (size >= sz) {
                cout << "Stack overflow" << endl;
            }
            else {
                Stack::Push(val);
            }
        }
        
        int Pop() {
            if (size == 0) {
                cout << "Stack underflow" << endl;
                return -1;
            }
            else {
                return Stack::Pop();
            }
        }        
};


int main()
{
    StackOverflow stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    cout << stack.Pop() << endl;
    cout << stack.Pop() << endl;
    cout << stack.Pop() << endl;
    cout << stack.Pop() << endl;
    cout << stack.Pop() << endl;
    cout << stack.Pop() << endl;
    stack.Display();
    return 0;
}



