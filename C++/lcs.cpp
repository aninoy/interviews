#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <list>

using namespace std;
# define INF numeric_limits<int>::min()

int **memo;
string str1, str2;
int slen1, slen2;
int uc = 0;
int lcs(int i, int j) {
	uc++;
	if(i == 0 || j == 0) {
		memo[i][j] = 0;
		return 0;
	}

	if(memo[i][j] != -1) {
		return memo[i][j];
	}

	int max = INF;

	if(str1[i] == str2[j]) {
		max = 1 + lcs(i-1, j-1);
	}
	else {
		int t1 = lcs(i-1, j);
		int t2 = lcs(i, j-1);
		//int t3 = lcs(i+1, j+1);

		if(t1 > max) {
			max = t1;
		}
		if(t2 > max) {
			max = t1;
		}
		//if(t3 > max) {
		//	max = t1;
		// }
	}


	memo[i][j] = max;
	return max;
}

void printmemo() {
	for(int i = 0; i < slen1; i++) {
		for(int j = 0; j < slen2; j++) {
			cout<<memo[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main() {

	str1 = "abcdaf";
	str2 = "acbcf";
	slen1 = str1.length();
	slen2 = str2.length();
	memo = new int*[slen1+1];
	for(int i = 0; i < slen1+1; i++) {
		memo[i] = new int[slen2+1];
		for(int j = 0; j < slen2+1; j++) {
			memo[i][j] = -1;
		}
	}
	printmemo();

	int result = lcs(slen1, slen2);
	cout<<result<<endl;
	printmemo();
	cout<<uc<<endl;
	return 0;
}
