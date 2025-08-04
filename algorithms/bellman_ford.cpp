#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

void bellmanFord(std::unordered_map<int, std::list<std::pair<int, int>>> graph, int source, int vertices)
{
	std::unordered_map<int, int> distances;

	// initialize all values to max
	for (const auto &pair : graph)
	{
		distances[pair.first] = INT_MAX;
	}

	// iterate through each possible vertex (relax edges |V| - 1 times )
	for (int i = 0; i < vertices - 1; ++i)
	{
		// iterate through each vertex
		for (const auto &firstPair : graph)
		{
			// iterate through each edge
			for (const auto &secondPair : graph[firstPair.first])
			{
				if (distances[firstPair.first] != INT_MAX && ((distances[firstPair.first] + secondPair.second) < distances[secondPair.first]))
				{
					distances[firstPair.first] = distances[secondPair.first] + secondPair.second;
				}
			}
		}
	}

	// check for negative weights
	for (const auto &firstPair : graph)
	{
		for (const auto &secondPair : graph[firstPair.first])
		{
			if (distances[firstPair.first] != INT_MAX && ((distances[secondPair.first] + secondPair.second) < distances[secondPair.first]))
			{
				std::cerr << "Graph contains negative weight cycle" << std::endl;
			}
		}
	}
}