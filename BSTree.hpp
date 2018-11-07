/*
 * Author: Benoit Coville
 * student number: c3316165
 * Course: SENG1120 Data Structures 
 * Assignment 3; Binary Search Tree & Hashtable
 */

template <typename T>
BSTree<T>::BSTree()
{
	m_root = NULL;
	m_size = 0;
}

template <typename T>
BSTree<T>::BSTree(BTNode<T>* root)
{
	m_root = root;
	m_size = 1;
}

template <typename T>
BSTree<T>::~BSTree()
{
	if(!empty())
	{
		//start recursive call to remove all the nodes
		internalRemoveAll(m_root);
	}
}

template <typename T>
void BSTree<T>::internalRemoveAll(BTNode<T>* current)
{
	//post order implementation !

	//if there is a left child, remove it
	if(current->get_left() != NULL)
		internalRemoveAll(current->get_left());
	//if there is a right child, remove it
	if(current->get_right() != NULL)
		internalRemoveAll(current->get_right());
	//then remove the current node
	delete current;
}


template <typename T>
void BSTree<T>::remove(T target)
{
	if(!empty())
	{
		BTNode<T>* target_node = search(target, m_root);

		if(target_node == NULL)
		{
			// std::cout << target << " is not in the tree" << std::endl;
		}
		else
		{
			//if this element has no children
			if(target_node->is_a_leaf())//WORKS
			{
				// get a pointer to its parent
				BTNode<T>* parent = target_node->get_parent();
				//if target_node is the left children of the parent
				if(parent->get_left() == target_node)
					parent->set_left(NULL);//reset parent's left
				else if(parent->get_right() == target_node)
					parent->set_right(NULL);//reset parent's right
				//and delete this element
				delete target_node;
			}
			else//this element has at least one child
				internalRemove(target_node);
		}
	}
	else
		std::cout << "Error, try to remove a node from an empty tree" << std::endl;
}


//this function manage the case where we have to remove a node with children
//we don't actually remove the node, we find the smallest value on the right (if it has a right child) or vice-versa (left) 
//and put this value in the "removed" node
template <typename T>
void BSTree<T>::internalRemove(BTNode<T>* target_node)
{
	BTNode<T>* extreme;

	if(target_node->get_right() != NULL)
	{
		// std::cout << "hey" << std::endl;
		//find the smallest element on the right of the target node
		extreme = search_smallest(target_node->get_right());//return the good value///////////////////////////////////////////////////////////////
		//put the value of smallest in the target
		target_node->set_data(extreme->get_data());
	}
	//else to avoid doing it 2 times, there is a if but we must enter this condition if we don't enter the first one
	else if(target_node->get_left() != NULL)
	{
		//find the smallest element on the right of the target node
		extreme = search_biggest(target_node->get_left());
		//put the value of smallest in the target
		target_node->set_data(extreme->get_data());
	}

	if(extreme->is_a_leaf())
	{
		// std::cout << "OUI ! " << std::endl;
		//remove extreme
		// get a pointer to its parent
		BTNode<T>* parent = extreme->get_parent();

		//if extreme is the left children of the parent
		if(parent->get_left() == extreme)
			parent->set_left(NULL);//reset parent's left
		else if(parent->get_right() == extreme)
			parent->set_right(NULL);//reset parent's right

		//and delete this element
		delete extreme;
	}
	else//rebelote
		internalRemove(extreme);
}

//Since all the elements on the left on a given element are lower than it, we just have to get the most left element
template <typename T>
BTNode<T>* BSTree<T>::search_smallest(BTNode<T>* current)
{
	if(current->get_left() != NULL)
		return search_smallest(current->get_left());
	else
	{
		return current;
	}
}

template <typename T>
BTNode<T>* BSTree<T>::search_biggest(BTNode<T>* current)
{
	if(current->get_right() != NULL)
		return search_biggest(current->get_right());
	else
		return current;
}

