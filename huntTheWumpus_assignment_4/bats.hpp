#include<iostream>
#include<string>
#include"event.hpp"
#ifndef BATS_HPP
#define BATS_HPP

using namespace std; 

class Bats: public Event {
	protected:	
		string precept;
		int type;
	public:
		Bats();		
		string get_precept();	
		int get_type();	
		void message(); 
};

#endif
