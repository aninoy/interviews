#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ct {
	int w;
	int v;
};

vector<ct> ctypes;
map<int, int> memo;

int mdv(int cap) {
	auto it = memo.find(cap);
	if(it != memo.end()) {
		return it->second;
	}
	int max = 0;
	for(int i = 0; i < ctypes.size(); i++) {
		int w = ctypes[i].w;
		int v = ctypes[i].v;
		if(w <= cap) {
			int value = mdv(cap-w) + v;
			if(value > max) {
				max = value;
			}
		}
	}

	memo.insert(make_pair(cap, max));
	return max;
}

int main() {

	ctypes.push_back({7, 160});
	ctypes.push_back({3, 90});
	ctypes.push_back({2, 0});

	int result = mdv(0);
	cout<<result<<endl;
	return 0;
}
