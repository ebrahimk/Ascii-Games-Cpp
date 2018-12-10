#include<iostream> 
#include<string>
#ifndef EVENT_HPP
#define EVENT_HPP

using namespace std;

class Event {
	public:
		virtual	string get_precept() = 0; 	
		virtual	void message() =0;
		virtual	int get_type() =0;
};

#endif 





