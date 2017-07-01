//CODE BLOAT ISSUE WITH TEMPLATES.
//Even though, we have a single template function, when you call it using different datatypes, a function for
//each datatype is generated in the background. So in the final image, each template will generate code for 
//the no of different datatypes that are used on the template.

#include <iostream>
using namespace std;

/*
int square (int a){
cout << "int function" << endl;
return a*a;
};

double square (double a){
cout << "double function" << endl;
return a*a;
};
*/

template <typename T>
T square (T x){
cout << "template function" << endl;
return x*x;
}

int square (int a){
cout << "int function" << endl;
return a*a;
};

double square (double a){
cout << "double function" << endl;
return a*a;
};

int main(){
cout << square<int>(5) << endl;
cout << square<float>(5.5) << endl;
cout << square(5) << endl;
cout << square(5.5) << endl;
return 0;
}
