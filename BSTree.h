/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <climits>
#include "BTNode.h"




template <typename T>
class BSTree
{
private:
	BTNode<T>* m_root;
	BTNode<T>* m_current;
	int m_size;

	//private functions

	//Pre conditions:
	//Post conditions:
	BTNode<T>* search(T target, BTNode<T>* current);

	//Pre conditions:
	//Post conditions:
	void internalAdd(BTNode<T>* current, BTNode<T>* new_node);
	//Pre conditions: 
	//Post conditions:
	void internalRemove(BTNode<T>* target_node);
	//Pre conditions:
	//Post conditions:
	void internalRemoveAll(BTNode<T>* current);

public:
	BSTree();
	BSTree(BTNode<T>* root);
	~BSTree();

	// Query
	//Pre conditions:
	//Post conditions:
	int size() const { return m_size; }
	//Pre conditions:
	//Post conditions:
	bool empty()const;
	//Pre conditions:
	//Post conditions:
	std::ostream& display(std::ostream& out)const;
	//Pre conditions:
	//Post conditions:
	std::ostream& displayNode(BTNode<T>* current, std::ostream& out)const;

	//Pre conditions:
	//Post conditions:
	BTNode<T>* search_smallest(BTNode<T>* current);
	BTNode<T>* search_biggest(BTNode<T>* current);

	//Pre conditions:
	//Post conditions:
	//return the value stored in the current node
	T get_current();
	//Pre conditions:
	//Post conditions:
	void add(T m_data);
	//Pre conditions:
	//Post conditions:
	void remove(T m_data);

	void test();
	


};

//Pre conditions:
//Post conditions:
template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree);

#include "BSTree.hpp"
#endif
