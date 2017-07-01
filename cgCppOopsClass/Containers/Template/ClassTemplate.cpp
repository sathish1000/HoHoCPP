//Difference between Function and class template.
//Function template can infer the datatype from function call itself. But in class template, it is not possible.
//You have to explicitly mention the datatype in class template class.


#include <iostream>
using namespace std;

template <typename T>
T square (T x){
cout << "template function" << endl;
return x*x;
}

template <typename T>
class Stack
{
T array[100];
int size;

public:
Stack():size(0) {};
void push(int a) {array[size]=a; size++;};
void print() const { for (int i=0; i<size; i++){cout << array[i] << endl;} }
int getSize() const {return size;}
int get(int i) const {return array[i];}
};

//Basically, this is a array multiplication independent of the type.
template <typename T>
Stack<T> operator* (Stack<T>& rhs1, Stack<T>& rhs2){
Stack<T> stack;
for (int i=0; i<rhs1.getSize(); i++)
{
stack.push(rhs1.get(i)*rhs2.get(i));
}
return stack;
};

int main(){
Stack<int> stack;
stack.push(5);
stack.push(1);
stack.push(4);
stack.print();
stack = square(stack);
stack.print();
return 0;
}
