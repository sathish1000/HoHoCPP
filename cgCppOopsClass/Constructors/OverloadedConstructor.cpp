#include <iostream>
using namespace std;

class Rectangle{

    private:
        int x;
        int y;

    public:
//        Rectangle():x(15),y(20){};
        Rectangle(int a):x(a),y(a){};
        Rectangle(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

int main(){
    //Constructors are called based on the number of arguments passed.
    Rectangle RectA(5,10);
    Rectangle RectB(5);
//    Rectangle RectC;
    cout << RectA.area() << endl;
    cout << RectB.area() << endl;
//    cout << RectC.area() << endl;
    return 0;
}
