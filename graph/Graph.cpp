#include "Graph.hpp"

Graph::Graph(size_t size)
	: m_size(size)
	, m_edge_cnt(0)
{
	this->m_adj_mat = new int*[size];
	for (size_t i = 0; i < size; i++)
	{
		m_adj_mat[i] = new int[size];
		for (size_t j = 0; j < size; j++)
			this->m_adj_mat[i][j] = 0;
	}
}

Graph::Graph(const Graph& g)
	: m_size(g.m_size)
	, m_edge_cnt(g.m_edge_cnt)
{
	this->m_adj_mat = new int*[this->m_size];
	for (size_t i = 0; i < this->m_size; i++)
	{
		this->m_adj_mat[i] = new int[this->m_size];
		for (size_t j = 0; j < this->m_size; j++)
			this->m_adj_mat[i][j] = g.m_adj_mat[i][j];
	}
}

Graph::~Graph()
{
	for (size_t i = 0; i < this->m_size; i++)
		delete this->m_adj_mat[i];
	delete this->m_adj_mat;
}

Graph& Graph::operator=(const Graph& g)
{
	if (this == &g)
		return *this;
	if (this->m_size != g.m_size)
	{
		for (size_t i = 0; i < this->m_size; i++)
			delete this->m_adj_mat[i];
		delete this->m_adj_mat;
		
		this->m_size = g.m_size;
		this->m_edge_cnt = g.m_edge_cnt;
		this->m_adj_mat = new int*[this->m_size];
		for (size_t i = 0; i < this->m_size; i++)
			this->m_adj_mat[i] = new int[this->m_size];
	}
	for (size_t i = 0; i < this->m_size; i++)
	{
		for (size_t j = 0; j < this->m_size; j++)
			this->m_adj_mat[i][j] = g.m_adj_mat[i][j];
	}
	return *this;
}

void Graph::set_edge_from_to(size_t v1, size_t v2)
{
	if (v1 >= m_size || v2 >= m_size)
	{
		std::cout << "Out of Index...\n";
		return ;
	}
	this->m_adj_mat[v1][v2] = 1;
	this->m_edge_cnt++;
}

void Graph::unset_edge_from_to(size_t v1, size_t v2)
{
	if (v1 >= m_size || v2 >= m_size)
	{
		std::cout << "Out of Index...\n";
		return ;
	}
	this->m_adj_mat[v1][v2] = 0;
	this->m_edge_cnt--;
}

void Graph::print()
{
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << "[ ";
		for (size_t j = 0; j < m_size; j++)
		{
			std::cout << this->m_adj_mat[i][j] << " "; 
		}
		std::cout << "]\n";
	}
}

size_t Graph::get_size()
{
	return this->m_size;
}

size_t Graph::get_edge_cnt()
{
	return this->m_edge_cnt;
}

int Graph::get_edge_from_to(size_t v1, size_t v2)
{
	if (v1 >= m_size || v2 >= m_size)
	{
		std::cout << "Out of Index...\n";
		return -1;
	}
	return this->m_adj_mat[v1][v2];
}