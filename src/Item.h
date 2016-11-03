#include <string>


class Item
{

public:
  static enum ItemType
  {
    HELMET, // int, wis, armor class
    ARMOR,  // armor class
    SHIELD, // armor class
    RING,   // armor class, str, con, wis, cha
    BELT,   // con, str
    BOOTS,  // armor class, dex
    WEAPON  // attack, damage
  }

  Item();
  Item(ItemType iType);
  ~Item();


  string getName();
  void setName(string iName);

  ItemType getItemType();
  void setItemType();

  int getStrBoost();
  void setStrBoost(int strB);

  int getDexBoost();
  void setDexBoost(int dexB);

  int getConBoost();
  void setConBoost(int conB);

  int getIntBoost();
  void setIntBoost(int intB);

  int getWisBoost();
  void setWisBoost(int wisB);

  int getChaBoost();
  void setChaBoost(int chaB);

  int getAtkBoost();
  void setAtkBoost(int atkB);

  int getDmgBoost();
  void setDmgBoost(int dmgB);

  int getArmBoost();
  void setArmBoost(int armB);

private:
  // items all have a name
  string itemName;
  // and a type
  ItemType type;

  // The boosts are restricted by the item type
  // items can boost the 6 bases ability scores
  int strBoost;
  int dexBoost;
  int conBoost;
  int intBoost;
  int wisBoost;
  int chaBoost;

  // and attack, damage or armor class
  int atkBoost;
  int dmgBoost;
  int armBoost;


}
