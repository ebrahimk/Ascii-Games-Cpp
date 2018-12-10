#include"Maze_Location.hpp"
#ifndef WALL_HPP
#define WALL_HPP
#include<iostream>

#pragma once

using namespace std;

class Wall: public MazeLocation {
        public:
                Wall();
                char get_display_character();
                bool is_occupiable();
                void set_symbol(char sym);
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
