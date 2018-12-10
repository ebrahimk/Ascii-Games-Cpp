#include<iostream>
#include"player.hpp"


using namespace std;

/***************************************
 *Function:		Hand()
 *Description:		initializes an array of Card types 
 *Parameters:		N/A
 *Pre-conditions:	Hand type is created 
 *Post-conditions:	hand array initialized 
 *Return:		N/A
*****************************************/

Hand::Hand(): n_cards(0) {
	this -> cards = new Card[52];
}
 
/***************************************
 *Function:		reveal()
 *Description:		prints the hand 
 *Parameters:		N/A
 *Pre-conditions:	Hand type declared 
 *Post-conditions:	N/A
 *Return:		N/A
*****************************************/

void Hand::reveal(){
	cout << "The first number is the rank, the second number is the suit. "<<endl;
	for(int i = 0 ; i< n_cards; i++){
		cout<< "Card number " << i+1 << ": ";
		cout<< this ->cards[i].get_rank() <<", " <<this -> cards[i].get_suit() <<endl;

	}
}
 
/***************************************
 *Function:		get_num()
 *Description:		returns the number of cards in a given hand 
 *Parameters:		N/A
 *Pre-conditions:	N/A 
 *Post-conditions:	N/A
 *Return:		returns the number of cards in a given hand
*****************************************/

int Hand::get_num(){
	return n_cards;
}
 
/***************************************
 *Function:		Hand()
 *Description:		deletes the memory created by the hand class 
 *Parameters:		N/A
 *Pre-conditions:	N/A
 *Post-conditions:	hand array deleted 
 *Return:		N/A
*****************************************/

Hand::~Hand(){
	delete [] cards;
}
 
/***************************************
 *Function:		get_rank_h()
 *Description:		returns the rank of a desired card
 *Parameters:		integer 
 *Pre-conditions:	hand type declared 
 *Post-conditions:	N/A 
 *Return:		card at some desired index values rank 
*****************************************/

int Hand::get_rank_h(int x){
   return cards[x].get_rank();
   }
 
/***************************************
 *Function:		get_rank_last()
 *Description:		returns rank of the last card in the hand 
 *Parameters:		N/A
 *Pre-conditions:	function gets called 
 *Post-conditions:	returns rank of the last card in the hand array 
 *Return:		last rank of the card in the hand array
*****************************************/

int Hand::get_rank_last(){
return cards[n_cards-1].get_rank();
}
 
/***************************************
 *Function:		set_hand()
 *Description:		sets the values of the Card in the last hand index 
 *Parameters:		Card type 
 *Pre-conditions:	Hand type declared 
 *Post-conditions:	N/A 
 *Return:		N/A
*****************************************/

void Hand::set_hand(Card dealt){
	this -> cards[n_cards] = dealt;
	n_cards ++;

}
 
/***************************************
 *Function:		swap_hand() 
 *Description:		fills dynamic array with the card which are to be transferred 
 *Parameters:		integer and intermediate array of cards 
 *Pre-conditions:	player called rank the opponent has 
 *Post-conditions:	parameter array filled with valid cards 	
 *Return:		N/A
*****************************************/

void  Hand::swap_hand(int x, Card location []){
	for(int i = 0; i < 52; i++){
		location[i].set_rank(0);
		location[i].set_suit(0); 
	}

	int c =0;
	for(int i =0; i < n_cards+1 ; i++){
		if(cards[i].get_rank() == x){
			location[c].set_rank(cards[i].get_rank());
			location[c].set_suit(cards[i].get_suit()); 
			cards[i].set_rank(0);
			cards[i].set_suit(0);
			c++; //this cannot trigger more than 3 times 	
			n_cards--; 
		}
	}
	location[51].set_rank(c);
	for(int j = 0; j <3; j++){
		for(int i = 0; i < n_cards+1; i++){
			if(cards[i].get_rank() ==0 && cards[i].get_suit() ==0){
				cards[i].set_rank(cards[i+1].get_rank()); 
				cards[i].set_suit(cards[i+1].get_suit());
				cards[i+1].set_rank(0);
				cards[i+1].set_suit(0); 
			}
		}
	}
}

/***************************************
 *Function:		lay_book()
 *Description:		determines weather or not a book is present in a given hand 
 *Parameters:		N/A
 *Pre-conditions:	turn is completed 
 *Post-conditions:	N/A 
 *Return:		N/A
*****************************************/

bool Hand::lay_book(){
	int c = n_cards; 
	int tf = 0;
	int t = n_cards;
	int check_mark = n_cards; 
	while(t>0){
		int count = 0;//steps through hand and determines if their are at least four cards of the same rank 
		for(int i =0; i < n_cards; i++){	
			if(cards[c].get_rank() == cards[i].get_rank()){ 	
				count++;
			}
		}
		if(count == 4){ //If we have a book we go through and remove those cards from the hand 
			for(int j = 0; j < n_cards; j++){
				if(cards[c].get_rank() == cards[j].get_rank()){
					cards[j].set_rank(0);
					cards[j].set_suit(0); 
				}
			} 
			n_cards =n_cards - 4; 
			t = 0;
			tf = 1;
		}
		else{
			c--;
		}
		t--; 
	} 

	for(int j = 0; j < 3; j++){	
		for(int i = 0; i < check_mark; i++){ //squishes the hand to the first portion of the array
			if(cards[i].get_rank() ==0 && cards[i].get_suit() ==0){
				cards[i].set_rank(cards[i+1].get_rank());
				cards[i].set_suit(cards[i+1].get_suit());
				cards[i+1].set_rank(0);
				cards[i+1].set_suit(0);

			}
		}
	} 
	if(tf == 0)
		return false; 
	else if(tf == 1)
		return true;
}

