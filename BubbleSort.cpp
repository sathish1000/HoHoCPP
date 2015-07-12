#include <iostream>
using namespace std;

class BubbleSort
{

	int* array;
	int N;

public:

	BubbleSort(int* arr, int n):array(arr),N(n) {
		order();
		display();
	};

	void order(){
		for (int i=0; i<(N-1); i++){
			for (int j=i+1; j<N; j++){
				if ((*(array+i)) < (*(array+j))){
					int temp;
					temp = (*(array+j));
					(*(array+j)) = (*(array+i));
					(*(array+i)) = temp;
				}
			}		
		}
	}

	void display(){
		for (int i=0; i<(N); i++){
			cout << *(array+i) << endl;
		}		


	}
};

int main()
{
	const int N=10;
	int array[N]={1,5,2,65,23,43,21,79,45,65};
	BubbleSort(array,N);
	return 0;
}
