#pragma once 
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

class Graph
{
private:
	int m_size;
	int **m_adj_mat;
	int m_edge_cnt;
	Graph() {}

public:
	Graph(int size);
	Graph(const Graph& g);
	~Graph();
	Graph& operator=(const Graph& g);
	void set_edge_from_to(int v1, int v2);
	void set_edge_from_to_value(int v1, int v2, int priority);
	void unset_edge_from_to(int v1, int v2);
	void print();
	int get_size();
	int get_edge_cnt();
	int get_edge_from_to(int v1, int v2);
	int get_out_degree(int v);
};

#endif
