#include <iostream>
#include <stdio.h>

using namespace std;

void insertionSort(int a[], int n) {
	if(n < 2) {
		return;
	}
	for(int key = 1; key < n; key++) {
		int i = key;
		while(i > 0 && a[i] < a[i-1]) {
			int temp = a[i];
			a[i] = a[i-1];
			a[i-1] = temp;
			i--;
		}
	}
}

void printList(int a[], int n) {
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

int main(int argc, char const *argv[]) {
	int a[] = {6,5,4,3,2,1,0,-1,-2};
	int n = 9;
	printList(a, n);
	insertionSort(a, n);
	printList(a, n);
	return 0;
}
