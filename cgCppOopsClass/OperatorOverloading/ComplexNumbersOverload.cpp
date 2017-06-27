#include <iostream>
#include <sstream>
using namespace std;

class ComplexNumber{

	private:
	int real;
	int imaginary;

	public:
	ComplexNumber(int x, int y):real(x),imaginary(y){};
	ComplexNumber operator+ (const ComplexNumber &cNum){
		this->real = this->real + cNum.real;//These steps will update the variables of c1.
		//To avoid updating c1, use commented steps below.
		this->imaginary = this->imaginary + cNum.imaginary;

                //int treal = this->real + cNum.real;
                //int timaginary = this->imaginary + cNum.imaginary;
                //return ComplexNumber(treal,timaginary);

		return ComplexNumber(this->real,this->imaginary);
	}

        ComplexNumber add(const ComplexNumber &cNum){
                this->real = this->real + cNum.real;
                this->imaginary = this->imaginary + cNum.imaginary;
                return ComplexNumber(this->real,this->imaginary);
        }

        string toString(){
		ostringstream ostr;
		ostr << "Real = " << real << ", Imaginary = " << imaginary << "." << endl;
		return ostr.str();
	}

};

int main(){
	ComplexNumber c1 = ComplexNumber(10,5);
        ComplexNumber c2 = ComplexNumber(5,10);

        ComplexNumber c3 = c1+c2;
        ComplexNumber c4 = c1.add(c2);

        cout << c3.toString() << endl;
        cout << c4.toString() << endl;
	return 0;
}
