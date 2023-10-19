#include "BST.hpp"

BST::BST()
	: m_head(nullptr)
	{}

BST::BST(const BST& bt)
{
	this->m_head = copy_recursive(bt.m_head);
}

BST::~BST()
{
	clear_recursive(this->m_head);
}

BST& BST::operator=(const BST& bt)
{
	if (this == &bt)
		return *this;
	clear_recursive(this->m_head);
	this->m_head = copy_recursive(bt.m_head);
	return *this;
}

void BST::clear_tree()
{
	clear_recursive(this->m_head);
	this->m_head = nullptr;
}

void BST::clear_recursive(t_node_ptr start)
{
	if (start == nullptr)
		return ;
	clear_recursive(start->m_left);
	clear_recursive(start->m_right);
	delete(start);
}

BST::t_node_ptr BST::copy_recursive(t_node_ptr t)
{
	if (t == nullptr)
		return nullptr;
	t_node_ptr new_tree = new t_node;
	new_tree->m_key = t->m_key;
	new_tree->m_left = copy_recursive(t->m_left);
	new_tree->m_right = copy_recursive(t->m_right);
	return new_tree;
}

BST::t_node_ptr BST::search_tree(int key)
{
	return search_recursive(this->m_head, key);
}

BST::t_node_ptr BST::search_recursive(t_node_ptr head, int key)
{
	if (head == nullptr)
	{
		std::cout << "No such node in this tree... key : " << key << '\n';
		return nullptr;
	}
	else if (head->m_key == key)
		return head;
	else if (head->m_key > key)
		return search_recursive(head->m_left, key);
	else if (head->m_key < key)
		return search_recursive(head->m_right, key);
	return nullptr;
}

void BST::insert_node(int key)
{
	insert_recursive(this->m_head, key);
}

void BST::insert_recursive(t_node_ptr &head, int key)
{
	if (head == nullptr)
	{
		head = new t_node;
		head->m_key = key;
		head->m_left = nullptr;
		head->m_right = nullptr;
		return ;
	}
	else if (head->m_key == key)
	{
		std::cout << "Duplicated key...\n";
		return ;
	}
	else if (head->m_key > key)
		insert_recursive(head->m_left, key);
	else if (head->m_key < key)
		insert_recursive(head->m_right, key);
}

void BST::delete_node(int key)
{
	delete_recursive(this->m_head, key);
}

void BST::delete_recursive(t_node_ptr& head, int key)
{
	//delete member function
	// There are 3 cases in this function
	// 1. terminal -> just cut
	// 2. has a one child -> link child to parent
	// 3. has two child
	// 왼쪽 자식중 가장 큰 값을 삭제하려는 노드로 바꾼다.
	// 오른쪽 자식중 가장 작은 값을 삭제하려는 노드로 바꾼다.
	if (head == nullptr)
	{
		std::cout << "No such node in this tree... key : " << key << '\n';
		return ;
	}
	else if (head->m_key > key)
		delete_recursive(head->m_left, key);
	else if (head->m_key < key)
		delete_recursive(head->m_right, key);
	else if (head->m_key == key)
	{
		if (head->m_left == nullptr && head->m_right == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else if (head->m_left == nullptr)
		{
			t_node_ptr tmp = head;
			head = head->m_right;
			delete tmp;
		}
		else if (head->m_right == nullptr)
		{
			t_node_ptr tmp = head;
			head = head->m_left;
			delete tmp;
		}
		else
		{
			copy_successor_recursive(head, head);
		}
	}

}

void BST::copy_successor_recursive(t_node_ptr& successor, t_node_ptr target)
{
	if (successor->m_left == nullptr)
	{
		target->m_key = successor->m_key;
		t_node_ptr tmp = successor;
		successor = successor->m_right;
		delete tmp;
	}
	else
	{
		copy_successor_recursive(successor->m_left, target);
	}
}

void BST::print_tree()
{
	std::cout << "tree display\n";
	print_tree_inorder(this->m_head);
}

void BST::print_tree_inorder(t_node_ptr head)
{
	if (head == nullptr)
		return ;
	print_tree_inorder(head->m_left);
	std::cout << head->m_key << '\n';
	print_tree_inorder(head->m_right);
}

size_t BST::get_height_subtree(t_node_ptr sub_head)
{
	if (sub_head == nullptr)
		return 0;
	size_t left_h = 1 + get_height_subtree(sub_head->m_left);
	size_t right_h = 1 + get_height_subtree(sub_head->m_right);
	return std::max(left_h, right_h);
}

size_t BST::get_height()
{
	return get_height_subtree(this->m_head);
}
