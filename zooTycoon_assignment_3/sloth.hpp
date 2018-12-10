#include<iostream> 
#include"animal.hpp"
#ifndef SLOTH_HPP
#define SLOTH_HPP

class Sloth: public Animal{
	public: 
		Sloth();
		Sloth(int age, float cost, int revenue,bool alive); 
		int food_cost();
		void set_adult_status();
		int get_rev();
};
#endif
