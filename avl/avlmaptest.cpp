#include <iostream>
#include <string>
#include "avlmap.h"

void printTree(const AVLMap<string, int>& tree) {
  for (AVLIterator<string, int> iter = tree.begin(); iter != tree.end(); ++iter) {
    cout << " - " << iter.key() << ' ' << iter.item() << endl;
  }
  cout << endl;
}

int main() {
  AVLMap<string, int> tree;

  while (true) {
    char cmd;
    string name;
    int grade;

    cin >> cmd;
    if (cmd == 'S') {
        cout << tree.size() << endl;
    }
    else if (cmd == 'U') {
      cin >> name >> grade;
      tree[name] = grade;
    }
    else if (cmd == 'F') {
      cin >> name;
      if (tree.hasKey(name)) {
        cout << name << " found with grade " << tree[name] << endl;
      }
      else {
        cout << name << " not found" << endl;
      }
    }
    else if (cmd == 'R') {
      cin >> name;
      if (!tree.hasKey(name)) {
        cout << name << " not found" << endl;
      }
      tree.remove(name);
    }
    else if (cmd == 'P') {
      cout << "Printing" << endl;
      printTree(tree);
    }
    else if (cmd == 'Q') {
      cout << "stopping" << endl;
      return 0;
    }
    else {
      cout << "invalid command" << endl;
      cout << "Possible Commands:" << endl
      << "S - print the size of the map" << endl
      << "U <name> <grade> - update the grade for the name" << endl
      << "F <name> - check if the name is in the tree" << endl
      << "R <name> - remove the entry with the given name" << endl
      << "P - print all entries in the tree, ordered by key" << endl
      << "Q - stop" << endl;

      // eat up the rest of the line
      getline(cin, name);
    }
  }
}
