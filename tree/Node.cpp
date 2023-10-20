#include "Node.hpp"

Node::Node(int key)
	: m_key(key)
	, m_left(nullptr)
	, m_right(nullptr)
	{}

Node::Node(const Node& node)
	: m_key(node.m_key)
	, m_left(nullptr)
	, m_right(nullptr)
	{}

Node& Node::operator=(const Node& node)
{
	this->m_key = node.m_key;
	return *this;
}

void Node::set_left(Node* left)
{
	this->m_left = left;
}

void Node::set_right(Node* right)
{
	this->m_right = right;
}

void Node::set_key(int key)
{
	this->m_key = key;
}