#include <fstream>
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include <unordered_map>

/*
Network Flooding Implementation
*/

void networkFlooding(std::unordered_map<int, std::list<std::pair<int, int>>> graph, int source)
{
	std::set<int> visited; 
	std::queue<int> queue; 

	std::cout << "Starting flood from node:" << source << std::endl; 

	queue.push(source); 
	visited.insert(source); 

	while (!queue.empty()) {
		int node = queue.pop(); 
		std::cout << "Flooding has reached node: " << node << std::endl; 

		for (const auto& neigh : graph[node]) {
			if (visited.find(neigh)){
				visited.insert(neigh)
				queue.push(neigh); 
			}
		}
		}


	}