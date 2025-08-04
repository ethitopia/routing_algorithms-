#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <limits>

class Graph
{
public:
	// Each edge: (destination, weight)
	std::unordered_map<int, std::list<std::pair<int, int>>> adj;
	bool directed;

	Graph(bool isDirected = false) : directed(isDirected) {}

	void addEdge(int u, int v, int weight)
	{
		adj[u].push_back({v, weight});
		if (!directed)
		{
			adj[v].push_back({u, weight});
		}
	}

	void printGraph()
	{
		for (const auto &[node, neighbors] : adj)
		{
			std::cout << node << ": ";
			for (const auto &[neighbor, weight] : neighbors)
			{
				std::cout << " -> (" << neighbor << ", " << weight << ")";
			}
			std::cout << "\n";
		}
	}

	const std::list<std::pair<int, int>> &getNeighbors(int u) const
	{
		static std::list<std::pair<int, int>> empty;
		auto it = adj.find(u);
		return (it != adj.end()) ? it->second : empty;
	}

	std::vector<int> getNodes() const
	{
		std::vector<int> nodes;
		for (const auto &[node, _] : adj)
		{
			nodes.push_back(node);
		}
		return nodes;
	}
};
