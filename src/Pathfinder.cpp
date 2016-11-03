#include "Pathfinder.h"
#include <iostream>
#include <algorithm>
#include <queue>

Pathfinder::Pathfinder(Map* map, int destinationX, int destinationY)
{
	this->map = map;
	this->height = map->getHeight();
	this->width = map->getWidth();
	this->destinationX = destinationX;
	this->destinationY = destinationY;
	createNodeGrid();
}

/**
* Create node grid from provided map.
*/
void Pathfinder::createNodeGrid()
{
	if (nodeGrid != nullptr)
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (nodeGrid[i][j] != nullptr)
					delete nodeGrid[i][j];
			}
			delete nodeGrid[i];
		}
	delete nodeGrid;
	//create a new 2d array for the nodes. Each Node is created from a MapTile
	nodeGrid = new Node**[width];
	for (int x = 0; x < width; x++)
	{
		nodeGrid[x] = new Node*[height];
		for (int y = 0; y < height; y++)
		{
			MapTile* tile = map->getTile(x, y);
			Node* node = new Node(x, y, tile->getMovementCost(), tile->getWalkable());

			//calculate the distance to destination from tile
			node->calculateHeuristic(destinationX, destinationY);
			nodeGrid[x][y] = node;
		}
	}
}
void Pathfinder::setDestination(int dx, int dy)
{
	destinationX = dx;
	destinationY = dy;
	refreshHeuristics();
}

void Pathfinder::refreshHeuristics()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			nodeGrid[x][y]->calculateHeuristic(destinationX, destinationY);
		}
	}
}

/**
* Get a path from x1, y1 to the destination
*/
std::vector<Node*> Pathfinder::getPath(int x1, int y1)
{
	//open nodes list
	std::vector<Node*> openNodes;
	//closed node list
	std::vector<Node*> closedNodes;

	//current node
	Node* current = nodeGrid[x1][y1];

	//push the neighboors of the first node on the open list
	if (x1 > 0 && nodeGrid[x1-1][y1]->walkable)
		openNodes.push_back(nodeGrid[x1 - 1][y1]);
	if (y1 > 0 && nodeGrid[x1 ][y1-1]->walkable)
		openNodes.push_back(nodeGrid[x1][y1 - 1]);
	if (x1 < width - 1 && nodeGrid[x1 + 1][y1]->walkable)
		openNodes.push_back(nodeGrid[x1 + 1][y1]);
	if (y1 < height - 1 && nodeGrid[x1][y1+1]->walkable)
		openNodes.push_back(nodeGrid[x1][y1 + 1]);


	bool found = false;

	//when open nodes is empty, no path can be found
	while (!openNodes.empty())
	{
		// put current node on closed list and remove it from open nodes.
		closedNodes.push_back(current);
		openNodes.erase(std::remove(openNodes.begin(), openNodes.end(), current), openNodes.end());

		//get all the valid niehgbooring nodes to the current node
		Node *neightboors[4] = {
			current->x>0 ? nodeGrid[current->x - 1][current->y] : nullptr,
			current->x<width - 1 ? nodeGrid[current->x + 1][current->y] : nullptr ,
			current->y>0 ? nodeGrid[current->x][current->y - 1] : nullptr ,
			current->y<height - 1 ? nodeGrid[current->x][current->y + 1] : nullptr
		};

		for (int i = 0; i < 4; i++)
		{
			//check to see if neighboor is valid
			if (neightboors[i] != nullptr && neightboors[i]->walkable)
			{
				Node* node = neightboors[i];
				//check if node is the destination node. If so, exit loop
				if (node == nodeGrid[destinationX][destinationY])
				{
					found = true;
					break;
				}
				//check if the node is on the closed or open list
				bool inOpen = std::find(openNodes.begin(), openNodes.end(), node) != openNodes.end();
				bool inClose = inOpen ? false : std::find(closedNodes.begin(), closedNodes.end(), node) != closedNodes.end();


				//if not in any list, set parent to current node and put it on open list
				if (!inOpen && !inClose) {
					node->parent = current;
					openNodes.push_back(node);
					//std::cout << "(" << node->x << " " << node->y <<"/"<<node->getLocalFValue()<< "/ "<< node->getFValue()<<") - ";
				}
				else if (inClose) //if in closed list, ignore node
				{
					continue;
				}
				else if (inOpen) //if on open, calculate costs to poentially change parent?
				{
					if (current->g + node->g < node->g)
					{
						node->parent = current;
					}
					//TODO calculate new parent if cost is low enough
				}

			}

		}
		//if  found, exit loop.
		if (found)
		{
			break;
		}

		//find the node in the open list with the lowest value
		int lowestIndex = -1;
		int lowestF = -1;
		for (int i = 0; i < openNodes.size(); i++)
		{
			Node* n = openNodes.at(i);
			//std::cout << "(" << i << ": " << n->x << "," << n->y << " / " << n->getFValue() << "), ";
			if (lowestF < 0 || n->getFValue() < lowestF)
			{
				lowestIndex = i;
				lowestF = n->getFValue();
			}

		}
		//std::cout << std::endl << lowestIndex << std::endl << std::endl;
		//if no nodes found, exit loop. No solution
		if (lowestIndex < 0)
			break;

		//set the current to the open node with lowest F cost. 
		current = openNodes.at(lowestIndex);
		//std::cout << "current: " << current->x << ":" << current->y;
		//std::cout << std::endl;

	}
	std::vector<Node*> path;
	//trace back path from destination to start using parents

	while (current->parent != nullptr)
	{
		path.push_back(current);
		current = current->parent;
	}
	path.push_back(current);
	return path;


}

/**
* Print grid of H values (distance)
*/
void Pathfinder::printHGrid()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			printf("%2d ", nodeGrid[x][y]->h);
		}
		std::cout << std::endl;
	}
}


Node::Node(int x, int y, int g, bool walkable)
{
	this->x = x;
	this->y = y;
	this->walkable = walkable;
	this->g = g;

	h = 0;
}

/**
* calculate distance. using manhatan method
*/
double Node::calculateHeuristic(int targetX, int targetY)
{
	h = abs(targetX - x) + abs(targetY - y);
	return h;
}

/**
* Get F value with parent nodes.
*/
double Node::getFValue()
{
	return getLocalFValue() + (parent == nullptr ? 0 : parent->getFValue());
}

/**
* Get the local F value without parent nodes.
*/
double Node::getLocalFValue()
{
	return h + g;
}

Pathfinder::~Pathfinder()
{
	if (nodeGrid != nullptr)
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (nodeGrid[i][j] != nullptr)
					delete nodeGrid[i][j];
			}
			delete nodeGrid[i];
		}
	delete nodeGrid;
}


