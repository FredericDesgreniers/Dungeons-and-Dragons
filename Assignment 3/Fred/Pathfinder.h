#pragma once

#include <vector>
#include "Map.h"

class Node;
class Map;
/** Pathfinder class for AI and map validation.
 * Pathfinder goes creates a path from pointer A to point B on a map.
 */
class Pathfinder
{
public:
	/**
	 * Creates a pathfinder with a map and start position
	 */
	Pathfinder(Map* map, int, int);
	/**
	 * create the node grid for the map.
	 * 
	 * Must be called if the getPaht() is called another time
	 */
	void createNodeGrid();
	/**
	 * Refresh heuristics
	 */
	void refreshHeuristics();
	/**
	 * Set destination
	 */
	void setDestination(int dx, int dy);

	/**
	 * Get apth from destination to x,y
	 */
	std::vector<Node*>* getPath(int x1, int y1);

	/**
	 * Print heuristics grid in console
	 */
	void printHGrid();

	~Pathfinder();
private:

	Map* map;
	int width;
	int height;
	int destinationX, destinationY;
	Node*** nodeGrid;


};
/**
 * Node used by pathfinding
 */
class Node
{
public:
	Node(int x, int y, int g, bool walkable);
	/**
	 * Claculate the manhatan distance from nodex,nodey to x,y
	 */
	double calculateHeuristic(int, int);
	/**
	 * Get the F value of this node + it's parents
	 */
	double getFValue();
	/**
	 * Get the FValue of only this node, which is heuristics + g
	 */
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

