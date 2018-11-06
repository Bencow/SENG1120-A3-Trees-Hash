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
		internalAdd(m_root, val);
	}
	m_size++;
}

template <typename T>
BSTree<T>::~BSTree()
{

}



template <typename T>
void BSTree<T>::internalAdd(BTNode<T>* current, T val)
{
	//if the value to insert is greater than the current node
	if(val > current->get_data())
	{
		if(current->get_right() == NULL)
		{
			//create a new node with val and the current node as parent
			BTNode<T>* new_node = new BTNode<T>(val, current);
			//insert the new node here
			current->set_right(new_node);
		}
		else
			internalAdd(current->get_right(), val);
	}
	else//the value is lower or equal to the current node
	{
		if(current->get_left() == NULL)
		{
			//create a new node with val and the current node as parent
			BTNode<T>* new_node = new BTNode<T>(val, current);
			//insert the new node here
			current->set_left(new_node);
		}
		else
			internalAdd(current->get_left(), val);
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
BTNode<T>* BSTree<T>::search(T target)
{
	//if the tree is empty, return NULL
	if(empty())
		return NULL;
	else
	{
		

	}
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
		out << current->get_data() << " ";
		displayNode(current->get_right(), out);
	}

	//current node has 1 child on the left
	else if(current->get_left() != NULL && current->get_right() == NULL)
	{
		displayNode(current->get_left(), out);
		out << current->get_data() << " ";
	}
	//the current node has no children
	else if(current->get_left() == NULL && current->get_right() == NULL)
		out << current->get_data() << " ";

	return out;
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const BSTree<T>& tree)
{
	return tree.display(out);
}