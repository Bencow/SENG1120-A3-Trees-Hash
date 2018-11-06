/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3; Binary Search Tree & Hashtable
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
	BTNode(const T& data, BTNode<T>* left, BTNode<T>* right);
	~BTNode();

	// Mutators
	void set_data(const T& val){ m_data = val; }
	void set_parent(BTNode<T>* val){ m_parent = val; }
	void set_left(BTNode<T>* val){ m_left = val; }
	void set_right(BTNode<T>* val){ m_right = val; }
	// Query
	T get_data() const { return m_data; }
	BTNode<T>* get_parent(){ return m_parent; }
	BTNode<T>* get_right(){ return m_right; }
	BTNode<T>* get_left(){ return m_left; }


};

#include "BTNode.hpp"


#endif
