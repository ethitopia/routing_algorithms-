#include <iostream> 
#include <fstream> 
#include <vector> 
#include <unordered_map>
#include <bellman_ford>
#include <../utils/dist/hoppingDistance>

/*
II-F Distance Vector Routing 
*/

using namespace std; 


class NetworkNode{
    private: 
    int nodeID; 
    std::function<int(int, int)> dist_; 
    std::unordered_map<int, int> routing_table; // node, distance 

    public: 
    Network(int node, std::function<int(int, int)> dist) : nodeID(node), distance(dist) {}; 

    void initializeRouting(std::unordered_map<int, std::list<std::pair<int, int>>> graph) {
        for (const auto& pair : graph) {
            int node = pair.first;
            std::list<std::pair<int, int>> edgeList = pair.second; 
            
            // node is current node
            if (node == nodeID) { 
                routing_table[nodeID] = 0; 
            // node is a neighbor 
            } else if (std::find(edgeList.begin(), edgeList.end(), node) != node.end()) {
                routing_table[node] = hoppingDistance(nodeID, node); 
            // node distance not known
            } else {

            }
        }
        }

    void initializeNeighbors(std::unordered_map<int, std::list<std::pair<int, int>>> graph) {
        for (const auto& pair : graph) {

        }
    }

    void updateRouting(vector<int> allNodes) {
        return; 
    }

    void setNodeId(int newID) {
        nodeID = newID; 
    }

    int getNodeID() {
        return nodeID; 
    }

    int distanceVectorRouting(std::unordered_map<int, std::list<std::pair<int, int>>> graph) {
        for (const auto& pair : graph) { 
            int node = pair.first; 
            NetworkNode newNode = NetworkNode(node); 
            newNode::
        }

    }


    }
