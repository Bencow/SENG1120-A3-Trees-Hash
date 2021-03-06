/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */


template<typename T>
BTNode<T>::BTNode()
{
	m_left = NULL;
	m_right = NULL;
	m_parent = NULL;
}

template<typename T>
BTNode<T>::BTNode(const T& data)
{
	m_data = data;
	m_left = NULL;
	m_right = NULL;
	m_parent = NULL;
}

template<typename T>
BTNode<T>::BTNode(const T& data, BTNode<T>* parent)
{
	m_data = data;
	m_left = NULL;
	m_right = NULL;
	m_parent = parent;
}

//destructor
template<typename T>
BTNode<T>::~BTNode()
{}

template<typename T>
bool BTNode<T>::is_a_leaf()const
{
	//if both children pointers are NULL
	if(m_right == NULL && m_left == NULL)
		return true;//the node is a leaf
	else
		return false;
}