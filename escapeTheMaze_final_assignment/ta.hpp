#ifndef TA_HPP
#define TA_HPP
#include<iostream>
#include<string>
#include"MazePerson.hpp"

using namespace std;

#pragma once

class TA : public MazePerson{
	protected:
		int counter;
		bool appeased;
	public:
		TA();
		char get_move();
		bool get_appeased();
		void counter_step();  
		void set_location(int row, int col);
		int get_row();
		int get_col();
		int get_floor();
		void set_floor(int f);
		void set_counter();
};

#endif



