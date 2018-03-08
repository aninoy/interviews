#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void reverseWord(int start, int end, string &s) {
	int i = 0;
	while(start < end) {
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
		i++;
	}
	cout<<"inner: "<<i<<endl;
}


void reverseWords(string &s){
	int start = 0, end = 0;
	int i = 0;
	while(end < s.length()) {
		if(s[end] == ' ') {
			reverseWord(start, end - 1, s);
			end++;
			start = end;
		}
		else {
			end++;
		}
		i++;
	}
	cout<<"outer: "<<i<<endl;

	if(start < end) {
		reverseWord(start, end - 1, s);
	}
	// cout<<"outer: "<<i<<endl;
	reverseWord(0, s.length() - 1, s);
}

int main() {
	string s = "a b c d";
	cout<<"Original: "<<s<<endl;
	reverseWords(s);
	cout<<"Reversed: "<<s<<endl;
	return 0;
}
