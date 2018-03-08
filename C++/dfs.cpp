#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct Node {
	int vertex;
	Node *next;
};

void insertVertex(vector<Node*> &adj) {
	Node *vertex = new Node();
	vertex->vertex = adj.size();
	vertex->next = NULL;
	adj.push_back(vertex);
}

void insertEdge(vector<Node*> &adj, int start, int end) {
	Node* edge = new Node();
	edge->vertex = end;
	edge->next = NULL;
	if(start < adj.size() && start >= 0) {
		Node *head = adj[start];
		if(head == NULL) {
			adj[start] = edge;
		}
		else {
			while(head->next != NULL) {
				head = head->next;
			}
			head->next = edge;
		}
	}
}

void dfsVisit(Node *vertex, vector<Node*> &adj, map<int, int> &parent) {

	if(vertex == NULL) {
		return;
	}

	int curParent = vertex->vertex;
	vertex = vertex->next;

	while(vertex != NULL) {
		if(parent.find(vertex->vertex) == parent.end()) {
			parent.insert(make_pair(vertex->vertex, curParent));
			dfsVisit(adj[vertex->vertex], adj, parent);
		}
		vertex = vertex->next;
	}
}

void dfs(vector<Node*> &adj, map<int,int> &parent) {
	for(int i = 0; i < adj.size(); i++) {
		if(parent.find(adj[i]->vertex) == parent.end()) {
			parent.insert(make_pair(adj[i]->vertex, -1));
			dfsVisit(adj[i], adj, parent);
		}
	}
}

void printMap(map<int, int> &parent, string name) {
	cout<<name<<"\n----------------\n";
	map<int, int>::iterator it = parent.begin();
	while(it != parent.end()) {
		cout<<it->second<<" --> "<<it->first<<"\n";
		it++;
	}
	cout<<"\n";
}

void printAdjList(vector<Node*> &adj) {
	cout<<"Adjacency List: \n--------------\n";
	for(int i = 0; i < adj.size(); i++) {
		Node *head = adj[i];
		while(head->next != NULL) {
			cout<<head->vertex<<" --> ";
			head = head->next;
		}
		cout<<head->vertex<<endl;
	}
	cout<<"\n";
}

int main(int argc, char const *argv[])
{
	vector<Node*> adj;
	map<int, int> parent;


	insertVertex(adj); // s 0
	insertVertex(adj); // a 1
	insertVertex(adj); // c 2
	insertVertex(adj); // d 3
	insertVertex(adj); // f 4
	insertVertex(adj); // v 5
	insertVertex(adj); // x 6
	insertVertex(adj); // z 7
	insertEdge(adj, 0, 3); insertEdge(adj, 0, 4); insertEdge(adj, 0, 5); insertEdge(adj, 0, 6);
	insertEdge(adj, 1, 0); insertEdge(adj, 1, 7);
	insertEdge(adj, 2, 1); insertEdge(adj, 2, 6); //insertEdge(adj, 2, 5); insertEdge(adj, 2, 6);
	insertEdge(adj, 3, 6); insertEdge(adj, 3, 2); insertEdge(adj, 3, 4);
	insertEdge(adj, 4, 2); insertEdge(adj, 4, 3); insertEdge(adj, 4, 5);
	insertEdge(adj, 5, 4); insertEdge(adj, 5, 2);
	insertEdge(adj, 6, 0); insertEdge(adj, 6, 3); insertEdge(adj, 6, 2);
	insertEdge(adj, 7, 1);
	printAdjList(adj);

	dfs(adj, parent);
	printMap(parent, "Parents");
	cout<<"Finished!\n";
	return 0;
}
