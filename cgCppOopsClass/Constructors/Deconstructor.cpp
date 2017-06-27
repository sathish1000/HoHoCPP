#include <iostream>
using namespace std;

class Rectangle{

    private:
        int* x;
        int* y;

    public:
        Rectangle(int a, int b){
            x = new int;
            y = new int;
            *x = a;
	    *y = b;		
	};
        ~Rectangle(){
            cout << "Deconstructor called" << endl;
            delete x;
	    delete y;
	}
        int area(){
            return ((*x)*(*y));
        } 
};

int main(){
    Rectangle RectA(5,10);
    cout << RectA.area() << endl;
    cout << "Return 0" << endl;
    return 0;
}
