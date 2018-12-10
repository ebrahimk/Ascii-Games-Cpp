#include<iostream>
#include<string>
#include"OpenSpace.hpp"
#include"Maze_Location.hpp"
 
/****************************************
 *Function:          	OpenSpace                        
 *Description:          Constructor for OpenSpace object
 *Parameters:         	N/A
 *Pre-conditions:     	OpenSpace object declared
 *Post-conditions:     	OpenSpace object created 
 *Return:             	N/A
 *****************************************/

OpenSpace::OpenSpace(): occupied(true),student(false), instructor(false),ta(false), skill(false),  start(false), end(false){
	symbol = ' ';
}
 
/****************************************
 *Function:  		get_display_character()                              
 *Description:       	returns symbol 
 *Parameters:        	N/A
 *Pre-conditions:    	funciton called
 *Post-conditions:     	symbol member returned
 *Return:               char symbol
 *****************************************/

char OpenSpace::get_display_character(){
	return this-> symbol;
}
 
/****************************************
 *Function:             set_symbol()                   
 *Description:       	set symbol member
 *Parameters:        	char sym
 *Pre-conditions:    	function called
 *Post-conditions:     	symbol member changed 
 *Return:               N/A
 *****************************************/

void OpenSpace::set_symbol(char sym){
	this->symbol = sym;
}
 
/****************************************
 *Function:           	is_occupiable()                
 *Description:       	returns whether location is wall or openspace 
 *Parameters:        	N/A
 *Pre-conditions:    	function called
 *Post-conditions:     	returned bool
 *Return:               return true 
 *****************************************/

bool OpenSpace::is_occupiable(){
	return true;
}

/****************************************
 *Function:          	set_has_student()       
 *Description:       	changes symbol to student and sets student status to true
 *Parameters:        	bool tf
 *Pre-conditions:    	function called 
 *Post-conditions:     	location has student
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_student(bool tf){
	this-> student = tf;
	if(student == true){
		this->symbol = '*';
	}
	else if(student == false){
		this->symbol = ' ';
	}
}

/****************************************
 *Function:		has_student()                                
 *Description:       	checks to see if location has student
 *Parameters:        	N/A
 *Pre-conditions:    	location checked for student
 *Post-conditions:     	returned bool
 *Return:               bool student
 *****************************************/

bool OpenSpace::has_student(){
	return this -> student;
}

/****************************************
 *Function:        	set_has_start()                        
 *Description:       	sets location to start 
 *Parameters:        	bool tf
 *Pre-conditions:    	function called
 *Post-conditions:     	symbol changed
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_start(bool tf){
	this -> symbol = '@';
	this -> start = tf;
}

/****************************************
 *Function:           	has_start()                
 *Description:       	checks to see if location is start 
 *Parameters:        	N/A
 *Pre-conditions:    	location checked 
 *Post-conditions:     	returned bool
 *Return:               bool start 
 *****************************************/

bool OpenSpace::has_start(){
	return start;
}

/****************************************
 *Function:           	set_has_ladder()        
 *Description:       	sets location to ladder
 *Parameters:        	bool
 *Pre-conditions:    	function called 
 *Post-conditions:     	location symbol changed 
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_ladder(bool tf){
	this -> symbol = '^';
	this -> end = tf;
}

/****************************************
 *Function:     	has_ladder()                           
 *Description:       	checks to see if location has ladder
 *Parameters:        	N/A
 *Pre-conditions:    	location object initialized 	
 *Post-conditions:     	end returned 
 *Return:               bool end
 *****************************************/

bool OpenSpace::has_ladder(){
	return end;
}

/****************************************
 *Function:          	set_has_ta()           
 *Description:       	sets location to have ta
 *Parameters:        	bool 
 *Pre-conditions:    	location object initialized 
 *Post-conditions:     	if true symbol changed 
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_ta(bool tf){
	this->ta = tf;
	if(ta == true){
		this->symbol = 'T';
	}
	else if(ta == false){
		this->symbol = ' ';
	}
}

/****************************************
 *Function:         	has_ta()                
 *Description:       	checks to see if location has ta 
 *Parameters:        	N/A
 *Pre-conditions:    	location  object initialized 
 *Post-conditions:     	return bool
 *Return:               bool ta
 *****************************************/

bool OpenSpace::has_ta(){
	return this-> ta; 
}

/****************************************
 *Function:          	set_has_instructor()            
 *Description:       	sets location to have instructor 
 *Parameters:        	bool 
 *Pre-conditions:    	location object initialized 
 *Post-conditions:     	location has instructor 
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_instructor(bool tf){
	this->instructor = tf;
	this->symbol = 'I';
}

/****************************************
 *Function:           	has_instructor()                
 *Description:       	checks to see if location has instructor 
 *Parameters:        	N/A	
 *Pre-conditions:    	location object initialized 
 *Post-conditions:     	return bool
 *Return:               bool instructor 
 *****************************************/

bool OpenSpace::has_instructor(){
	return this-> instructor;
}

/****************************************
 *Function:        	set_has_skill()   
 *Description:       	sets location to have a skill
 *Parameters:        	bool tf
 *Pre-conditions:    	location object initialized  
 *Post-conditions:     	if true location symbol changed 
 *Return:               N/A
 *****************************************/

void OpenSpace::set_has_skill(bool tf){
	this->skill = tf;

	if(skill == true){
		this->symbol = '$';
	}
	else if(skill == false){
		this->symbol = ' ';
	}
}

/****************************************
 *Function:           	has_skill()                
 *Description:       	checks to see if location has skill 
 *Parameters:        	N/A
 *Pre-conditions:    	location object initialized 	
 *Post-conditions:     	return bool
 *Return:               bool skill 
 *****************************************/

bool OpenSpace::has_skill(){
	return this-> skill;
}
