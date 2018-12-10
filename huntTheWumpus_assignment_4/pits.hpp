#include<iostream>
#include<string> 
#include"event.hpp"
#ifndef PITS_HPP
#define PITS_HPP

using namespace std;

class Pits: public Event {
	protected: 
		string precept;
		int type;
	public:
		Pits();
		void message();
		int get_type();
		string get_precept();
};

#endif
