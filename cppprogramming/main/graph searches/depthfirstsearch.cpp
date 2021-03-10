#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>  // for non-recursive version
#include "digraph.h"

using namespace std;

unordered_map<int, int> depthFirstSearchNonRecursive(const Digraph& graph, int startVertex) {
  unordered_map<int, int> searchTree; // map each vertex to its predecessor

  searchTree[startVertex] = -1;

  stack<int> s;         // store unexplored nodes in a stack rather than an unordered_set
  s.push(startVertex);

  while (!s.empty()) {
    int v = s.top();  // return a reference to the "newest" element
    s.pop();

    for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
      if (searchTree.find(*iter) == searchTree.end()) { // not reached before
        searchTree[*iter] = v;
        s.push(*iter);
      }
    }
  }

  return searchTree;
}


void depthFirstSearch(const Digraph& graph, int v, int parent, unordered_map<int, int>& searchTree) {
  if (searchTree.find(v) != searchTree.end()) {
    return; // already visited this node
  }

  searchTree[v] = parent;

  for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
    depthFirstSearch(graph, *iter, v, searchTree); // recursive call
  }
}

int main() {
  Digraph graph;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int label;
    cin >> label;
    graph.addVertex(label);
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph.addEdge(u, v);
  }
  int startVertex, endVertex;

  cin >> startVertex >> endVertex;

  // do the DFS to get the search tree
  unordered_map<int, int> searchTree;
  depthFirstSearch(graph, startVertex, -1, searchTree);
  // searchTree = depthFirstSearchNonRecursive(graph, startVertex);

  // print searchTree
  cout << "Search tree:" << endl;
  for (auto it : searchTree) {
    cout << it.first << ": " << it.second << endl;
  }
  cout << endl;

  // get a path from startVertex to endVertex
  list<int> path; // store the path in a doubly-linked list
  if (searchTree.find(endVertex) == searchTree.end()) {
    cout << "Vertex " << endVertex << " not reachable from " << startVertex << endl;
  }
  else {
    int stepping = endVertex;
    while (stepping != startVertex) {
      path.push_front(stepping);
      stepping = searchTree[stepping]; // crawl up the search tree one step at a time
    }
    path.push_front(startVertex);

    cout << "Path from " << startVertex << " to " << endVertex << ":";
    for (auto it : path) {
      cout << ' ' << it;
    }
    cout << endl;
  }

  return 0;
}
