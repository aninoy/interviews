#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

long long trailingZeros(long long n) {
	// write your code here, try to do it without arithmetic operators.
	long long count = 0;
	for (int i = 1; i <= n; i++) {
		long long factor = pow(5,i);
		if(n / factor > 0) {
			long long x = (long long)(n / factor);
			count += x*i;
		}
		else {
			break;
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	cout<<trailingZeros(5555550000000)<<"\n";
	return 0;
}
