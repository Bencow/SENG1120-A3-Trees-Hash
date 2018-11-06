/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3; Binary Search Tree & Hashtable
 */

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

#include "BTNode.h"




template <typename T>
class BSTree
{
private:
	BTNode<T>* m_root;
	BTNode<T>* m_current;
	int m_size;

	//private functions
	BTNode<T>* search(T target);
	void internalAdd(BTNode<T>* current, T val);
	void internalRemove(BTNode<T>* current, T target);
	void internalRemoveAll(BTNode<T>* current);

public:
	BSTree();
	BSTree(BTNode<T>* root);
	~BSTree();

	// Query
	int size() const { return m_size; }
	bool empty()const;
	std::ostream& display(std::ostream& out)const;
	std::ostream& displayNode(BTNode<T>* current, std::ostream& out)const;

	//return the value stored in the current node
	T get_current();
	void add(T m_data);
	void remove(T m_data);
	


};

template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree);

#include "BSTree.hpp"
#endif
