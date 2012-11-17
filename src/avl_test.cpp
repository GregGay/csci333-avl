#include "AVL.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  AVL<int>* avl = new AVL<int>();
  //AVL<double>* avlD = new AVL<double>();
  //AVL<std::string>* avlS = new AVL<std::string>();
  
  cout << "Pre Order Traversal Print" << endl;
  cout << endl;
  avl->insert(4);
  avl->insert(2);
  avl->insert(3);
  avl->insert(7);
  avl->insert(1);
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
