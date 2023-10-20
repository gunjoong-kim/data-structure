#pragma once
#ifndef NODE_HPP
#define NODE_HPP

class Node
{
private:
	int m_key;
	Node *m_left;
	Node *m_right;
	Node() {}

public:
	Node(int key);
	Node(const Node& node);
	~Node() {}
	Node& operator=(const Node& node);

	void set_left(Node* left);
	void set_right(Node* right);
	void set_key(int key);
};

typedef Node* t_node_ptr;

#endif