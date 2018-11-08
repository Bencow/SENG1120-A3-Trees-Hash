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
	//pointer to the first node of the tree
	BTNode<T>* m_root;
	//number of elements in the tree
	int m_size;

	//private functions:

	//recursive function
	//Pre conditions: the value you're looking for and a valid node of the tree (first call with the root)
	//Post conditions: if the object has been found, return a pointer to the node, else return false
	BTNode<T>* search(T target, BTNode<T>* current);

	//recursive function
	//Pre conditions:
	//Post conditions:
	BTNode<T>* search_smallest(BTNode<T>* current);
	
	//recursive function
	//Pre conditions:
	//Post conditions:
	BTNode<T>* search_biggest(BTNode<T>* current);

	//recursive function
	//Pre conditions:
	//Post conditions:
	void internalAdd(BTNode<T>* current, BTNode<T>* new_node);

	//recursive function
	//Pre conditions: 
	//Post conditions:
	void internalRemove(BTNode<T>* target_node);

	//recursive function
	//Pre conditions:
	//Post conditions:
	void internalRemoveAll(BTNode<T>* current);

	//recursive function
	//Pre conditions:
	//Post conditions:
	std::ostream& displayNode(BTNode<T>* current, std::ostream& out)const;

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
	//Pre conditions: the tree is not empty
	//Post conditions: display all the nodes from the lowest to the greatest
	std::ostream& display(std::ostream& out)const;




	//Pre conditions:
	//Post conditions:
	//return the value stored in the current node
	T get_current();

	//Pre conditions: none
	//Post conditions: allocate a new node with the value and add this node at the right position in the tree
	void add(T val);

	//Pre conditions: the tree is not empty
	//Post conditions: if a node in a tree contains this value remove the node
	void remove(T m_data);
	


};

//Pre conditions: none
//Post conditions: call BSTree<T>::display
template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree);

#include "BSTree.hpp"
#endif
