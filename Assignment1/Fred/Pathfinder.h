#pragma once

#include <vector>
#include "map.h"
#include <queue>
class Node;
class Map;
class Pathfinder
{
public:
	Pathfinder(Map* map, int, int);

	void createNodeGrid();
	void refreshHeuristics();
	void setDestination(int dx, int dy);
	std::vector<Node*> getPath(int x1, int y1);
	void printHGrid();
private:

	Map* map;
	int width;
	int height;
	int destinationX, destinationY;
	Node*** nodeGrid;


};

class Node
{
public:
	Node(int x, int y, int g, bool walkable);
	double calculateHeuristic(int, int);
	double getFValue();
	double getLocalFValue();
	int h;
	int g;
	int f;
	int x;
	int y;
	bool walkable;
	Node* parent;

	 bool operator==(const Node &n1){
		 return this->x == n1.x && this->y == n1.y;
	}
};

