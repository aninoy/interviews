#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <list>

using namespace std;
# define INF numeric_limits<int>::max()

struct Node {
	int v;
	int w;
};

class comparator {
public:
	bool operator()(Node a, Node b) {
		return a.w > b.w;
	}
};

void addEdge(list<Node> adj[], int s, int t, int w) {
	adj[s].push_back(Node({t, w}));
	adj[t].push_back(Node({s, w}));
}

void dijkstra(list<Node> adj[], int s, int V){
	priority_queue<Node, vector<Node>, comparator> pq;
	vector<int> dist(V, INF);

	dist[s] = 0;
	pq.push(Node({s, 0}));

	while(!pq.empty()) {
		int u = pq.top().v;
		pq.pop();

		list<Node>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++) {
			int v = it->v;
			int w = it->w;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(Node({v, dist[v]}));
			}
		}
	}
	//print dists
	for(int i = 0; i < dist.size(); i++) {
		cout<<i<<": "<<dist[i]<<endl;
	}
}

int main() {
	int V = 9;
	list<Node> *adj = new list<Node>[V];

	addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    dijkstra(adj, 0, V);

	return 0;
}
