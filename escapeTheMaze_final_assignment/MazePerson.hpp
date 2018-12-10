#ifndef MAZEPERSON_HPP
#define MAZEPERSON_HPP
#include<iostream>
#include<string>

#pragma once

using namespace std;

class MazePerson{
	protected:
		int row_loc;
		int col_loc;
		int floor;
	public: 
		MazePerson();
		char get_move();
		void set_location(int row, int col);
		int get_row();
		int get_col();
		int get_floor();
		void set_floor(int num);	
};

#endif
/*
char get_move();
                bool get_appeased();
                void counter_step();                                                               
                void set_location(int row, int col);
                int get_row();
                int get_col();
                int get_floor();
                void set_floor(int f);
                void set_counter();
*/
