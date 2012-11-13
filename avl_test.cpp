#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  AVL<int>* avl = new AVL<int>();
  
  cout << "Traversal Print" << endl;
  cout << endl;
  avl->insert(1);
  avl->insert(2);
  avl->insert(3);
  /*
  avl->insert(4);
  avl->insert(5);
  avl->insert(5);
  avl->insert(7);
  */
  avl->print();

  cout << endl;
  cout << "End of Insert" << endl;
}
