#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;
const int size = 6;

void printImage(int a[size][size], int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void rotate90(int[][] a, int size){
	int n = size - 1;

	for(int i = 0; i < size/2; i++) {
		for(int j = i; j < n-i; j++) {
			// cout<<"Positions: "<<i<<", "<<j<<", "<<n-i<<", "<<n-j<<"\n";
			// cout<<"Rotating: "<<a[i][j]<<", "<<a[j][n-i]<<", "<<a[n-i][n-j]<<", "<<a[n-j][i]<<"\n";
			int temp = a[n-j][i];
			a[n-j][i] = a[n-i][n-j];
			a[n-i][n-j] = a[j][n-i];
			a[j][n-i] = a[i][j];
			a[i][j] = temp;
			// cout<<"After rotating: "<<a[i][j]<<", "<<a[j][n-i]<<", "<<a[n-i][n-j]<<", "<<a[n-j][i]<<"\n";
		}
	}
	printImage(a, size);
}

int main(int argc, char const *argv[]) {
	int a[size][size] = {{1,2,3,1,2,1},{4,5,6,7,5,3},{7,8,9,1,0,1},
						{4,5,6,7,5,3},{1,2,3,1,2,1},{7,8,9,1,0,1}};
	// int a[size][size] = {{0,0,0,0,0,1},{0,0,0,0,1,0},{0,0,0,1,0,0},
	// 					{0,0,1,0,0,0},{0,1,0,0,0,0},{1,0,0,0,0,0}};
	printImage(a, size);
	cout<<endl;
	rotate90(a, size);

	return 0;
}
