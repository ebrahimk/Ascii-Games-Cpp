#include<iostream> 
#include"sloth.hpp"
#include<cstdlib>

using namespace std; 
 
/***************************************
 *Function:		Constructor for sloth class             
 *Description:        	initializes sloth class 
 *Parameters:           N/A
 *Pre-conditions:       class type declared 
 *Post-conditions:      sloth object created 
 *Return:               N/A
*****************************************/

Sloth::Sloth(){
	age = 0; 
	cost = 50;
	revenue = 200;
	alive = false; 
} 
 
/***************************************
 *Function:            Sloth
 *Description:         Parameteried constructor for sloth class 
 *Parameters:          int float int bool 
 *Pre-conditions:      type created 
 *Post-conditions:     object of type sloth made 
 *Return:              N/A
*****************************************/

Sloth::Sloth(int age, float cost, int revenue, bool alive){
	this -> age = age;
	this -> cost = cost; 
	this -> revenue = revenue; 
	this ->alive = alive;
}
 
/***************************************
 *Function:            food_cost()
 *Description:         generates cost of foo
 *Parameters:          N/A
 *Pre-conditions:      N/A
 *Post-conditions:     cost calculated 
 *Return:              cost 
*****************************************/

int Sloth::food_cost(){
	float multiplier = rand()%50;
	float multi = (multiplier/100)+.75;
	cost = cost * multi;
	return cost;
}
 
/***************************************
 *Function:            set_adult_status 
 *Description:         sets adult status 
 *Parameters:          N/A
 *Pre-conditions:      function gets called 
 *Post-conditions:     yes 
 *Return:              N/A
*****************************************/

void Sloth::set_adult_status(){
	if(age > 1095){
		revenue = 100;
	}
}
 
/***************************************
 *Function:            get_rev
 *Description:         gets the revenue 
 *Parameters:          N/A
 *Pre-conditions:      function gets called 
 *Post-conditions:     revenue returned 
 *Return:              N/A
*****************************************/

int Sloth::get_rev(){
	return this-> revenue; 
}
