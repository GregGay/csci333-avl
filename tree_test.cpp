#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BST<int>* bst = new BST<int>();
  
  cout << "Tree Print" << endl;
  bst->insert(10);
  bst->insert(5);
  bst->insert(7);
  bst->insert(3);
  bst->insert(2);
  bst->insert(15);
  bst->insert(16);
  bst->insert(1);
  bst->insert(12);
  bst->treePrint();

  cout << endl;
  
  bst->remove(10);
  bst->treePrint();
  
  cout << endl;

  bst->remove(12);
  bst->treePrint();
  
  cout << endl;

  bst->remove(5);
  bst->treePrint();
  
  cout << endl;

  bst->remove(1);
  bst->treePrint();

  cout << endl;

  bst->remove(3);
  bst->treePrint();

  cout << endl;

  bst->remove(16);
  bst->treePrint();

  cout << endl;

  bst->remove(15);
  bst->treePrint();

  cout << endl;

  bst->remove(2);
  bst->treePrint();

  cout << "End of Remove" << endl;
}
