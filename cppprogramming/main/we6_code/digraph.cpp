#include "digraph.h"
#include <queue>
#include <iostream> // Need to remove this
using namespace std;

void Digraph::addVertex(int v) {
  // If it already exists, does nothing.
  // Otherwise, adds v with an empty adjacency set.
  nbrs[v];
}

void Digraph::addEdge(int u, int v) {
  addVertex(v);
  nbrs[u].insert(v); // will also add u to nbrs if it was not there already
}


bool Digraph::isVertex(int v) {
  return nbrs.find(v) != nbrs.end();
}

bool Digraph::isEdge(int u, int v) {
  // check that u is in the keys and that it's associated set contains v
  return nbrs.find(u) != nbrs.end() && nbrs[u].find(v) != nbrs[u].end();
}

unordered_set<int>::const_iterator Digraph::neighbours(int v) const {
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.begin();
}

unordered_set<int>::const_iterator Digraph::endIterator(int v) const {
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.end();
}

int Digraph::numNeighbours(int v) {
  // this will crash the program if v is not a vertex
  return nbrs.find(v)->second.size();
}

int Digraph::size() {
  return nbrs.size();
}

vector<int> Digraph::vertices() {
  vector<int> v;
  for (unordered_map<int, unordered_set<int>>::const_iterator it = nbrs.begin();
    it != nbrs.end(); it++) {
      v.push_back(it->first);
    }
  return v;
}

bool Digraph::isWalk(vector<int> walk) {
  if (walk.size() == 0)
    return false;
  if (walk.size() == 1)
    return isVertex(walk[0]);
  for (vector<int>::size_type i=0; i<walk.size()-1; i++)
    if (!isEdge(walk[i], walk[i+1]))
      return false;

  return true;
}

bool Digraph::isPath(vector<int> path) {
  set<int> s(path.begin(), path.end());
  if (s.size() < path.size())
    return false;

  return isWalk(path);
}

unordered_map<int, int> breadthFirstSearch(const Digraph& graph, int startVertex) {
  unordered_map<int, int> searchTree; // map each vertex to its predecessor

  searchTree[startVertex] = -1;

  queue<int> q;         // store unexplored nodes in a queue rather than an unordered_set
  q.push(startVertex);

  while (!(q.empty())) {
    int v = q.front();  // return a reference to the "oldest" element
    q.pop();

    for (auto iter = graph.neighbours(v); iter != graph.endIterator(v); iter++) {
      if (searchTree.find(*iter) == searchTree.end()) { // not reached before
        searchTree[*iter] = v;
        q.push(*iter);
      }
    }
  }

  return searchTree;
}

int count_components(Digraph& graph){
  int count = 0, total = 0;
  vector<int> vertexs = graph.vertices();
  unordered_set<int> seen_vertexs;
  // int s = vertexs.size();
  while (!(vertexs.empty())) {
    int start_v = vertexs.back();
    if (!(seen_vertexs.empty())) {
      while ((!vertexs.empty()) && (seen_vertexs.find(start_v) != seen_vertexs.end())) {
        vertexs.pop_back();
        start_v = vertexs.back();
      }
    } 
    if (vertexs.empty()){
      break;
    }
    count++;
    unordered_map<int, int> result = breadthFirstSearch(graph, start_v);
    for (auto entry: result){
      int value = entry.first;
      seen_vertexs.insert(value);
    }
  }
  return count;
}

Digraph read_city_graph_undirected(){
  Digraph graph;
  string input_line;
  while (getline(cin, input_line)){
    char V = 'V', E = 'E', comma = ',';
    if (input_line[0] == V){
      int index = 2; char temp = input_line[index];
      while (temp != ','){
        index++;
        temp = input_line[index];
      }
      string sub_str = input_line.substr(2, index-1);
      int ver = stoi(sub_str);
      graph.addVertex(ver);
    }
    else if (input_line[0] == E){
      int bounds = input_line.size()+1;
      int index = 2, substr_i = 0; char temp = input_line[index]; string temp_string = "", sub_str[2];
      for (int i = index; i < bounds; i++) {
        temp = input_line[i];
        if (temp == comma){
          sub_str[substr_i] = temp_string;
          temp_string = "";
          substr_i++;
          continue;
        }
        else{
          temp_string += temp;
        }
      }
      int ver1 = stoi(sub_str[0]);
      int ver2 = stoi(sub_str[1]);
      graph.addEdge(ver1, ver2);
      graph.addEdge(ver2, ver1);
    }
  }
  return graph;
}

int main(){
  Digraph graph = read_city_graph_undirected();
  int count = count_components(graph);
  cout << count << endl;
}


    // else if (input_line[0] == E){
    //  int index = 2; char temp = input_line[index];
    //   while (temp != ','){
    //     index++;
    //     temp = input_line[index];
    //   }
    //   string sub_str = input_line.substr(2, index-1);
    //   int ver1 = stoi(sub_str); index++; int temp_i = index;
    //   temp = input_line[index];
    //   while (temp != ','){
    //     index++;
    //     temp = input_line[index];
    //   }
    //   sub_str = input_line.substr(temp_i, index-1);
    //   int ver2 = stoi(sub_str);
    //   graph.addEdge(ver1, ver2);
    //   graph.addEdge(ver2, ver1);
    // }
