/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3: Binary Search Tree & Hashtable
 */

//constructor
template <typename T>
HTable<T>::HTable()
{
	//set all the data to NULL pointer
	for(int i = 0 ; i < 150 ; ++i)
	{
		m_data[i] = NULL;
	}
}

//destructor
template <typename T>
HTable<T>::~HTable()
{
	//delete all the data
	for(int i = 0 ; i < 150 ; ++i)
	{
		delete m_data[i];
	}
}


template <typename T>
int HTable<T>::hashFunction(T value)const
{
	return value%150;
}

template <typename T>
void HTable<T>::add(T val)
{
	//T must implement copy constructor
	int* new_value = new T(val);
	//get the hash key returned by the object to access the right case in the m_data array
	int key = hashFunction(val);
	m_data[key] = new_value;
	m_size++;
}

template <typename T>
void HTable<T>::remove(T target)
{
	if(!empty())
	{
		//get the hash key of the target
		int key = hashFunction(target);

		//if the key created by the target leads to an element in the hash table
		//i.e. the target is in the hash table already 
		if(m_data[key] != NULL)
		{
			//delete the pointer accessed with the key
			delete m_data[key];
			//put this pointer to NULL again
			m_data[key] = NULL;
			m_size--;
		}
		else
		{
			//the target is not in the hash table -> do nothing
		}

	}
	else
		std::cout << "try to remove an element from an empty tree" << std::endl;
}

template <typename T>
bool HTable<T>::empty()
{
	if(m_size == 0)
		return true;
	else
		return false;
}

template <typename T>
std::ostream& HTable<T>::display(std::ostream& out)const
{
	//a bit absurde to go through the entire array when we have a hash table...
	for(int i = 0 ; i < 150 ; ++i)
	{
		//if there's an element at the current case of the array
		if(m_data[i] != NULL)
		{
			//print it
			out << *m_data[i] << " ";
		}
	}
	return out;
}



//Non member funtions:

template<typename T>
std::ostream& operator<<(std::ostream& out, const HTable<T>& table)
{
	return table.display(out);
}