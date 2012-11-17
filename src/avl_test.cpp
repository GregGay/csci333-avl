#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  AVL<int>* avl = new AVL<int>();
  
  cout << "Pre Order Traversal Print" << endl;
  cout << endl;
  avl->insert(1);
  avl->insert(2);
  avl->insert(4);
  avl->insert(7);
  avl->insert(8);
  avl->print();
  /*cout << endl;
  cout << "Post Order Traversal" << endl;
  avl->postOrderTraversal();
  cout << endl;
  cout << "In Order Traversal" << endl;
  avl->inOrderTraversal();*/
  cout << endl;
  cout << "End of Insert" << endl;
}