template <typename T>
BTNode<T>* BSTree<T>::search(T target, BTNode<T>* current)
{
	BTNode<T>* result;
	//if the current node is the one we're looking for
	if(current->get_data() == target)
	{
		return current;
	}
	else//current is not the one
	{
		if(current->is_a_leaf())
		{
			return NULL;
		}
		//if the node has a left child
		if(current->get_left() != NULL)
		{
			//check if the child or one of its children are the target 
			result = search(target, current->get_left());
			//if the child (or one of its children) is the target
			if(result != NULL)
				return result;
			else//the child hasn't find anything (returned NULL)
			{
				//try the left side
				//if the node has a right child
				if(current->get_right() != NULL)
				{
					//check if the child or one of its children are the target 
					result = search(target, current->get_right());
					//if the child (or one of its children) is the target
					if(result != NULL)
						return result;
					else//the target is not one of the child of the current node
					{
						//Both children returned NULL, so return NULL
						return NULL;
					}
				}
				else//if the left has returned NULL and there's no right child
					return NULL;
			}
		}
		//if the node has a right child
		if(current->get_right() != NULL)
		{
			//check if the child or one of its children are the target 
			result = search(target, current->get_right());
			//if the child (or one of its children) is the target
			if(result != NULL)
				return result;
			else
				return NULL;
		}
		return NULL;
	}

}




template <typename T>
void BSTree<T>::add(T val)
{
	//allocate a new node
	BTNode<T>* new_node = new BTNode<T>(val);

	//if the tree is empty
	if(empty())
	{
		//put the new node in root position
		m_root = new_node;
	}
	else//tree has at least one element
	{
		//start the recursive call
		internalAdd(m_root, new_node);
	}
	m_size++;
}

template <typename T>
void BSTree<T>::internalAdd(BTNode<T>* current, BTNode<T>* new_node)
{
	//if the value to insert is greater than the current node
	if(new_node->get_data() > current->get_data())
	{
		if(current->get_right() == NULL)
		{
			//create a new node with val and the current node as parent
			new_node->set_parent(current);
			//insert the new node here
			current->set_right(new_node);
		}
		else
			internalAdd(current->get_right(), new_node);
	}
	else//the value is lower or equal to the current node
	{
		if(current->get_left() == NULL)
		{
			//create a new node with val and the current node as parent
			new_node->set_parent(current);
			//insert the new node here
			current->set_left(new_node);
		}
		else
			internalAdd(current->get_left(), new_node);
	}
}



template <typename T>
bool BSTree<T>::empty()const
{
	if(m_root == NULL)
		return true;
	else
		return false;
}


template <typename T>
std::ostream& BSTree<T>::display(std::ostream& out)const
{
	if(m_root == NULL)
	{
		out << "the tree is empty" << std::endl;
		return out;
	}
	else
	{
		return displayNode(m_root, out);
	}
}


template <typename T>
std::ostream& BSTree<T>::displayNode(BTNode<T>* current, std::ostream& out)const
{
	
	//current node has 2 children
	if(current->get_left() != NULL && current->get_right() != NULL)
	{
		displayNode(current->get_left(), out);
		out << current->get_data() << " ";
		displayNode(current->get_right(), out);
	}
	//current node has 1 child on the right
	else if(current->get_left() == NULL && current->get_right() != NULL)
	{
		out << current->get_data() <<  " ";
		displayNode(current->get_right(), out);
	}

	//current node has 1 child on the left
	else if(current->get_left() != NULL && current->get_right() == NULL)
	{
		displayNode(current->get_left(), out);
		out << current->get_data() <<  " ";
	}
	//the current node has no children
	else if(current->get_left() == NULL && current->get_right() == NULL)
		out << current->get_data() <<  " ";
	return out;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
	return tree.display(out);
}


template <typename T>
void BSTree<T>::test()
{
	std::cout << search_smallest(m_root)->get_data() << std::endl;
	std::cout << search_biggest(m_root)->get_data() << std::endl;
}
