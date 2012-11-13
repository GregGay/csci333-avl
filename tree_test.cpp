#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  AVL<int>* bst = new AVL<int>();
  
  cout << "Tree Print" << endl;
  bst->BSTInsert(10);
  bst->BSTInsert(5);
  bst->BSTInsert(7);
  bst->BSTInsert(3);
  bst->BSTInsert(2);
  bst->BSTInsert(15);
  bst->BSTInsert(16);
  //bst->insert(1);
  //bst->insert(12);
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
