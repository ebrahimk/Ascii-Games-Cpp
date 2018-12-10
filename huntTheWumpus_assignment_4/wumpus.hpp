#include<iostream>
#include<string>
#include"event.hpp"
#ifndef WUMPUS_HPP
#define WUMPUS_HPP

using namespace std; 

class Wumpus : public Event {
		string precept;
		int type;	
	public:
		Wumpus();	
		string get_precept(); 
		void message();
		int get_type(); 
};

#endif

