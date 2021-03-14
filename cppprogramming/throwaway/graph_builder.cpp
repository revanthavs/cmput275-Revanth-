#include <iostream>
using namespace std;

class Graph {
public:
	void addVertex(int v){
		nbrs[v];
	}

	virtual void addEdge(int u, int v){
		nbrs[v];
		nbrs[u].insert(v);
		nbrs[v].insert(u);
	}
friend ostream& operator<<(Graph& graph);
private:
	unordered_map<int, unordered_set<int>> nbrs;
};

class Digraph: public Graph{
public:
	void addEdge(int u, int v){
		nbrs[v];
		nbrs[u].insert(v);
	}
};


int main(){

}