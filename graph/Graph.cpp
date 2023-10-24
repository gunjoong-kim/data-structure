#include "Graph.hpp"

Graph::Graph(int size)
	: m_size(size)
	, m_edge_cnt(0)
{
	this->m_adj_mat = new int*[size];
	for (int i = 0; i < size; i++)
	{
		m_adj_mat[i] = new int[size];
		for (int j = 0; j < size; j++)
			this->m_adj_mat[i][j] = 0;
	}
}

Graph::Graph(const Graph& g)
	: m_size(g.m_size)
	, m_edge_cnt(g.m_edge_cnt)
{
	this->m_adj_mat = new int*[this->m_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_adj_mat[i] = new int[this->m_size];
		for (int j = 0; j < this->m_size; j++)
			this->m_adj_mat[i][j] = g.m_adj_mat[i][j];
	}
}

Graph::~Graph()
{
	for (int i = 0; i < this->m_size; i++)
		delete this->m_adj_mat[i];
	delete this->m_adj_mat;
}

Graph& Graph::operator=(const Graph& g)
{
	if (this == &g)
		return *this;
	if (this->m_size != g.m_size)
	{
		for (int i = 0; i < this->m_size; i++)
			delete this->m_adj_mat[i];
		delete this->m_adj_mat;
		
		this->m_size = g.m_size;
		this->m_edge_cnt = g.m_edge_cnt;
		this->m_adj_mat = new int*[this->m_size];
		for (int i = 0; i < this->m_size; i++)
			this->m_adj_mat[i] = new int[this->m_size];
	}
	for (int i = 0; i < this->m_size; i++)
	{
		for (int j = 0; j < this->m_size; j++)
			this->m_adj_mat[i][j] = g.m_adj_mat[i][j];
	}
	return *this;
}

void Graph::set_edge_from_to(int v1, int v2)
{
	if (v1 >= m_size || v2 >= m_size || v1 < 0 || v2 < 0)
	{
		std::cout << "Out of Index...\n";
		return ;
	}
	this->m_adj_mat[v1][v2] = 1;
	this->m_edge_cnt++;
}

void Graph::set_edge_from_to_value(int v1, int v2, int priority)
{
	if (v1 >= m_size || v2 >= m_size || v1 < 0 || v2 < 0)
	{
		std::cout << "Out of Index...\n";
		return ;
	}
	this->m_adj_mat[v1][v2] = priority;
	this->m_edge_cnt++;
}

void Graph::unset_edge_from_to(int v1, int v2)
{
	if (v1 >= m_size || v2 >= m_size || v1 < 0 || v2 < 0)
	{
		std::cout << "Out of Index...\n";
		return ;
	}
	this->m_adj_mat[v1][v2] = 0;
	this->m_edge_cnt--;
}

void Graph::print()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << "[ ";
		for (int j = 0; j < m_size; j++)
		{
			std::cout << this->m_adj_mat[i][j] << " "; 
		}
		std::cout << "]\n";
	}
}

int Graph::get_size()
{
	return this->m_size;
}

int Graph::get_edge_cnt()
{
	return this->m_edge_cnt;
}

int Graph::get_edge_from_to(int v1, int v2)
{
	if (v1 >= m_size || v2 >= m_size || v1 < 0 || v2 < 0)
	{
		std::cout << "Out of Index...\n";
		return -1;
	}
	return this->m_adj_mat[v1][v2];
}

int Graph::get_out_degree(int v)
{
	int cnt = 0;
	for (int i = 0; i < this->m_size; i++)
	{
		if (this->m_adj_mat[v][i] == 1)
			cnt++;
	}
	return cnt;
}