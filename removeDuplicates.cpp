#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

void removeDuplicates(string& str){
	int i = 0; int checker = 0;
	int j = 0;
	int size = str.length();

	while(j < str.length() && i < size) {
		int val = str[j] - 'a';
		if((checker & (1 << val)) == 0) {
			checker |= (1 << val);
			str[i++] = str[j++];
		}
		else {
			j++;
			size--;
		}
	}

	str.resize(size);
}

int main(int argc, char const *argv[]) {
	string str = "abababab";
	removeDuplicates(str);
	cout<<str<<endl;
}
