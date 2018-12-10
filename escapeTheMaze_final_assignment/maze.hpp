#include"Maze_Location.hpp"
#include"MazeLevel.hpp"
#include"MazePerson.hpp"
#include"instructor.hpp"
#include"ta.hpp"
#include"intrepidstudent.hpp"
#include"OpenSpace.hpp"
#include"wall.hpp"
#include<iostream>
#include<string>
#include<fstream>
//#define LEVELS "maze.txt"

#ifndef MAZE_HPP
#define MAZE_HPP

#pragma once

using namespace std;

class Maze{
	protected:
		int height;
		int width;
		int level_num;
		MazeLevel** levels;
		Instructor* Rob_the_cruel;
		TA**  	    minions;
		IntrepidStudent* 	Kamron;
	public:
		Maze();
		~Maze();
		void turn();
		void turn_ta(); 			
		void check_skills();
		int check_win();
		void check_ta();
		void display();
		void set_symbols();
};

#endif
