#include<iostream> 
#include<string> 
#include"event.hpp"
#include"empty.hpp"

using namespace std;

/***************************************
 *Function:             Empty          
 *Description:          Empty constructor 
 *Parameters:           N/A
 *Pre-conditions:       Empty object called 
 *Post-conditions:      Empty object created 
 *Return:               N/A
*****************************************/


Empty::Empty(): type(5), precept(""){
}
 
/***************************************
 *Function:             get_type()
 *Description:          returns the type of event
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      int type returned 
 *Return:               int type
*****************************************/

int Empty::get_type(){
	return this-> type; 
}
 
/***************************************
 *Function:             message()
 *Description:          prints message about room 
 *Parameters:           N/A
 *Pre-conditions:       function is called 
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Empty::message(){ 
	cout<<"";
}

/***************************************
 *Function:             get_precept() 
 *Description:          returns precept string
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      prints the precept
 *Return:               string
*****************************************/


string Empty::get_precept(){
	return this->precept; 
}
