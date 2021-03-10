#include <iostream>
#include <vector>
#include "digraph.h"

using namespace std;

int main() {
  Digraph graph;
  int nodes[] = {1, 2, 3, 4, 5, 6};
  for (auto v : nodes)
    graph.addVertex(v);
  int edges[][2] = {{1, 2}, {3, 4}, {3, 5}, {4, 5}};
  for (auto e : edges) {
    graph.addEdge(e[0], e[1]);
    graph.addEdge(e[1], e[0]);
  }
  // cout << count_components(graph) << endl;
  graph.addEdge(1, 4);
  graph.addEdge(4, 1);
  // cout << count_components(graph) << endl;
    

  // graph.addVertex(1);
  // graph.addVertex(4);
  // graph.addEdge(5, 4);
  // graph.addEdge(4, 100);
  // graph.addEdge(4, 1);
  // graph.addEdge(1, 4);

  cout << "size() - " << graph.size() << endl;

  cout << "Entire adjacency list:" << endl;
  vector<int> vertices = graph.vertices();
  for (auto v : vertices) {
    cout << v << ':';
    for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
      cout << ' ' << *iter;
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
