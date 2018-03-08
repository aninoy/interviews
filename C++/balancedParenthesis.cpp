#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str = "{(a+b})";
	stack<char> s; //new stack<char>();
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
			s.push(str[i]);
		}
		if(str[i] == ')' && s.top() == '(') {
			s.pop();
		}
		else if(str[i] == '}' && s.top() == '{') {
			s.pop();
		}
		else if(str[i] == ']' && s.top() == '[') {
			s.pop();
		}
	}
	if(s.empty()) {
		cout<<"Expression is balanced.\n";
	}
	else {
		cout<<"Expression is NOT balanced!\n";
	}
	return 0;
}
