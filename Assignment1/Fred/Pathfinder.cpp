#include "Pathfinder.h"
#include <iostream>
#include <algorithm>
Pathfinder::Pathfinder(Map* map, int destinationX, int destinationY)
{
	this->map = map;
	this->height = map->getHeight();
	this->width = map->getWidth();
	this->destinationX = destinationX;
	this->destinationY = destinationY;
	createNodeGrid();
}

void Pathfinder::createNodeGrid()
{
	nodeGrid = new Node**[width];
	for (int x = 0; x < width; x++)
	{
		nodeGrid[x] = new Node*[height];
		for (int y = 0; y < height; y++)
		{
			MapTile* tile = map->getTile(x, y);
			Node* node = new Node(x, y, tile->getMovementCost(), tile->getWalkable());
			//std::cout << x << ", " << y << " " << tile->getWalkable() << std::endl;
			node->calculateHeuristic(destinationX, destinationY);
			nodeGrid[x][y] = node;
		}
	}
}

void Pathfinder::getPath(int x1, int y1)
{
	std::vector<Node*> openNodes;
	std::vector<Node*> closedNodes;

	Node* current = nodeGrid[x1][y1];

	if (x1 > 0)
		openNodes.push_back(nodeGrid[x1 - 1][y1]);
	if(y1 > 0)
		openNodes.push_back(nodeGrid[x1][y1 - 1]);
	if(x1 < width-1)
		openNodes.push_back(nodeGrid[x1 + 1][y1]);
	if(y1 < height - 1)
		openNodes.push_back(nodeGrid[x1][y1+1]);


	bool found = false;
	while(!openNodes.empty())
	{
		closedNodes.push_back(current);
		openNodes.erase(std::remove(openNodes.begin(), openNodes.end(), current), openNodes.end());

		Node *neightboors[4] = { 
			current->x>0?nodeGrid[current->x - 1][current->y]:nullptr,
			current->x<width-1?nodeGrid[current->x + 1][current->y]:nullptr ,
			current->y>0?nodeGrid[current->x][current->y -1]:nullptr ,
			current->y<height-1?nodeGrid[current->x][current->y+1]:nullptr
		};
		
		for (int i = 0; i < 4; i++)
		{

			if(neightboors[i]!=nullptr && neightboors[i]->walkable)
			{
				Node* node = neightboors[i];
				if(node == nodeGrid[destinationX][destinationY])
				{
					std::cout << "FOUNDED";
					found = true;
					break;
				}
				bool inOpen = std::find(openNodes.begin(), openNodes.end(), node) != openNodes.end();
				bool inClose = inOpen?false: std::find(closedNodes.begin(), closedNodes.end(), node) != closedNodes.end();
				


				if(!inOpen && !inClose){
					node->parent = current;
					openNodes.push_back(node);
					std::cout << "(" << node->x << " " << node->y << ") - ";
				}else if(inClose)
				{
					continue;
				}else if(inOpen)
				{
					
				}

			}

		}
		if (found)
		{
			break;
		}
		int lowestIndex = -1;
		int lowestF = -1;
		for (int i = 0; i < openNodes.size(); i++)
		{
			Node* n = openNodes.at(i);
			if( lowestF < 0 || n->getFValue() < lowestF)
			{
				lowestIndex = i;
			}
		
		}
		
		if (lowestIndex < 0)
			break;
		current = openNodes.at(lowestIndex);
		std::cout << "current: " << current->x << ":" << current->y;
		std::cout << std::endl;
		
	}
	while(current->parent != nullptr)
	{
		std::cout << current->x << " " << current->y << std::endl;
		current = current->parent;
	}

}

void Pathfinder::printHGrid()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			std::cout << nodeGrid[x][y]->h << " ";
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

double Node::calculateHeuristic(int targetX, int targetY)
{
	h = abs(targetX - x) + abs(targetY - y);
	return h;
}

double Node::getFValue()
{
	return getLocalFValue()+(parent==nullptr?0:parent->getFValue());
}

double Node::getLocalFValue()
{
	return h + g;
}


