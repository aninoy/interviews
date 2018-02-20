#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string str = "23*54*+9-";
	stack<int> s;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '+' || str[i] == '*' || str[i] == '-'
			|| str[i] == '/' || str[i] == '^') {
			int b = s.top();
			s.pop();
			int a = s.top();
			s.pop();
			int res = -1;
			switch(str[i]){
				case '+':
					res = a + b;
					break;
				case '-':
					res = a - b;
					break;
				case '*':
					res = a * b;
					break;
				case '/':
					res = a / b;
					break;
				case '^':
					res = pow(a, b);
					break;
			}
			s.push(res);
		}
		else {
			s.push(str[i] - '0');
		}
	}
	cout<<"Result: "<<s.top()<<"\n";
	return 0;
}
