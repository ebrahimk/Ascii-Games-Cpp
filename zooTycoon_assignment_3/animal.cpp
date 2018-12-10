#include<iostream> 
#include"animal.hpp" 

using namespace std; 

/***************************************
 *Function:		increase_age            
 *Description:          increases the age of a given animal by 1 
 *Parameters:           N/A
 *Pre-conditions:       method called on animal type 
 *Post-conditions:      animal age increased by one day 
 *Return:               N/A
*****************************************/

void Animal::increase_age(){
	age = age +1; 
}

/***************************************
 *Function:            get_age 
 *Description:         returns the age of an animal
 *Parameters:          N/A
 *Pre-conditions:      called on animal type 
 *Post-conditions:     N/A
 *Return:              age of animal 
*****************************************/

int Animal::get_age(){
	return this->age; 
}

/***************************************
 *Function:            set_living_status 
 *Description:         sets the living status to the argument
 *Parameters:          bool 
 *Pre-conditions:      changing the living status of an animal 
 *Post-conditions:     status is changed 
 *Return:              N/A
*****************************************/

void Animal::set_living_status(bool TF){
	alive = TF; 
}

/***************************************
 *Function:            get_living_status 
 *Description:         returns the living status of an animal 
 *Parameters:          N/A
 *Pre-conditions:      method is called 
 *Post-conditions:     N/A
 *Return:              bool true or false 
*****************************************/

bool Animal::get_living_status(){
	return this -> alive; 
}
