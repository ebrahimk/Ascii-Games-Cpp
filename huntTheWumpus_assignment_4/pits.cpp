#include<iostream>
#include<string> 
#include"pits.hpp"

using namespace std;
 
/***************************************
 *Function:             Pits           
 *Description:          Pits constructor 
 *Parameters:           N/A
 *Pre-conditions:       Pit object called 
 *Post-conditions:      Pit object created 
 *Return:               N/A
*****************************************/

Pits::Pits(): type(3), precept("You feel a breeze") {
}
 
/***************************************
 *Function:             message()
 *Description:          prints message about room 
 *Parameters:           N/A
 *Pre-conditions:       function is called 
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Pits::message(){
	cout<<"Throwing caution to the wind you barge into the next room only to realize that their is a bottomless pit. You fall and plummet to your death."<<endl; 
}
 
/***************************************
 *Function:             get_type()
 *Description:          returns the type of event
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      int type returned 
 *Return:               int type
*****************************************/

int Pits::get_type(){
	return this-> type;
}

/***************************************
 *Function:             get_precept() 
 *Description:          returns precept string
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      prints the precept
 *Return:               string
*****************************************/

string Pits::get_precept(){
	return this -> precept; 
}
