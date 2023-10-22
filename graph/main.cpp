#include "Graph.hpp"

int main()
{
	int a = 1;
	int b = 2;
	Graph g(15);
	Graph c(30);
	g.set_edge_from_to(1, 3);
	g.set_edge_from_to(14, 14);
	g.set_edge_from_to(a, b);
	g.set_edge_from_to(15, 15);
	g.print();
	g = c;
	g.print();
}