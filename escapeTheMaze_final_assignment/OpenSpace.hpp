#include"Maze_Location.hpp"
#ifndef OPENSPACE_HPP
#define OPENSPACE_HPP
#include<iostream>
#include<string>

using namespace std;

#pragma once 

class OpenSpace: public MazeLocation {
        protected:
                bool occupied;
		bool student;
		bool ta; 
		bool instructor; 
                bool start;
                bool end;
		bool skill;	
        public:
                OpenSpace();
                char get_display_character();
                void set_symbol(char sym); 
		bool is_occupiable();
		void set_has_student(bool tf);
                bool has_student();
		void set_has_ta(bool tf);
		bool has_ta();
		void set_has_instructor(bool tf);
		bool has_instructor();
		void set_has_skill(bool tf);
		bool has_skill();
		void set_has_start(bool tf);
                bool has_start();
		void set_has_ladder(bool tf);
                bool has_ladder();		
};

#endif
