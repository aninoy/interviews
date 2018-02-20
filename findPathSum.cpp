#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

struct Node {
	char name;
	int value;
	Node *left;
	Node *right;
};

map<pair<char,int>,bool> memo;
int origSum = -1;

Node* createNode(int value, char name){
	Node *node = new Node();
	node->name = name;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool search(char name, int value) {
	return memo.find(make_pair(name, value)) != memo.end();
}

void memoize(char name, int value) {
	// cout<<name<<" "<<value<<endl;
	memo[{name, value}] = true;
}

void findPath(Node *node, int sum, string path) {
	if(node == NULL) {
		return;
	}
	if(search(node->name, sum)) {
		return;
	}
	if(sum == node->value) {
		cout<<path+node->name<<endl;
	}
	findPath(node->left, sum - node->value, path + node->name);
	findPath(node->right, sum - node->value, path + node->name);
	findPath(node->left, origSum, "");
	findPath(node->right, origSum, "");
	memoize(node->name, sum);
}

void printMap() {
	for(auto it = memo.begin(); it != memo.end(); it++) {
		cout<<it->first.first<<", "<<it->first.second<<": "<<it->second<<"\n";
	}
}

int main(int argc, char const *argv[])
{
	Node *a = createNode(1, 'a');
	Node *b = createNode(2, 'b');
	Node *c = createNode(5, 'c');
	Node *d = createNode(2, 'd');
	Node *e = createNode(3, 'e');
	Node *f = createNode(0, 'f');
	Node *g = createNode(-2, 'g');
	Node *h = createNode(1, 'h');
	a->left = b;
	b->left = d;
	d->left = h;
	b->right = e;
	a->right = c;
	c->left = f;
	c->right = g;

	origSum = 4;
	findPath(a, origSum, "");
	// printMap();
	return 0;
}
