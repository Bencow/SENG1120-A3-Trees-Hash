/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */

#ifndef HTABLE_H
#define HTABLE_H


#include <iostream>




//Note on the typedef : T has to be a numeric type
//or at least, it must implement operator %
template <typename T>
class HTable
{
private:
	//Array storing pointer to the data
	T* m_data[150];
	//number of elements in the hash table
	int m_size;


public:
	HTable();
	~HTable();

	//Pre conditions: T must implement operator %
	//Post conditions: return the hash key of the input
	int hashFunction(T val)const;

	//Pre conditions: T must implement operator % and have a copy constructor
	//Post conditions: allocate a copy of the val object and make m_data[key] points to it
	void add(T val);

	//Pre conditions:T must implement operator %
	//Post conditions: if the target is in the has table, remove it
	void remove(T target);

	//Pre conditions: none
	//Post conditions: return true if HTable has no element
	bool empty();

	//Pre conditions: T must implement operator <<
	//Post conditions: display all the elements in the hash table
	std::ostream& display(std::ostream& out)const;
	
};

//Pre conditions: T must implement operator <<
//Post conditions: call HTable<T>::display()
template<typename T>
std::ostream& operator<<(std::ostream& out, const HTable<T>& table);


#include "HTable.hpp"

#endif
