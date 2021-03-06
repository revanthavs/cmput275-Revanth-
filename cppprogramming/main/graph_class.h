#ifndef _GRAPH_CLASS_H
#define _GRAPH_CLASS_H
#include <unordered_map>
#include <unordered_set>

class Graph{
public:
	void addVertex(int v);

	virtual void addEdge(int u, int v);

private:
	unordered_map<int, unordered_set<int>> nbrs;
};

#endif
