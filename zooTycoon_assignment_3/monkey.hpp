#include<iostream>
#include<string> 
#include"animal.hpp"
#ifndef MONKEY_HPP
#define MONEKY_HPP

class Monkey : public Animal{
	public: 
		Monkey();
		Monkey(int age,float cost,int revenue,bool alive); //used for initializng purchased animals  
		int food_cost();   
		void set_adult_status();
		int get_rev();
		float get_cost();
};

#endif
