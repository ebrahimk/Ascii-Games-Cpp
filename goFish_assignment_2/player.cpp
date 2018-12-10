#include<iostream> 
#include"player.hpp"
#include<cstdlib> 

using namespace std; 

/***************************************
 *Function:		Player()
 *Description:		constructor for player class 
 *Parameters:		N/A
 *Pre-conditions:	Player type declared 
 *Post-conditions:	Player initialized 	
 *Return:		N/A
 *****************************************/

Player::Player() : n_books(0) {
	books = new int[13];  
}

/***************************************
 *Function:		~Player()
 *Description:		deletes dynamic array of book numbers 
 *Parameters:		N/A
 *Pre-conditions:	Player type declared 
 *Post-conditions:	N/A
 *Return:		N/A
 *****************************************/

Player::~Player(){
	delete [] books;
}

/***************************************
 *Function:		reveal_hand()
 *Description:		reveals the players hand 
 *Parameters:		N/A
 *Pre-conditions:	player type initialized 
 *Post-conditions:	player hand printed 
 *Return:		N/A
 *****************************************/

void Player::reveal_hand(){
	hand.reveal();
}

/***************************************
 *Function:		get_card_num()
 *Description:		returns the number of cards in a players hand 
 *Parameters:		N/A 
 *Pre-conditions:	function called 
 *Post-conditions:	hand number returned 
 *Return:		the number of cards in a players hand 
 *****************************************/

int Player::get_card_num(){
	return hand.get_num();
}

/***************************************
 *Function:		add_to_hand()
 *Description:		adds a card to a players hand
 *Parameters:		Card type 
 *Pre-conditions:	function called 
 *Post-conditions:	card slot in player hand array filled with  card from opponent hand 
 *Return:		N/A 
 *****************************************/

void Player::add_to_hand(Card new_card){	
	hand.set_hand(new_card);
}

/**************************** ***********
 *Function:		get_book_num()
 *Description:		returns the number of books from a given player 
 *Parameters:		N/A
 *Pre-conditions:	the function is called 
 *Post-conditions:	the number is returned 
 *Return:		returns the number of books owned by a given player 
 *****************************************/

int Player::get_book_num(){
	return n_books;
}

/***************************************
 *Function:		get_last()
 *Description:		returns the rank of the last card in a players hand 
 *Parameters:		N/A 
 *Pre-conditions:	function called 
 *Post-conditions:	the rank of the last card in a given players hand array is returned 
 *Return:		rank of last card in a given players hand array 
 *****************************************/

int Player::get_last(){
	return hand.get_rank_last(); 
}

/***************************************
*Function:		ask_human()
*Description:		simulates the player asking the computer for a card 
*Parameters:		N/A
*Pre-conditions:	Player type initialized 
*Post-conditions:	and integer corresponding to the rank the player wants is returned 
*Return:		integer corresponding to desired rank is returned 
*****************************************/

int Player::ask_human(){//verify and return the requested card rank 
	int t  =1;
	while(t){
		int count = 0;
		int request = 0;
		cout <<"What rank would you like to ask the computer for? Enter the rank here: ";
		cin >> request; 
		for(int i = 0; i < hand.get_num();i++){
			if(request == hand.get_rank_h(i)) 
				count  = 1;
		}
		if(count > 0){
			t = 0;
			return request;
		} 
		else{
			cout <<"You must request a the rank of a card which is in your hand already. " <<endl; 
		}
	}
}

/***************************************
*Function:		ask_pc()
*Description:		pc asks player for card type 
*Parameters:		N/A
*Pre-conditions:	player has taken a turn 
*Post-conditions:	N/A
*Return:		returns integer of a card rank in the pcs hand  
*****************************************/

int Player::ask_pc(){
	srand (time(NULL));
	int t = 1;
	int choice = rand()%hand.get_num(); 
	int rank_choice	= hand.get_rank_h(choice);
	cout<< "Give me all of your cards of rank " << rank_choice <<endl;
	return  rank_choice;
} 
 
/***************************************
*Function:		swap()
*Description:		calls swap hand function in hand.cpp
*Parameters:		location integer and array of cards to be filled with new cards 
*Pre-conditions:	player asked for a card 
*Post-conditions:	location array changed 
*Return:		N/A
*****************************************/

void Player::swap(int request, Card location []){
	hand.swap_hand(request, location);
}
 
/***************************************
*Function:		book_num_change()
*Description:		determines weather or not the player has a book, if so increments book number for that player 
*Parameters:		N/A
*Pre-conditions:	turn has taken place 
*Post-conditions:	book num incremented or not 
*Return:		N/A
*****************************************/

void Player::book_num_change(){ 
	if(hand.lay_book() == true){
		n_books++;
		cout <<"you got a book!" <<endl; 
		cout <<"you now have " << n_books <<" books."<<endl; 
	}
}
 
/***************************************
*Function:		boo_num_change2()
*Description:		changes book num for pc
*Parameters:		N/A
*Pre-conditions:	turn has been taken by pc 
*Post-conditions:	book number incremented or not 
*Return:		N/A
*****************************************/

void Player::book_num_change2(){
	if(hand.lay_book() == true){
		n_books++;
		cout <<"The computer got a book!" <<endl;
		cout <<"The computer now has " << n_books <<" books."<<endl;
	}
}




