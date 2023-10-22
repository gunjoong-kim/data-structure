#ifndef BST_HPP
#define BST_HPP

#pragma once

#include <iostream>

typedef struct s_node
{
	int m_key;
	int color;
	struct s_node* m_left;
	struct s_node* m_right;
}	t_node;

typedef t_node* t_node_ptr;

class BST
{
protected:
	t_node_ptr m_head;

protected:	
	t_node_ptr search_recursive(t_node_ptr head, int key);
	t_node_ptr copy_recursive(t_node_ptr t);
	void insert_recursive(t_node_ptr& head, int key);
	void delete_recursive(t_node_ptr& head, int key);
	void clear_recursive(t_node_ptr head);
	void copy_successor_recursive(t_node_ptr& successor, t_node_ptr target);
	void print_tree_inorder(t_node_ptr head);
	size_t get_height_subtree(t_node_ptr sub_head);

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
	size_t get_height();
};

#endif