#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  BST<int>* bst = new BST<int>();
/*
  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  
  bst->print();

  cout << endl;
  //bst->insert(12);
  bst->remove(6);
  
  bst->print();*/


  bst->insert(10);
  bst->insert(5);
  bst->insert(15);
  bst->insert(16);
  bst->insert(13);
  bst->insert(12);
  bst->insert(17);
  bst->print();
    
  cout<< endl;

  bst->remove(15);
  bst->print();
  
  cout<< endl;
  
  bst->remove(10);
  bst->print();
  
  cout << endl;
/*
  bst->remove(13);
  bst->print();
*/
}
