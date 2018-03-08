#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str = "a+b+c^d";
	string res;
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '+' || str[i] == '-') {
			if(!s.empty()) {
				res += s.top();
				s.pop();
			}
			s.push(str[i]);
		}
		else if(str[i] == '*' || str[i] == '/'){
			if(!s.empty()) {
				char prev = s.top();
				if(prev == '^') {
					res += s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
		else if(str[i] == '^') {
			s.push(str[i]);
		}
		else {
			res += str[i];
		}
	}

	while(!s.empty()){
		res += s.top();
		s.pop();
	}
	cout<<"Result: "<<res<<"\n";
	return 0;
}
