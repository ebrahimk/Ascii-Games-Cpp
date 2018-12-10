#include<iostream> 
#include<string> 
#include"adventurer.hpp"

using namespace std; 
 
/***************************************
 *Function: 		Adventurer()                      
 *Description:         	constructor for Adventurer object
 *Parameters:          	N/A
 *Pre-conditions:       object called 
 *Post-conditions:      object created 
 *Return:               N/A
*****************************************/

Adventurer::Adventurer(){
	gold = false;
	arrows = 3;
}
 
/***************************************
 *Function:         	loose_arrow()       
 *Description:         	decrements arrow count
 *Parameters:          	N/A
 *Pre-conditions:       arrow int decreased 
 *Post-conditions:      N/A
 *Return:              	N/A
*****************************************/

void Adventurer::loose_arrow(){
	arrows--;
}

/***************************************
 *Function:        	get_arrows()       
 *Description:         	returns the number of arrows the player has 
 *Parameters:         	N/A
 *Pre-conditions:       N/A
 *Post-conditions:      int returned 
 *Return:               int arrows 
*****************************************/

int Adventurer::get_arrows(){
	return this-> arrows;
}

/***************************************
 *Function:        	set_gold()
 *Description:         	determines the found status of the gold 
 *Parameters:          	bool 
 *Pre-conditions:       N/A
 *Post-conditions:      status changed 
 *Return:               N/A
*****************************************/

void Adventurer::set_gold(bool tf){
	gold = true;
}

/***************************************
 *Function:          	get_gold()
 *Description:         	gets the gold bool
 *Parameters:          	N/A
 *Pre-conditions:       function called 
 *Post-conditions:     	N/A
 *Return:               bool gold 
*****************************************/

bool Adventurer::get_gold(){
	return this-> gold;  
}
