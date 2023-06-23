#include "Node.h"

Node::Node(int x, int y, int id)
{
	this->id = id;
	this->x = x;
	this->y = y;
}

Node::~Node()
{

}

void Node::setX(int x)
{
	this->x = x;
}

void Node::setY(int y)
{
	this->y = y;
}

void Node::setID(int id)
{
	this->id = id;
}

int Node::getX() const
{
	return x;
}

int Node::getY() const
{
	return y;
}

int Node::totalEdges() const
{
	return static_cast<int>(edges.size());
}

int Node::getID() const
{
	return id;
}

void Node::addEdge(const Node& dest)
{
	if (!edges.contains(dest.id))
	edges[dest.id] = &dest;
}

void Node::removeEdge(int id)
{
	if (edges.contains(id)) 
	edges.erase(id);
}

void Node::clearEdges()
{
	edges.clear();
}

bool Node::hasEdge(int id) const
{
	return edges.contains(id);
}

std::vector<const Node*> Node::getEdges() const
{
	std::vector<const Node*> adjacent;
	adjacent.reserve(edges.size());
	for (auto iter = edges.cbegin(); iter != edges.cend(); ++iter) 
	{
		adjacent.push_back(iter->second);
	}
	return adjacent;
}

bool Node::operator==(const Node& other) const
{
	return this->x == other.x && this->y == other.y &&
		this->edges == other.edges;
}