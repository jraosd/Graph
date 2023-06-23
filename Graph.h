#ifndef GRAPH_H
#define GRAPH_H
#include"Node.h"
#include<unordered_map>

class Graph
{
public:
	Graph();
    ~Graph();
	void createNode(int id, int x, int y);
	void deleteNode(int id);
	bool containsNode(int id) const;
	bool validEdge(int originID, int destID) const;
	const std::vector<const Node*> getAdjacent(int id) const;
	void createEdge(int originID, int destID);
	void removeEdge(int originID, int destID);
	void clearEdges();
	int edgeCount() const;
	int nodeCount() const;

private:
	std::unordered_map<int, Node*> graph;
	int totalNodes;
	int totalEdges;

};
#endif