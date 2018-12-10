#include<iostream>
#include"card.hpp"

using namespace std;
 
/***************************************
 *Function:		Card()           
 *Description:         	Card class constructor 
 *Parameters:           N/A 
 *Pre-conditions:       Card type defined   
 *Post-conditions:      card suit and type intialized 
 *Return:               none 
*****************************************/

Card::Card(){
        rank = 1;
        suit = 1;
}
 
/***************************************
 *Function:		set_rank()           
 *Description:         	changes the value o private member rank
 *Parameters:           integer 
 *Pre-conditions:       Card type initialized  
 *Post-conditions:      rank in card changed 
 *Return:               N/A
*****************************************/

void Card::set_rank(int x){
this -> rank = x;
}
 
/***************************************
 *Function: 		set_suit()          
 *Description:         	sets the suit of given card 
 *Parameters:           integer 
 *Pre-conditions:       Card type intitialized  
 *Post-conditions:      suit of givenn card is changed 
 *Return:               N/A
*****************************************/

void Card::set_suit(int x){
this -> suit = x;
}

/***************************************
 *Function:           	get_rank()
 *Description:    	getter for the card rank      
 *Parameters:           N/A 
 *Pre-conditions:      	Card type initialized 
 *Post-conditions:      N/A
 *Return:              	rank of given card 
*****************************************/


int Card::get_rank(){
        return rank;
}
 
/***************************************
 *Function:              get_suit()
 *Description:         	 getter for given card suit 
 *Parameters:            N/A 
 *Pre-conditions:        Card type initialized 
 *Post-conditions:       N/A 
 *Return:                suit of given card 
*****************************************/

int Card::get_suit(){
        return suit;
}

