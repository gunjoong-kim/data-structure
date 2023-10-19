#include "AVL.hpp"

size_t AVL::get_balance_factor(t_node_ptr sub_head)
{
	if (sub_head == nullptr)
		return 0;
	size_t left_h = get_height_subtree(sub_head->m_left);
	size_t right_h = get_height_subtree(sub_head->m_right);
	return left_h - right_h;
}

void AVL::rotate_ll(t_node_ptr parent)
{
	
}

void AVL::rotate_rr(t_node_ptr parent)
{

}

void AVL::rotate_lr(t_node_ptr parent)
{

}

void AVL::rotate_rl(t_node_ptr parent)
{

}

void AVL::rebalance(t_node_ptr parent)
{
	
}

void AVL::insert_node(int key)
{

}

void AVL::delete_node(int key)
{

}