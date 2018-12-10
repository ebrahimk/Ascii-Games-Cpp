#include<iostream>
#include"instructor.hpp"
#include<string>

/****************************************
 *Function: 		Instructor()                                                   
 *Description:          Instructor object constructor 
 *Parameters:           N/A
 *Pre-conditions:       Instructor object initialized 
 *Post-conditions:      Instructor object created 
 *Return:               N/A
 *****************************************/

Instructor::Instructor(){
        this->row_loc = 0;
        this->col_loc =0;
	this->floor =2;
}

/****************************************
 *Function:             get_move()                      
 *Description:          returns a char based off the direction object moves     
 *Parameters:           N/A
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      returns char
 *Return:               char direction
 *****************************************/

char Instructor::get_move(){
        return 'n';
}

/****************************************
 *Function:             set_location()           
 *Description:          sets the locaiton of object
 *Parameters:           int row, int col
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      row_loc and col_loc changed 
 *Return:               N/A
 *****************************************/

void Instructor::set_location(int row, int col){
        this-> row_loc = row;
        this-> col_loc = col;
}

/****************************************
 *Function:             get_row()                      
 *Description:          returns the row the object is located at      
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the row 
 *Return:               row_loc
 *****************************************/

int Instructor::get_row(){
        return this-> row_loc;
}

/****************************************
 *Function:             get_col()                  
 *Description:          returns the col the object is located     
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the column 
 *Return:               int col_loc
 *****************************************/

int Instructor::get_col(){
        return this-> col_loc;
}

/****************************************
 *Function:             set_floor()                            
 *Description:          sets the floor the object is located at    
 *Parameters:           int num
 *Pre-conditions:       Object created
 *Post-conditions:      floor changed 
 *Return:               N/A
 *****************************************/

void Instructor::set_floor(int f){
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

int Instructor::get_floor(){
        return this-> floor;
}

