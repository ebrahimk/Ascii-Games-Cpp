#ifndef INTREPIDSTUDENT_HPP
#define INTREPIDSTUDENT_HPP
#include<iostream>
#include<string>
#include"MazePerson.hpp"

#pragma once

using namespace std;

class IntrepidStudent : public MazePerson{
        protected:
                int skills;
        public:
		IntrepidStudent();
                char get_move();
                void set_location(int row, int col);
                int get_row();
                int get_col();
                int get_skills();
                void increase_skills();
                void decrease_skills();
		void lose_skills();
		int get_floor();
		void set_floor(int f);
};

#endif


