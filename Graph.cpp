#include "Graph.h"
#include<iostream>

Graph::Graph()
{
	totalNodes = 0;
	totalEdges = 0;
}

Graph::~Graph()
{

}

void Graph::createNode(int id, int x, int y)
{
	if (graph.contains(id)) return;
	
	Node* node = new Node(x, y, id);
	graph[id] = node;
	totalNodes++;
}

void Graph::deleteNode(int id)
{
	if (graph.contains(id))
	{
		auto end = graph.end();
		for (auto iter = graph.begin(); iter != end; iter++)
		{
			if (iter->second->hasEdge(id))
			{
				iter->second->removeEdge(id);
				totalEdges--;
			}
		}
		Node* node = graph.at(id);
		graph.erase(id);
		delete node;
		node = nullptr;
		totalNodes--;
	}
}

bool Graph::containsNode(int id) const
{
	return graph.contains(id);
}

bool Graph::validEdge(int originID, int destID) const
{
	return graph.contains(originID) && graph.contains(destID)   
		   && graph.at(originID)->hasEdge(destID);
}

const std::vector<const Node*> Graph::getAdjacent(int id) const
{	
	if (graph.contains(id))
		return graph.at(id)->getEdges();
	else
		return std::vector<const Node*>();
}

void Graph::createEdge(int originID, int destID)
{
	if (graph.contains(originID) && graph.contains(destID) && 
		!graph.at(originID)->hasEdge(destID))
	{
		graph.at(originID)->addEdge(*graph.at(destID));
		totalEdges++;
	}
}

void Graph::removeEdge(int originID, int destID)
{
	if(validEdge(originID, destID))
	{
		graph.at(originID)->removeEdge(destID);
		totalEdges--;
	}
}

void Graph::clearEdges()
{
	auto end = graph.end();
	for (auto iter = graph.begin(); iter != end; iter++)
	{
		totalEdges -= iter->second->totalEdges();
		iter->second->clearEdges();
	}
}

int Graph::edgeCount() const
{
	return totalEdges;
}

int Graph::nodeCount() const
{
	return totalNodes;
}
