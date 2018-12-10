#include"Maze_Location.hpp"
#include"OpenSpace.hpp"
#include"wall.hpp"
#include<fstream>

#pragma once

#ifndef MAZELEVEL_HPP
#define MAZELEVEL_HPP
#include<iostream>
#include<string>


using namespace std;

class MazeLevel{
        protected:
                MazeLocation*** locations;
                int row;
                int col;
        public:
                MazeLevel(ifstream& level, int height, int width);
                ~MazeLevel();

                void set_location_symbol(int row, int col, char sym);
		char get_location_sym(int row, int col);

                void display_maze();
			
		void set_ta(int row1, int col1, bool tf1);
		bool check_ta(int row2, int col2);
		
		void set_instructor(int row3, int col3, bool tf3);	
		bool check_instructor(int row4, int col4);
		
		void set_skill(int row3, int col3, bool tf3); 
		bool check_skill(int row4, int col4);
		
		void set_student(int row5, int col5, bool tf5);
	 	bool check_student(int row6, int col6);
		
		bool wall_open(int row6, int col6);	
			
		bool check_ladder(int row7, int col7);
		bool check_start(int row8, int col8);
		
};

#endif


