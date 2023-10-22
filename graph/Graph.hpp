#pragma once 
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

class Graph
{
private:
	size_t m_size;
	int **m_adj_mat;
	size_t m_edge_cnt;
	Graph() {}

public:
	Graph(size_t size);
	Graph(const Graph& g);
	~Graph();
	Graph& operator=(const Graph& g);
	void set_edge_from_to(size_t v1, size_t v2);
	void unset_edge_from_to(size_t v1, size_t v2);
	void print();
	size_t get_size();
	size_t get_edge_cnt();
	int get_edge_from_to(size_t v1, size_t v2);
};

#endif
