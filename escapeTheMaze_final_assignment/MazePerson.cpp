#include<iostream>
#include"MazePerson.hpp"
 
/****************************************
 *Function:		MazePerson()                                          
 *Description:          constructor for MazePerson object	
 *Parameters:           N/A
 *Pre-conditions:       MazePerson object declared 
 *Post-conditions:      Mazeperson object created 
 *Return:              	N/A
 *****************************************/

MazePerson::MazePerson(){
	this-> row_loc = 0;
	this-> col_loc =0;
	this-> floor =0;
}

/****************************************
 *Function:         	get_move()                      
 *Description:          returns a char based off the direction object moves     
 *Parameters:           N/A
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      returns char
 *Return:               char direction
 *****************************************/

char MazePerson::get_move(){
}

/****************************************
 *Function:           	set_location()           
 *Description:          sets the locaiton of object
 *Parameters:           int row, int col
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      row_loc and col_loc changed 
 *Return:               N/A
 *****************************************/

void MazePerson::set_location(int row,int col){
}

/****************************************
 *Function:           	get_row()                      
 *Description:          returns the row the object is located at      
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the row 
 *Return:               row_loc
 *****************************************/

int  MazePerson::get_row(){
	return 0;
}

/****************************************
 *Function:           	get_col()                  
 *Description:         	returns the col the object is located     
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the column 
 *Return:               int col_loc
 *****************************************/

int MazePerson::get_col(){
	return 0;
}

/****************************************
 *Function:            	get_floor()                     
 *Description:      	returns the floow the object is located at    
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      floor returned 
 *Return:               int floor
 *****************************************/

int MazePerson::get_floor(){
	return 0;
}

/****************************************
 *Function:          	set_floor()                            
 *Description:         	sets the floor the object is located at    
 *Parameters:           int num
 *Pre-conditions:       Object created
 *Post-conditions:      floor changed 
 *Return:               N/A
 *****************************************/

void MazePerson::set_floor(int num){
}

