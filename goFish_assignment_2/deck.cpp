#include<iostream>
#include<algorithm>
#include"player.hpp"
#include<cstdlib>

using namespace std;
 
/***************************************
 *Function: 		Deck()          
 *Description:         	initializes array of cards 
 *Parameters:           N/A
 *Pre-conditions:       deck type initialized 
 *Post-conditions:      array of Card types created 
 *Return:               N/A
*****************************************/

Deck::Deck(){
n_cards =51;
}
 
/***************************************
 *Function: 		get_num_cards()          
 *Description:         	getter for the number of cards left in the deck 
 *Parameters:           N/A
 *Pre-conditions:       Deck type initialized   
 *Post-conditions:      number of cards returned 
 *Return:               number of cards left in the deck 
*****************************************/

int Deck::get_num_cards(){
return n_cards;
}
 
/***************************************
 *Function: 		initialize()          
 *Description:         	intializes all of the card rank and suit values of the deck 
 *Parameters:           N/A
 *Pre-conditions:       Deck type initialized   
 *Post-conditions:      Deck of Card types initialized  
 *Return:              	N/A
*****************************************/

void Deck::initialize(){
        int count = 13;
        for(int j = 1; j < 5; j++){
                for(int i = 1; i < 14 ; i++ ){
                        cards[count*(j-1)+(i-1)].set_rank(i);
                        cards[count*(j-1)+(i-1)].set_suit(j);
                }//Mad because im accessing private data for some cunty reason
        }
} 
 
/***************************************
 *Function:		shuffle()           
 *Description:         	shuffles the values of the initialized cards 
 *Parameters:           N/A 
 *Pre-conditions:       Deck type initialized
 *Post-conditions:      N/A
 *Return:               N/A
*****************************************/

void Deck::shuffle(){
        srand (time(NULL));
        for(int i =0; i<52; i++){
                swap(cards[rand()%52],  cards[rand()%52]);
        }
}
 
/***************************************
 *Function:  		draw()         
 *Description:         	takes a card from the last indeck in the deck and deletes the values 
 *Parameters:           N/A
 *Pre-conditions:       Deck type initialized 
 *Post-conditions:      N/A
 *Return:               returns card from the top of the deck 
*****************************************/

Card Deck::draw(){
        Card chosen;
        chosen = cards[n_cards];
        cards[n_cards].set_rank(0);
	cards[n_cards].set_suit(0);
	n_cards--;
                return chosen;
}

