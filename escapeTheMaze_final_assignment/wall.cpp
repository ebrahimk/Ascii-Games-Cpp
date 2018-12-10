#include<iostream>
#include"Maze_Location.hpp"
#include"wall.hpp"
 
/****************************************
 *Function:            	Wall()                        
 *Description:          Constructor for Wall object
 *Parameters:           N/A
 *Pre-conditions:       Wall object declared
 *Post-conditions:      Wall object created 
 *Return:               N/A
 *****************************************/

Wall::Wall(){
	symbol = '#';
}
 
/****************************************
 *Function:             get_display_character()                              
 *Description:          returns symbol 
 *Parameters:           N/A
 *Pre-conditions:       funciton called
 *Post-conditions:      symbol member returned
 *Return:               char symbol
 *****************************************/

char Wall::get_display_character(){
	return this->symbol;
}
 
/****************************************
 *Function:             is_occupiable()
 *Description:          returns whether location is wall or openspace
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returned bool
 *Return:               return true
 *****************************************/

bool Wall::is_occupiable(){
	return false;
}

/****************************************
 *Function:             set_symbol()
 *Description:          set symbol member
 *Parameters:           char sym
 *Pre-conditions:       function called
 *Post-conditions:      symbol member changed
 *Return:               N/A
 *****************************************/

void Wall::set_symbol(char sym){
}

/****************************************
 *Function:             set_has_student()       
 *Description:          changes symbol to student and sets student status to true
 *Parameters:           bool tf
 *Pre-conditions:       function called 
 *Post-conditions:      location has student
 *Return:               N/A
 *****************************************/
 
void Wall::set_has_student(bool tf){
}

/****************************************
 *Function:             has_student()
 *Description:          checks to see if location has student
 *Parameters:           N/A
 *Pre-conditions:       location checked for student
 *Post-conditions:      returned bool
 *Return:               bool student
 *****************************************/

bool Wall::has_student(){
	return false;
}

/****************************************
 *Function:             set_has_ta()           
 *Description:          sets location to have ta
 *Parameters:           bool 
 *Pre-conditions:       location object initialized 
 *Post-conditions:      if true symbol changed 
 *Return:               N/A
 *****************************************/

void Wall::set_has_ta(bool tf){
}

/****************************************
 *Function:             has_ta()                
 *Description:          checks to see if location has ta 
 *Parameters:           N/A
 *Pre-conditions:       location  object initialized 
 *Post-conditions:      return bool
 *Return:               bool ta
 *****************************************/

bool Wall::has_ta(){
	return false;
}

/****************************************
 *Function:             set_has_instructor()            
 *Description:          sets location to have instructor 
 *Parameters:           bool 
 *Pre-conditions:       location object initialized 
 *Post-conditions:      location has instructor 
 *Return:               N/A
 *****************************************/

void Wall::set_has_instructor(bool tf){
}

/****************************************
 *Function:             has_instructor()                
 *Description:          checks to see if location has instructor 
 *Parameters:           N/A     
 *Pre-conditions:       location object initialized 
 *Post-conditions:      return bool
 *Return:               bool instructor 
 *****************************************/

bool Wall::has_instructor(){
	return false;
}

/****************************************
 *Function:             set_has_skill()   
 *Description:          sets location to have a skill
 *Parameters:           bool tf
 *Pre-conditions:       location object initialized  
 *Post-conditions:      if true location symbol changed 
 *Return:               N/A
 *****************************************/

void Wall::set_has_skill(bool tf){
}

/****************************************
 *Function:             has_skill()                
 *Description:          checks to see if location has skill 
 *Parameters:           N/A
 *Pre-conditions:       location object initialized     
 *Post-conditions:      return bool
 *Return:               bool skill 
 *****************************************/

bool Wall::has_skill(){
	return false;
}

/****************************************
 *Function:             set_has_start()                        
 *Description:          sets location to start 
 *Parameters:           bool tf
 *Pre-conditions:       function called
 *Post-conditions:      symbol changed
 *Return:               N/A
 *****************************************/

void Wall::set_has_start(bool tf){
}

/****************************************
 *Function:             has_start()                
 *Description:          checks to see if location is start 
 *Parameters:           N/A
 *Pre-conditions:       location checked 
 *Post-conditions:      returned bool
 *Return:               bool start 
 *****************************************/

bool Wall::has_start(){
	return false;
}

/****************************************
 *Function:             set_has_ladder()        
 *Description:          sets location to ladder
 *Parameters:           bool
 *Pre-conditions:       function called 
 *Post-conditions:      location symbol changed 
 *Return:               N/A
 *****************************************/

void Wall::set_has_ladder(bool tf){
}

/****************************************
 *Function:             has_ladder()                           
 *Description:          checks to see if location has ladder
 *Parameters:           N/A
 *Pre-conditions:       location object initialized     
 *Post-conditions:      end returned 
 *Return:               bool end
 *****************************************/

bool Wall::has_ladder(){
	return false;
}

