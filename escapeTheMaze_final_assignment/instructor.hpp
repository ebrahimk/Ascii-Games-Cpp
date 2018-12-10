#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP
#include<iostream>
#include<string>
#include"MazePerson.hpp"

#pragma once

using namespace std;

class Instructor: public MazePerson{ 
        public:
                Instructor();
                char get_move();
         	void set_location(int row, int col);
		int get_row();
		int get_col();
		int get_floor();
		void set_floor(int f);
};

#endif

