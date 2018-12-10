#include<iostream>
#include<vector> 
#include"room.hpp"
#include<string>
#include"adventurer.hpp" 
#ifndef CAVE_HPP
#define CAVE_HPP

using namespace std;

class Cave {
	protected:
		vector<vector<Room*> > network;
		int room_num;
		int location_row;
		int location_col; 
		int wump_row;
		int wump_col; 
		int rope_row;
		int rope_col; 
		Adventurer hero; 
	public:
		Cave(int num);
		~Cave(); 
		void player_move(); 
		bool what_happens(); //returns false if player dies 
		void check_precepts(); 
		bool shoot(); 
		bool check_lose_arrows(bool wump_dead); //moves wumpus if move is true// checks to see if Hero has any more arrows
		bool win(bool wump_dead); 
		void print_cave();
		bool check_same();
		void exposition();
		void ending();
};

#endif
 
