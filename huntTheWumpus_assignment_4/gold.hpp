#include<iostream>
#include<string>
#include"event.hpp"
#ifndef GOLD_HPP
#define GOLD_HPP

using namespace std;

class Gold: public Event {	
	protected: 
		int type;
		string precept;		
	public:
		Gold();
		void message();
		int get_type();
		string get_precept(); 
};

#endif
