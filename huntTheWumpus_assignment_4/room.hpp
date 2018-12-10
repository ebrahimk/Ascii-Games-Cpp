#include<iostream>
#include"event.hpp"
#ifndef ROOM_HPP
#define ROOM_HPP

using namespace std; 

class Room {
	protected:
		Event* event; // may cause errors because its a pointer 
		string dimension;
	public:
		Room();
		~Room(); 
		void set_room(Event* some_event); 	 
		int check(); 
		int get_event_type();
		Event* get_event(); 
		string get_dimension();
		void set_dimension(string hero); 
		void message(); //might need to change these names maybe functions will overload 
		string get_precept(); 	
};

#endif

