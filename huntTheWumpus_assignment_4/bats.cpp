#include<iostream> 
#include<string>
#include"bats.hpp"

using namespace std; 
 
/***************************************
 *Function:             Bats          
 *Description:          Bats constructor 
 *Parameters:           N/A
 *Pre-conditions:       Bats object called 
 *Post-conditions:      Bats object created 
 *Return:               N/A
*****************************************/

Bats::Bats(): type(2), precept("You hear a flutter nearby."){
}
 
/***************************************
 *Function:             get_precept() 
 *Description:          returns precept string
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      prints the precept
 *Return:               string
*****************************************/

string Bats::get_precept(){
	return precept;
}
 
/***************************************
 *Function:             message()
 *Description:          prints message about room 
 *Parameters:           N/A
 *Pre-conditions:       function is called 
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Bats::message(){
	cout<<"As you enter the room you are swarmed by a mob of angry super bats!!!! The bats surround you and grab your armor whisking you away somewhere deep within the caves."<<endl;
}
 
/***************************************
 *Function:             get_type()
 *Description:          returns the type of event
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      int type returned 
 *Return:               int type
*****************************************/

int Bats::get_type(){
	return this -> type;
}
