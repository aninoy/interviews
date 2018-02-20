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

void bfs(vector<Node*> &adj, map<int, int> &level, map<int, int> &parent) {
	int l = 0;
	vector<Node*> frontier;
	Node* start = adj.front();
	frontier.push_back(start);
	level.insert(make_pair(start->vertex, 0));
	parent.insert(make_pair(start->vertex, -1));

	while(!frontier.empty()) {
		vector<Node*> next;
		for(int i = 0; i < frontier.size(); i++) {
			Node *vertex = adj[frontier[i]->vertex];
			vertex = vertex->next;
			while(vertex != NULL) {
				if(level.find(vertex->vertex) == level.end()) {
					level.insert(make_pair(vertex->vertex, l + 1));
					parent.insert(make_pair(vertex->vertex, frontier[i]->vertex));
					next.push_back(vertex);
				}
				vertex = vertex->next;
			}
		}

		frontier = next;
		l++;
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
	map<int, int> level;
	map<int, int> parent;


	insertVertex(adj); // s 0
	insertVertex(adj); // a 1
	insertVertex(adj); // c 2
	insertVertex(adj); // d 3
	insertVertex(adj); // f 4
	insertVertex(adj); // v 5
	insertVertex(adj); // x 6
	insertVertex(adj); // z 7
	insertEdge(adj, 0, 1); insertEdge(adj, 0, 6);
	insertEdge(adj, 1, 0); insertEdge(adj, 1, 7);
	insertEdge(adj, 2, 3); insertEdge(adj, 2, 4); insertEdge(adj, 2, 5); insertEdge(adj, 2, 6);
	insertEdge(adj, 3, 6); insertEdge(adj, 3, 2); insertEdge(adj, 3, 4);
	insertEdge(adj, 4, 2); insertEdge(adj, 4, 3); insertEdge(adj, 4, 5);
	insertEdge(adj, 5, 4); insertEdge(adj, 5, 2);
	insertEdge(adj, 6, 0); insertEdge(adj, 6, 3); insertEdge(adj, 6, 2);
	insertEdge(adj, 7, 1);
	printAdjList(adj);

	bfs(adj, level, parent);
	printMap(level, "Levels");
	printMap(parent, "Parents");

	return 0;
}
