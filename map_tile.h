#pragma once

class MapTile
{
private:
	int id;
	bool walkable;

	int movementCost = 1;

public:
	MapTile(int id);

	int getId()
	{
		return id;
	}

	void setId(int id)
	{
		this->id = id;
	}

	bool getWalkable()
	{
		return walkable;
	}

	void setWalkable(bool walkable)
	{
		this->walkable = walkable;
	}

	int getMovementCost()
	{
		return movementCost;
	}
};