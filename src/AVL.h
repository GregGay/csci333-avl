#ifndef __AVL_H__
#define __AVL_H__

#include "Node.h"
#include <string>

template <typename T>
class AVL {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);
  void inOrderTraversalPrint(Node<T>* root);
  void postTraversalPrint(Node<T>* root);

 public:
  AVL<T>();
  ~AVL<T>();

  bool find(T v);
  void insert(T v);
  void rotateLeft(Node<T>** cn);
  void rotateRight(Node<T>** cn);
  void remove(T v);
  void inOrderTraversal();
  void postOrderTraversal();
  void print();
  void treePrint();
};

#endif
