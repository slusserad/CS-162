/*
Program name : Final Project Game
Author : Adam Slusser
Date : 12/ 6 / 2019
Description : Header for Space class which is the base class for the Bridge, Cargo Bay, Common Area, Engine Bay, 
Living Area, and Outside classes. Functions included control direction, description of room (class) player is in, 
if there is an item that player can pick up, describes the problem in the room, if the problem has been solved and
a map of the ship.
*/
#ifndef _SPACE_HPP
#define _SPACE_HPP

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Space {

protected:
	Space* North;
	Space* East;
	Space* South;
	Space* West;

	bool room_solved;
	
	string room_name;
	string room_description; 

public:
	Space();
	Space(Space* N, Space* S, Space* E, Space* W, string descript, string name);
	//Pure virual function.
	virtual ~Space() = 0;
	virtual	void set_north(Space* N);
	virtual void set_east(Space* E);
	virtual void set_south(Space* S);
	virtual void set_west(Space* W);

	virtual	Space* get_north();
	virtual Space* get_east();
	virtual Space* get_south();
	virtual Space* get_west();
	virtual string get_room_name();
	virtual string get_description();
	virtual void problem_solved();
	virtual string action_description();
	virtual string action_item_required();
	virtual string room_item();
	virtual void ship_map() {
		cout << "                        [][][][][][][][]                              " << endl;
		cout << "                        []  Bridge    []     Outside the ship         " << endl;
		cout << "                        []  (North)   []                              " << endl;
		cout << "[][][][][][][][][][][][]||------------||[][][][][][]||------||[][][][]" << endl;
		cout << "[]              ||                              ||                  []" << endl;
		cout << "[]  Cargo Bay   |      Common Area/Kitchen       | Living Quarters  []" << endl;
		cout << "[]  (West)      |                                |     (East)       []" << endl;
		cout << "[]              ||                              ||                  []" << endl;
		cout << "[][][][][][][][][][][][]||------------||[][][][][][][][][][][][][][][]" << endl;
		cout << "                        [] Engine Bay []                              " << endl;
		cout << "                        [] (South)    []                              " << endl;
		cout << "                        [][][][][][][][]                              " << endl;
	}
};
#endif // !_SPACE_HPP