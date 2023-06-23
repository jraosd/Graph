#ifndef NODE_H
#define NODE_H

#include <unordered_map>

class Node
{
public:
	Node(int x, int y, int id);
	~Node();

	void setX(int x);
	void setY(int y);
	void setID(int id);

	int getX() const;
	int getY() const;
	int totalEdges() const;
	int getID() const;
	
	void addEdge(const Node& dest);
	void removeEdge(int id);
	void clearEdges();
	bool hasEdge(int id) const;
	std::vector<const Node*> getEdges() const;


	bool operator==(const Node& other) const;
	
private:
	int x;
	int y;
	int id;
	std::unordered_map<int, const Node*> edges;
};
#endif