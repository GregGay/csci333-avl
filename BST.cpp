#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
    Node<T>** cur=&root;
    while(*cur != 0 && (*cur)->getValue() != v){
	  if (v < (*cur)->getValue()) {
		cur=&((*cur)->getLeftChild());
	  }
	  else {
		cur=&((*cur)->getRightChild());
	  }
    }
    if(*cur==0) return;

    Node<T>* nodeToRemove = *cur;

    if(nodeToRemove->getRightChild()==0 || nodeToRemove->getLeftChild()==0){
	  cur=&((*cur)->getLeftChild());
	  delete nodeToRemove;
    }
    
    //Node<T>** iop = (*cur)->getLeftChild();
    Node<T>* ios = (*cur)->getRightChild();
    while(ios->getLeftChild()!=0) {
	  ios=ios->getLeftChild();
    }
    ios->setLeftChild(*nodeToRemove->getLeftChild());
    *cur=ios;
    delete nodeToRemove;
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getLeftChild());
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
//template class BST<std::string>;
