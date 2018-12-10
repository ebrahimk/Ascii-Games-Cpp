#include<iostream>
#include<string>  
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
	protected:
		bool alive; 
		int age;  
		float cost; 
		int revenue; 
	public:	
		void increase_age();
		int  get_age();  
		void set_living_status(bool TF);	
		bool get_living_status();	
};

#endif 
