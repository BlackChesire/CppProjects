#ifndef INC_32_EX3_312391774_HOCKEY_TABLE_H
#define INC_32_EX3_312391774_HOCKEY_TABLE_H
#include "DiscLinkedList.h"
#include "WallLinkedList.h"
#include "Vector2D.h"
class Hockey_table
{
public:
	Hockey_table(const DiscLinkedList &DiscLinkedList, const WallLinkedList &wallLinkedlist); //ctor
	Hockey_table(Hockey_table &other);// copy ctor
	Hockey_table &operator=(const Hockey_table &rhs);
	bool check_discs_collison(Disc &disc1, Disc &disc2) const;		//checks if 2 disc bumped each other
	Vector2D find_closet_point(const Wall &wall, const Disc &disc); //finds the distance between the disc and the disc
	bool check_disc_to_wall_bump(Disc &disc, Wall &wall);			// check if disc bumped with a disc
	void speed_update_after_bump(Disc &disc1, Disc &disc2);			//updates the disc's speed a bump with another disc
	void speed_update_after_wall_bump(Disc &disc, Wall &wall);		// updates the disc's speed after a bump with a disc
	void check_stepover(Disc disc);                                 //checks if the discs already exits
    	void check_stepover(Wall wall);                                 // checks if disc is stepping over wall on init.
	void simulate(double t, double dt);								//simualtes the game
	const DiscLinkedList &getDiscLinkedlist() const;				// returns discs linked list
	const WallLinkedList &getWallLinkedlist() const;				// returns walls linked list
	void step_simulation(double dt, double time);                   // simulating the game given the time
	friend ostream &operator<<(ostream &, const Hockey_table &);
	DiscLinkedList discLinkedlist; // linked list to keep all the discs
	WallLinkedList wallLinkedlist; //linked list to keep all the walls
};

ostream &operator<<(ostream &out, const Hockey_table &table);
#endif //INC_32_EX3_312391774_HOCKEY_TABLE_H
