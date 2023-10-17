#ifndef BST_HPP
#define BST_HPP

#pragma once

#include <iostream>

class BST
{
	typedef struct s_node
	{
		int m_key;
		struct s_node* m_left;
		struct s_node* m_right;
	} t_node;

	typedef t_node* t_node_ptr;

	private:
		t_node_ptr m_head;

	private:	
		t_node_ptr search_recursive(t_node_ptr head, int key);
		t_node_ptr copy_recursive(t_node_ptr t);
		void insert_recursive(t_node_ptr& head, int key);
		void delete_recursive(t_node_ptr& head, int key);
		void copy_successor_recursive(t_node_ptr& successor, t_node_ptr target);
		void print_tree_inorder(t_node_ptr head);

	public:
		BST();
		BST(const BST& bt);
		virtual ~BST();
		BST& operator=(const BST& bt);
		void clear_tree();
		t_node_ptr search_tree(int key);
		virtual void insert_node(int key);
		virtual void delete_node(int key);
		void print_tree();

	// static functions
	public:
		static void clear_recursive(t_node_ptr head);
};

#endif