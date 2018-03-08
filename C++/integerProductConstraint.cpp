#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int prod = 20;
int values[2] = {0, 0};
int integers[7] = {2, 4, 1, 6, 5, 40, -1};
int n = 7;
int counter = 0;
// map<int, int>
bool findProd(int index) {
	counter++;
	cout<<"Testing: "<<integers[index]<<", "<<values[0]<<", "<<values[1]<<endl;
	if(index >= n) {
		return false;
	}

	if(values[0] * integers[index] == prod) {
		values[1] = integers[index];
		return true;
	}
	else {
		//values[0] = integers[index];
		if (findProd(index + 1)) {
			return true;
		}
		else {
			values[0] = integers[index];
			return findProd(index+1);
		}
	}
}

int main() {

	if(findProd(0)) {
		cout<<"Found! -> "<<values[0]<<", "<<values[1]<<endl;
	}
	else {
		cout<<"Not Found!\n";
	}
	cout<<"Calls: "<<counter<<endl;
	return 0;
}
