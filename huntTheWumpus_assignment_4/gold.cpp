#include<iostream>
#include<string>
#include"gold.hpp"
#include"event.hpp"

using namespace std;

/***************************************
 *Function:             Gold         
 *Description:          Gold constructor 
 *Parameters:           N/A
 *Pre-conditions:       Gold object called 
 *Post-conditions:      Gold object created 
 *Return:               N/A
*****************************************/


Gold::Gold(): type(4), precept("You hear a muffled cry nearby..."){
}
 
/***************************************
 *Function:             message()
 *Description:          prints message about room 
 *Parameters:           N/A
 *Pre-conditions:       function is called 
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Gold::message(){
	cout<<"Entering the room you see a beautiful young lady with flowing golden locks... "<<endl;
	cout<<endl;
	cout<<"Oh brave hero, you have found me!!! Thank you!!! I am eternally in your debt!"<<endl; 
}
 
/***************************************
 *Function:             get_type()
 *Description:          returns the type of event
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      int type returned 
 *Return:               int type
*****************************************/

int Gold::get_type(){
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


string Gold::get_precept(){
	return this-> precept;
}
