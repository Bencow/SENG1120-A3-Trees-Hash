/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */

#ifndef HTABLE_H
#define HTABLE_H


#include <iostream>


template <typename T>
class HTable
{
private:
	//Array storing the data
	T* m_data[150];
	//number of elements in the hash table
	int m_size;


public:
	HTable();
	~HTable();

	//Pre conditions: T has to be a numeric type
	//Post conditions:
	int hashFunction(T val)const;
	void add(T val);
	void remove(T target);
	std::ostream& display(std::ostream& out)const;
	
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const HTable<T>& table);


#include "HTable.hpp"

#endif
