#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int A[2][3] = {{1,2,3}, {4,5,6}};
	int B[4] = {1,2,3,4};
	for(int i = 0; i < 10; i++){
		cout<<**(A+i)<<" ";
	}

	return 0;
}
