#pragma once

class MapTile
{
private:
	int id;
	bool walkable;
public:
	MapTile(int id);

	int getId()
	{
		return id;
	}
	bool getWalkable()
	{
		return walkable;
	}

	void setWalkable(bool walkable)
	{
		this->walkable = walkable;
	}
};