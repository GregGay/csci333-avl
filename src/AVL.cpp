#include "AVL.h"
#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;

template <typename T>
AVL<T>::AVL() {
  root = 0;
}

template <typename T>
AVL<T>::~AVL() {
  
}

template <typename T>
bool AVL<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void AVL<T>::insert(T v) {
    Node<T>* temp = new Node<T>(v);
    Node<T>** cn = 0;
    Node<T>** curr = &root;
    bool critNodeFound = false;

    while (*curr != 0) {
	  if ((*curr)->getBalance() != 0) {
		cn = curr;
		critNodeFound = true;	
	  }

	  if (v < (*curr)->getValue()) {
		if ((*curr)->getBalance() == 1 || (*curr)->getBalance() == -1) {
		    cn = curr;
		}
		curr=&((*curr)->getLeftChild());
	  }

	  else if (v > (*curr)->getValue()) {
		if ((*curr)->getBalance() == 1 || (*curr)->getBalance() == -1) {
		    cn=curr;
		}
		curr=&((*curr)->getRightChild());
	  }
    }
    *curr = temp;
  
    Node<T>** R;
    Node<T>** C = 0;
    Node<T>** B = 0;
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;

    if (!critNodeFound) {
	  R = &root;
    }

    else {
	  if (v < (*cn)->getValue()) {
		d1 = -1;
		C = &((*cn)->getLeftChild());
	  }
	  else if (v > (*cn)->getValue()) {
		d1 = 1;
		C = &((*cn)->getRightChild());
	  }

	  if((*cn)->getBalance()!=d1) {
		(*cn)->setBalance(0);
		R = curr;
	  }

	  else {
		if (v < (*C)->getValue()) {
		    d2 = -1;
		    B = &((*C)->getLeftChild());
		}
		else if (v > (*C)->getValue()) {
		    d2 = 1;
		    B = &((*C)->getRightChild());
		}

		if(d2 == d1) {
		    (*cn)->setBalance(0);
		    R = B;
		    if (d1 == -1) {
			  rotateRight(cn);
		    }
		    else if (d1 == 1) {
			  rotateLeft(cn);
		    }
		}

		else {
		    if (v < (*B)->getValue()) {
			  d3 = -1;
			  R = &((*B)->getLeftChild());
		    }
		    else if (v > (*B)->getValue()) {
			  d3 = 1;
			  R = &((*B)->getRightChild());
		    }

		    if (d3 == d2) {
			  (*cn)->setBalance(0);
			  (*C)->setBalance(d1);
		    }
		    else if (d3 == -d2) {
			  (*cn)->setBalance(d2);
		    }
		    else {
			  (*cn)->setBalance(0);
		    }

		    if (d2==1) {
			  rotateLeft(C);
		    }
		    else if (d2==-1) {
			  rotateRight(C);
		    }
		    if (d1==1) {
			  rotateLeft(cn);
		    }
		    else if (d1==-1) {
			  rotateRight(cn);
		    }
		}
	  }
    }

    int d = 0;
    while ((*R) != 0 && (*R)->getValue() != v) {
	  if (v < (*R)->getValue()) {
		d = -1;
		(*R)->setBalance(-1);
		R = &((*R)->getLeftChild());
	  }
	  else if (v > (*R)->getValue()) {
		d = 1;
		(*R)->setBalance(1);
		R = &((*R)->getRightChild());
	  }
    }
}

template <typename T>
void AVL<T>::rotateLeft(Node<T>** cn) {
	  Node<T>* tempRightChild = *cn;
	  Node<T>* tempLeftChild = tempRightChild->getLeftChild();
	  *cn = tempRightChild->getRightChild();
	  (*cn)->setLeftChild(*tempRightChild);
	  tempRightChild->setRightChild(*tempLeftChild);
}

template <typename T>
void AVL<T>::rotateRight(Node<T>** cn) {
	  Node<T>* tempLeftChild = *cn;
	  Node<T>* tempRightChild = tempLeftChild->getRightChild();
	  *cn = tempLeftChild->getLeftChild();
	  (*cn)->setRightChild(*tempLeftChild);
	  tempLeftChild->setLeftChild(*tempRightChild);
}

template <typename T>
void AVL<T>::remove(T v) {
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
void AVL<T>::inOrderTraversal() {
  inOrderTraversalPrint(root);
}

template <typename T>
void AVL<T>::inOrderTraversalPrint(Node<T>* root) {
  if(root != 0) {
    inOrderTraversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    inOrderTraversalPrint(root->getRightChild());
  }
}

template <typename T>
void AVL<T>::postOrderTraversal() {
  postTraversalPrint(root);
}

template <typename T>
void AVL<T>::postTraversalPrint(Node<T>* root) {
  if(root != 0) {
    postTraversalPrint(root->getLeftChild());
    postTraversalPrint(root->getRightChild());
    std::cout << root->getValue() << std::endl;
  }
}

template <typename T>
void AVL<T>::print() {
  traversalPrint(root);
}

template <typename T>
void AVL<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    //std::cout << root->getBalance() << std::endl;
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getLeftChild());
    //std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
    //std::cout << root->getValue() << std::endl;
  }
}

template <typename T>
void AVL<T>::treePrint() {
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

	  for(int j = 0; j < (int)levels[i].size(); j++) {
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

template class AVL<int>;
template class AVL<double>;
template class AVL<std::string>;
