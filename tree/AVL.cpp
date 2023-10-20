#include "AVL.hpp"

size_t AVL::get_balance_factor(t_node_ptr sub_head)
{
	if (sub_head == nullptr)
		return 0;
	size_t left_h = get_height_subtree(sub_head->m_left);
	size_t right_h = get_height_subtree(sub_head->m_right);
	return left_h - right_h;
}

void AVL::rotate_ll(t_node_ptr& parent)
{
	t_node_ptr child = parent->m_left;
	parent->m_left = child->m_right;
	child->m_right = parent;
	parent = child;
}

void AVL::rotate_rr(t_node_ptr& parent)
{
	t_node_ptr child = parent->m_right;
	parent->m_right = child->m_left;
	child->m_left = parent;
	parent = child;
}

void AVL::rotate_lr(t_node_ptr& parent)
{
	rotate_rr(parent->m_left);
	rotate_ll(parent);
}

void AVL::rotate_rl(t_node_ptr& parent)
{
	rotate_ll(parent->m_right);
	rotate_rr(parent);
}

void AVL::rebalance(t_node_ptr& parent)
{
	int diff_parent = get_balance_factor(parent);
	if (abs(diff_parent) <= 1)
		return ;
	if (diff_parent < 0)
	{
		int diff_child = get_balance_factor(parent->m_right);
		if (diff_child < 0)
			rotate_rr(parent);
		else
			rotate_rl(parent);
	}
	else
	{
		int diff_child = get_balance_factor(parent->m_left->m_left);
		if (diff_child < 0)
			rotate_lr(parent);
		else
			rotate_ll(parent);
	}
}

void AVL::insert_node(int key)
{
	insert_node_recursive(this->m_head, key);
}

void AVL::insert_node_recursive(t_node_ptr& head, int key)
{
	if (head == nullptr)
	{
		t_node_ptr new_node = new t_node;
		new_node->m_key = key;
		new_node->m_left = nullptr;
		new_node->m_right = nullptr;
		head = new_node;
		return ;
	}

	if (head->m_key < key)
	{
		insert_node_recursive(head->m_right, key);
		rebalance(head);
	}
	else if (head->m_key > key)
	{
		insert_node_recursive(head->m_left, key);
		rebalance(head);
	}
	else if (head->m_key == key)
	{
		std::cout << "Duplicated key...\n";
		return ;
	}
}

void AVL::delete_node(int key)
{
	delete_node_recursive(this->m_head, key);
}

void AVL::delete_node_recursive(t_node_ptr& head, int key)
{
	if (head == nullptr)
	{
		std::cout << "No such node in this tree... key : " << key << '\n';
		return ;
	}
	else if (head->m_key > key)
	{
		delete_recursive(head->m_left, key);
		rebalance(head);
	}
	else if (head->m_key < key)
	{
		delete_recursive(head->m_right, key);
		rebalance(head);
	}
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
			copy_successor_recursive(head->m_right, head);
		}
	}
}