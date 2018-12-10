#include<iostream> 
#include"animal.hpp"
#ifndef SEA_OTTER_HPP
#define SEA_OTTER_HPP

class Otter: public Animal{
	public:
		Otter();
		Otter(int age, float cost, int revenue, bool alive);
		int food_cost(); 
		void set_adult_status();
		int get_rev();
};
#endif
