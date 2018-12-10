#include<iostream>
#include<string>
#include"room.hpp"
#include"event.hpp"
#include"empty.hpp"

using namespace std; 

/****************************************
 *Function:		Room()                       
 *Description:          Room constructor 
 *Parameters:          	N/A
 *Pre-conditions:       Room object called
 *Post-conditions:      Room object created 
 *Return:               N/A
*****************************************/


Room::Room(){
	event = new Empty;
	dimension ="|_|";
}
 
/****************************************
 *Function:           	~Room        
 *Description:          Room destructor 
 *Parameters:          	N/A
 *Pre-conditions:       N/A
 *Post-conditions:      memory freed
 *Return:               N/A
*****************************************/

Room::~Room(){
	delete event;
}
 
/****************************************
 *Function:             get_dimension (yes I know I mispelled that)       
 *Description:          returns the demension of te room 
 *Parameters:          	N/A
 *Pre-conditions:   	function called 
 *Post-conditions:      string returned 
 *Return:               string demension 
*****************************************/

string Room::get_dimension(){
	return this-> dimension;
}
 
/****************************************
 *Function:            	set_dimension
 *Description:          sets the demension of a room 
 *Parameters:          	string hero marker 
 *Pre-conditions:       room demesion changed 
 *Post-conditions:    	N/A
 *Return:               N/A
*****************************************/

void Room::set_dimension(string hero){
	this-> dimension = hero;
}
 
/****************************************
 *Function:             set_room()       
 *Description:          set the event in a room to something new 
 *Parameters:          	event pointer 
 *Pre-conditions:       function called 
 *Post-conditions:      event in said room is changed 
 *Return:               N/A
*****************************************/

void Room::set_room(Event* some_event){
	delete event;
	event = some_event;	
}
 
/****************************************
 *Function:             message       
 *Description:          grabs the message 
 *Parameters:          	N/A
 *Pre-conditions:       function called
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Room::message(){
	return event->message(); // may need to make new names 
}
 
/****************************************
 *Function:                get_precept()       
 *Description:             returns string precept
 *Parameters:          	   N/A
 *Pre-conditions:          N/A
 *Post-conditions:         string returned 
 *Return:                  string 
*****************************************/

string  Room::get_precept(){
	return event->get_precept();
}
 
/****************************************
 *Function: 		   get_event_type()                      
 *Description:             gets the int corresponding to given type
 *Parameters:          	   N/A
 *Pre-conditions:          function called
 *Post-conditions:         N/A
 *Return:                  int 
*****************************************/

int Room::get_event_type(){
	return event -> get_type(); //this may not work 
}
 
/****************************************
 *Function:                check()        
 *Description:             checks to see what event is in a given room 
 *Parameters:          	   N/A
 *Pre-conditions:          N/A
 *Post-conditions:         return int corresponding to event type 
 *Return:                  int type
*****************************************/

int Room::check(){
	if(event -> get_type() == 1)
		return 1;                               //Wumpus
	if(event -> get_type() == 2) // pit
		return 2;
	if(event -> get_type() == 3) //bats 
		return 3;
	if(event -> get_type() == 4) //gold 
		return 4;
}
 
/****************************************
 *Function:               get_event()
 *Description:            gets the event 
 *Parameters:          	  N/A
 *Pre-conditions:         N/A
 *Post-conditions:        N/A
 *Return:                 event*
*****************************************/

Event* Room::get_event(){
	return this->event; 
}

