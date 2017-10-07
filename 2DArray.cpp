#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
    int** arry2D;
    int noOfCols = 2, noOfRows = 3;
    
    arry2D = new int*[noOfRows];
    for (int i=0; i<noOfRows; i++) {
        arry2D[i] = new int[noOfCols];
    }
    
    for (int m=0; m<noOfRows; m++) {
        for (int n=0; n<noOfCols; n++) {
            arry2D[m][n] = rand()%100;
        }
    }
    
    for (int m=0; m<noOfRows; m++) {
        for (int n=0; n<noOfCols; n++) {
            cout << "Value at position m = " << m << ", n = "<< n << " is " << arry2D[m][n] << endl;
        }
    }    
    
    for (int i=0; i<noOfRows; i++) {
        delete [] arry2D[i];
    }    
    delete [] arry2D;
    return 0;
}