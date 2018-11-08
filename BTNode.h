/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */

#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>

template <typename T>
class BTNode
{
private:
	T m_data;
	BTNode<T>* m_left;
	BTNode<T>* m_right;
	BTNode<T>* m_parent;

public:
	BTNode();
	BTNode(const T& data);
	BTNode(const T& data, BTNode<T>* parent);
	// BTNode(const T& data, BTNode<T>* left, BTNode<T>* right);
	~BTNode();

	// Mutators
	//Pre conditions: none
	//Post conditions: copy the value passed as reference in the Node
	void set_data(const T& val){ m_data = val; }

	//Pre conditions: none
	//Post conditions: set parent pointer to val
	void set_parent(BTNode<T>* val){ m_parent = val; }

	//Pre conditions: none
	//Post conditions: set left pointer to val
	void set_left(BTNode<T>* val){ m_left = val; }

	//Pre conditions: none
	//Post conditions: set right pointer to val
	void set_right(BTNode<T>* val){ m_right = val; }


	// Query
	//Pre conditions: none
	//Post conditions: return a copy of the data (nor a reference)
	T get_data() const { return m_data; }

	//Pre conditions: none
	//Post conditions: return pointer to parent
	BTNode<T>* get_parent(){ return m_parent; }

	//Pre conditions: none
	//Post conditions: return pointer to right child
	BTNode<T>* get_right(){ return m_right; }

	//Pre conditions: none
	//Post conditions: return pointer to left child
	BTNode<T>* get_left(){ return m_left; }
	
	//Pre conditions: none
	//Post conditions: return true if m_left and m_right are both pointing to NULL
	bool is_a_leaf()const;


};

#include "BTNode.hpp"


#endif
