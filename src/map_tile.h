#pragma once

class MapTile
{
private:
	int id;
	bool walkable;

	int movementCost = 1;

public:
	MapTile(int id);

	int getId();

	void setId(int id);

	bool getWalkable();
	void setWalkable(bool walkable);

	int getMovementCost();
};