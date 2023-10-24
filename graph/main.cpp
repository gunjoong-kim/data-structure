#include "Graph.hpp"
#include <queue>

void dfs(Graph& g, int start, std::vector<int>& visited)
{
	visited[start] = 1;
	std::cout << "DFS visit node : " << start << std::endl;
	for (int i = 0; i < g.get_size(); i++)
	{
		if (i == start)
			continue;
		if (g.get_edge_from_to(start, i) == 1 && visited[i] == 0)
			dfs(g, i, visited);
	}
}

void bfs(Graph& g, int start)
{
	std::vector<int> visited(g.get_size(), 0);
	std::queue<int> q;

	q.push(start);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		visited[current] = 1;
		std::cout << "BFS visit node : " << current << std::endl;
		for (int i = 0; i < g.get_size(); i++)
		{
			if (current == i)
				continue ;
			int edge = g.get_edge_from_to(current, i);
			if (edge == 1 && visited[i] == 0)
				q.push(i);
		}
	}
}

void topological_sort(Graph& g)
{
	int size = g.get_size();
	std::vector<int> out_degree(size, 0);
	for (int i = 0; i < size; i++)
		out_degree[i] = g.get_out_degree(i);
	
	std::vector<int> result;
	std::vector<int> visited(size, 0);
	std::queue<int> q;
	for (int i = 0; i < size; i++)
	{
		if (out_degree[i] == 0)
		{
			visited[i] = 1;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		result.push_back(current);
		for (int i = 0; i < size; i++)
		{
			if (visited[i] == 1)
				continue ;
			if (g.get_edge_from_to(i, current) == 1)
				out_degree[i]--;
			if (out_degree[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	if (result.size() != (size_t)size)
	{
		std::cout << "This is not ordered set..." << std::endl;
		return ;
	}
	else
	{
		int len = result.size();
		for (int i = len - 1; i >= 0; i--)
			std::cout << result[i] << " ";
		std::cout << "\n";
	}
}

void prim_algorithm(Graph& g, int start)
{
	std::priority_queue<int> q;
	std::vector<int> result;

	q.push(start);
	while (q.empty())
	{
		int current = q.top();
		result.push_back(current);
		
	}
}

int main() {
    Graph g(10);
	std::vector<int> visited_for_dfs(g.get_size(), 0);

    // 간선 추가
    g.set_edge_from_to(0, 1);
    g.set_edge_from_to(1, 2);
    g.set_edge_from_to(2, 3);
    g.set_edge_from_to(3, 4);
    g.set_edge_from_to(4, 5);
    g.set_edge_from_to(5, 6);
    g.set_edge_from_to(6, 7);
    g.set_edge_from_to(7, 8);
    g.set_edge_from_to(8, 9);

    g.print();

	dfs(g, 0, visited_for_dfs);
	bfs(g, 0);
	topological_sort(g);

    return 0;
}