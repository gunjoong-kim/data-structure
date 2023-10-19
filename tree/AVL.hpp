#pragma once
#ifndef AVL_HPP
#define AVH_HPP

#include "BST.hpp"

class AVL : public BST
{
	private:
		size_t get_balance_factor(t_node_ptr sub_head);
		void rotate_ll(t_node_ptr parent);
		void rotate_rr(t_node_ptr parent);
		void rotate_lr(t_node_ptr parent);
		void rotate_rl(t_node_ptr parent);
		void rebalance(t_node_ptr parent);

	public:
		AVL() : BST() {}
		AVL(const AVL& avl) : BST(avl) {}
		virtual ~AVL() {}
		virtual void insert_node(int key);
		virtual void delete_node(int key);
};

#endif