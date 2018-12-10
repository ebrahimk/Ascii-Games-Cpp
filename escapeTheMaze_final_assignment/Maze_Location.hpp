#ifndef MAZE_LOCATION_HPP
#define MAZE_LOCATION_HPP
#include<iostream>

using namespace std;

#pragma once 

class MazeLocation{
        protected:
                char symbol;
	public:
                virtual bool is_occupiable() =0;
                virtual char get_display_character() =0; 
                virtual void set_symbol(char sym) =0;
                virtual void set_has_student(bool tf) =0;
                virtual bool has_student() =0;
                virtual void set_has_ta(bool tf)=0;
                virtual bool has_ta() = 0;
                virtual void set_has_instructor(bool tf) =0;
                virtual bool has_instructor() =0;
                virtual void set_has_skill(bool tf) =0;
                virtual bool has_skill() =0;
                virtual void set_has_start(bool tf)=0;
                virtual bool has_start()=0;
                virtual void set_has_ladder(bool tf)=0;
                virtual bool has_ladder()=0;

};

#endif
