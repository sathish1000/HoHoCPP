#include <iostream>
using namespace std;

class Temp{
	int count;
	public:
	Temp():count(5) {};
        //Prefix increment.
	void operator ++(){
		count++;
	};
        //Postfix increment.
        void operator ++(int){
                count++;
        };
	void display(){
		cout << count << endl;
	};
};

int main(){
	Temp t;
	++t;
//	t++;//error: no ‘operator++(int)’ declared for postfix ‘++’ [-fpermissive]
        t++;
	t.display();
	return 0;
}
