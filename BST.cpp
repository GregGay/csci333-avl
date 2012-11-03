#include "BST.h"
#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;

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
    
    if(*cur==0){ 
	  return;
    }
    
    else {
	  Node<T>* nodeToRemove = *cur;
    
	  if(nodeToRemove->getRightChild()==0 && nodeToRemove->getLeftChild()==0) {
		*cur=0;
	  }

	  else if(nodeToRemove->getLeftChild()==0) {
		*cur=(*cur)->getRightChild();
	  }
	  
	  else if(nodeToRemove->getRightChild()==0) {
		*cur=(*cur)->getLeftChild();
	  }
	  
	  else {    
		Node<T>* ios = nodeToRemove->getRightChild();
		while(ios->getLeftChild()!=0) {
		    ios=ios->getLeftChild();
		}
    
		ios->setLeftChild(*nodeToRemove->getLeftChild());
		*cur=(*cur)->getRightChild();
	  }

	  delete nodeToRemove; 
    }
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
    //std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
    //std::cout << root->getValue() << std::endl;
  }
}

template <typename T>
void BST<T>::treePrint() {
    std::list<Node<T>* > s;
    
    vector<vector<bool> > isPresent;
    vector<vector<T> > levels;
    vector<T> someRows;
    vector<bool> someOtherRow;
    levels.push_back(someRows);
    isPresent.push_back(someOtherRow);

    levels[0].push_back(root->getValue());
    isPresent[0].push_back(true);

    s.push_front(root);

    int currentLevel = 1;
    int nextLevel = 0;
    int depth = 1;

    while(!s.empty()) {
	  Node<T>* val = s.front();
	  s.pop_front();

	  currentLevel--;

	  vector<T> row;
	  vector<bool> otherRow;
	  levels.push_back(row);
	  isPresent.push_back(otherRow);

	  if(val->getLeftChild()!=0) {
		s.push_back(val->getLeftChild());
		levels[depth].push_back(val->getLeftChild()->getValue());
		isPresent[depth].push_back(true);
		nextLevel++;
	  }
	  else {
		isPresent[depth].push_back(false);
	  }
	  if(val->getRightChild()!=0) {
		s.push_back(val->getRightChild());
		levels[depth].push_back(val->getRightChild()->getValue());
		isPresent[depth].push_back(true);
		nextLevel++;
	  }
	  else {
		isPresent[depth].push_back(false);
	  }
	  if(currentLevel==0) {
		depth++;
		currentLevel = nextLevel;
		nextLevel = 0;
	  }
    }

    int width;
    for(int i = 0; i < depth; i++) {
	  width = pow(1.625, depth-i-1);
	  if(isPresent[i][0]) {
		cout << std::setw(width) << levels[i][0];
	  }
	  else {
		cout << std::setw(width) << " ";
	  }

	  for(int j = 1; j < (int)levels[i].size(); j++) {
		if(isPresent[i][j]) {
		    cout << std::setw(pow(1.75, depth-i-1)) << std::setfill(' ') << levels[i][j];
		}
		else {
		    cout << std::setw(pow(1.75, depth-i-1)) << std::setfill(' ') << " ";
		}
        }
	  cout << endl;
    }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
