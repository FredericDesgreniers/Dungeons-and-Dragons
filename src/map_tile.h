#pragma once
/**
 * represents a tile on a map
 */
class MapTile
{
private:
	/**
	 * Tile id
	 */
	int id;
	/**
	 * Is tile walkable
	 */
	bool walkable;
	/**
	 * Tile movement cost
	 */
	int movementCost = 1;

public:
	/**
	 * Create a tile
	 * use map'h's TILE constants for ID
	 */
	MapTile(int id);

	/**
	 * return tile ID
	 */
	int getId();

	/**
	 * Set tile id
	 */
	void setId(int id);

	/**
	 * returns if tile is walkable
	 */
	bool getWalkable();
	/**
	 * Set if tile is walkable
	 */
	void setWalkable(bool walkable);
	/**
	 * return movement cost
	 */
	int getMovementCost();
};