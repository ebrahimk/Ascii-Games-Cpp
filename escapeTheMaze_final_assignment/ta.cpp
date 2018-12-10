#include<iostream>
#include<string>
#include"ta.hpp"
#include<cstdlib>

using namespace std;
 
/****************************************
 *Function:             TA()                                                   
 *Description:          TA object constructor 
 *Parameters:           N/A
 *Pre-conditions:       TA object initialized 
 *Post-conditions:      TA object created 
 *Return:               N/A
 *****************************************/

TA::TA(){
	row_loc =0;
	col_loc =0;
	appeased = false;
	counter = 10;
	floor = 0; 
}

/****************************************
 *Function:             set_location()           
 *Description:          sets the locaiton of object
 *Parameters:           int row, int col
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      row_loc and col_loc changed 
 *Return:               N/A
 *****************************************/

void TA::set_location(int row, int col){
	this-> row_loc =row;
	this-> col_loc =col;
}

/****************************************
 *Function:             get_row()                      
 *Description:          returns the row the object is located at      
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the row 
 *Return:               row_loc
 *****************************************/

int TA::get_row(){
	return this->row_loc;
}

/****************************************
 *Function:             get_col()                  
 *Description:          returns the col the object is located     
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the column 
 *Return:               int col_loc
 *****************************************/

int TA::get_col(){
	return this-> col_loc;
}
 
/****************************************
 *Function:  		counter_step()                                                  
 *Description:          decrements counters every turn, if zero ta no longer appeased 
 *Parameters:           N/A
 *Pre-conditions:       turn takes place
 *Post-conditions:      counter decrease by one or appeased equals false
 *Return:               N/A
 *****************************************/

void TA::counter_step(){
	if(this->counter > 0){
		this->counter--;
	}
	if(counter > 0)
		this->appeased = true;
	else{
		this-> appeased = false;
	}
}

/****************************************
 *Function:           	set_counter()                                    
 *Description:        	sets counter to 10
 *Parameters:           N/A
 *Pre-conditions:       students demonstrates skill
 *Post-conditions:      counter equals ten
 *Return:               N/A
 *****************************************/

void TA::set_counter(){
	this->	counter = 10; 
}

/****************************************
 *Function:             get_move()                      
 *Description:          returns a char based off the direction object moves     
 *Parameters:           N/A
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      returns char
 *Return:               char direction
 *****************************************/

char TA::get_move(){	
	int direction = rand()%4+1;
	if(direction == 1)
		return 'w' ;
	if(direction == 2)
		return 'd';
	if(direction == 3)
		return 's';
	if(direction == 4)
		return 'a';
}

/****************************************
 *Function:           	get_appeased()                                    
 *Description:        	returns the appeased status of a ta
 *Parameters:           N/A
 *Pre-conditions:       TA object initialized
 *Post-conditions:     	appeased returned 
 *Return:               bool appeased 
 *****************************************/

bool TA::get_appeased(){
	return this-> appeased;
}

/****************************************
 *Function:             set_floor()                            
 *Description:          sets the floor the object is located at    
 *Parameters:           int num
 *Pre-conditions:       Object created
 *Post-conditions:      floor changed 
 *Return:               N/A
 *****************************************/

void TA::set_floor(int f){
	this-> floor = f;
}

/****************************************
 *Function:             get_floor()                     
 *Description:          returns the floow the object is located at    
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      floor returned 
 *Return:               int floor
 *****************************************/

int TA::get_floor(){
	return this-> floor;
}

