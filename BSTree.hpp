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
		//internalRemove(target_node);
	}
	else
		std::cout << "Error, try to remove a node from an empty tree" << std::endl;
}



template <typename T>
void BSTree<T>::internalRemove(BTNode<T>* current, T target)
{
	//find the smallest element on the right of the target node
	BTNode<T>* smallest = search_smallest_right(current);
	//put the value of smallest in the target
	current->set_data(smallest->get_data());

	//if this element has no children
	if(smallest->is_a_leaf())
	{
		// get a pointer to its parent
		BTNode<T>* parent = smallest->get_parent();
		//if smallest is the left children of the parent
		if(parent->get_left() == smallest)
			parent->set_left(NULL);//reset parent's left
		else if(parent->get_right() == smallest)
			parent->set_right(NULL);//reset parent's right

		//and delete the children
		delete smallest;
	}
	//the current element has at least one children
	else
		internalRemove(smallest);//recursive call (find the smallest element on the right of this node and remove it)
}

template <typename T>
BTNode<T>* BSTree<T>::search(T target, BTNode<T>* current)
{
	BTNode<T>* result;
	//if the current node is the one we're looking for
	if(current->get_data() == target)
	{
		std::cout << current->get_data() << " trouvé ! parent is "; 
		//std::cout << current->get_parent()->get_data() << std::endl;
		return current;
	}
	else//current is not the one
	{
		if(current->get_left() != NULL)
		{
			result = search(target, current->get_left());
			if(result != NULL)
				return result;
		}
		if(current->get_right() != NULL)
		{
			result = search(target, current->get_right());
			if(result != NULL)
				return result;
		}
		return NULL;
	}

}


template <typename T>
BTNode<T>* BSTree<T>::search_smallest_right(BTNode<T>* current)
{

}


template <typename T>
void BSTree<T>::add(T val)
{
	//allocate a new node
	BTNode<T>* new_node = new BTNode<T>(val);
	std::cout << "new node: " << new_node->get_data() << std::endl;

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
			std::cout << new_node->get_parent()->get_data() << std::endl;//FAIT PLANTEY
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

			std::cout << new_node->get_parent()->get_data() << std::endl;//FAIT PLANTEY
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
	/*
	//current node has 2 children
	if(current->get_left() != NULL && current->get_right() != NULL)
	{
		displayNode(current->get_left(), out);
		out << current->get_data() << " (" << current->get_parent()->get_data() << ") ";
		displayNode(current->get_right(), out);
	}
	//current node has 1 child on the right
	else if(current->get_left() == NULL && current->get_right() != NULL)
	{
		out << current->get_data() <<  " (" << current->get_parent()->get_data() << ") ";
		displayNode(current->get_right(), out);
	}

	//current node has 1 child on the left
	else if(current->get_left() != NULL && current->get_right() == NULL)
	{
		displayNode(current->get_left(), out);
		out << current->get_data() <<  " (" << current->get_parent()->get_data() << ") ";
	}
	//the current node has no children
	else if(current->get_left() == NULL && current->get_right() == NULL)
		out << current->get_data() <<  " (" << current->get_parent()->get_data() << ") ";
*/
	return out;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
	return tree.display(out);
}

