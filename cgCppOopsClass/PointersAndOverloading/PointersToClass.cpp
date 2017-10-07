#include <iostream>
using namespace std;

class RectangleC{

        int x;
        int y;

    public:
        RectangleC(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

struct RectangleS{

        int x;
        int y;

        RectangleS(int a, int b){
            x=a;
            y=b;
	};
        int area(){
            return (x*y);
        } 
};


int main(){

    //Difference between struct anfd class.

    RectangleC RectA(5,10);
    //cout << RectA.x << endl; //Gives a error.

    RectangleS RectB(5,10);
    cout << RectB.x << endl;

    //Pointer to a class.
    RectangleC* rect = new RectangleC(15,20);
    cout << rect->area() << endl;
    return 0;
}
