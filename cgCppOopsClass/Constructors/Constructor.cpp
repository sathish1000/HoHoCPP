#include <iostream>
using namespace std;

class Rectangle{

    private:
        int x;
        int y;

    public:
        Rectangle(int a, int b):x(a),y(b){};
        int area(){
            return (x*y);
        } 
};

int main(){
    Rectangle RectA(5,10);
    cout << RectA.area() << endl;
    return 0;
}
