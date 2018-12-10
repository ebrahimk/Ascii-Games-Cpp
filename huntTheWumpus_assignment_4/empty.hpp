#include<iostream>
#include<string> 
#include"event.hpp"
#ifndef EMPTY_HPP
#define EMPTY_HPP

using namespace std; 

class Empty : public Event { 
	protected:
		int type;
		string precept;
	public:
		Empty();
		int get_type();
		string get_precept();
		void message();	
};

#endif

