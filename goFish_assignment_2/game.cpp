#include<iostream>
#include"player.hpp"
#include"game.hpp"


using namespace std; 
 
/***************************************
 *Function: 		Game()
 *Description:		initializes deck  
 *Parameters:		N/A
 *Pre-conditions:	Game type declared 
 *Post-conditions:	deck initialized 
 *Return:		N/A
*****************************************/

Game::Game(){
	cards.initialize();
	cards.shuffle();	
}
 
/***************************************
 *Function:		p1_show_hand()
 *Description:		reveals player 1 hand
 *Parameters:		N/A
 *Pre-conditions:	game type declared 
 *Post-conditions:	hand printed 
 *Return:		N/A
*****************************************/

void Game::p1_show_hand(){
	players[0].reveal_hand();
}
 
/***************************************
 *Function:		over()
 *Description:		determines weather all the cards in the deck have been consumed 
 *Parameters:		N/A
 *Pre-conditions:	a turn has taken place 
 *Post-conditions:	N/A
 *Return:		true or false 
*****************************************/

bool Game::over(){
	if(cards.get_num_cards() == 0)
		return false;
	else 
		return true;
}
 
/***************************************
 *Function:		p1_turn
 *Description:		this function simulates player 1 turn
 *Parameters:		N/A
 *Pre-conditions:	game type is declared 
 *Post-conditions:	player one turn has occured 
 *Return:		N/A
*****************************************/

void Game::p1_turn(){
	Card* exchange = new Card[52];
	int t = 1;
	if(players[0].get_card_num() == 0){	// If the players hand is empty the y must draw a card 
		cout <<"you hand is empty, you draw a card."<<endl; 
		players[0].add_to_hand(cards.draw());
	}
	while(t == 1){
		int request = players[0].ask_human();	// determine the rank the player wants 
		players[1].swap(request, exchange);	//Send array in to fetch those cards/determinie if they exist 
		if(exchange[0].get_rank()== 0){
			cout<<"GO FISH." <<endl;  
			players[0].add_to_hand(cards.draw());			
			players[0].book_num_change();
			if(players[0].get_last()== request){ //check to see if the card drawn matches if not t =0;
				cout << "You drew a card with the rank you called! you get to go again! Here is your hand now: " <<endl; 	
				players[0].reveal_hand();
			}
			else{	//pass the turn
				cout <<"you did not draw a card of you chosen rank. "<<endl; 
				t = 0; 
			}
		}
		else{	//if player had declared rank 
			cout<<"Your opponent had cards of the selected rank. This is your current hand, you get to go again." <<endl; 
			for(int i = 0; i< exchange[51].get_rank(); i++){  // i needs to be equal to the number of cards oppent had that were valid 
				players[0].add_to_hand(exchange[i]);

			}
			players[0].book_num_change();
			players[0].reveal_hand();
		}

	}
	delete [] exchange; 
	players[0].reveal_hand();
}
 
/***************************************
 *Function:		p2_turn()
 *Description:		simulates the computers turn
 *Parameters:		N/A
 *Pre-conditions:	player one has gone 
 *Post-conditions:	computer takes turn  
 *Return:		N/A
*****************************************/

void Game::p2_turn(){
	Card* exchange = new Card[52];
	int t = 1;
        if(players[1].get_card_num() == 0){
                cout <<"The computers hand is empty, it draws a card."<<endl;
                players[1].add_to_hand(cards.draw());
        }
	while(t == 1){
		int request = players[1].ask_pc();
		players[0].swap(request, exchange);
		if(exchange[0].get_rank() == 0){ 
			cout<< "You dont have any of the called rank, the computer has to GO FISH!" <<endl;
			players[1].add_to_hand(cards.draw());
			players[1].book_num_change2();
			if(players[1].get_last() == request){ 
				cout <<"The computer drew a card of their requested rank! The computer gets to go again! " <<endl; 	
			}
			else{
				cout<< "The computer did not draw a card of their requested rank. It's your turn! "<<endl; 
				t = 0; 
			}
		}
		else{
			cout<<"You had cards of the called rank, hand em' over!" <<endl;
			for(int i = 0; i< exchange[51].get_rank(); i++){
				players[1].add_to_hand(exchange[i]);

			}
			players[0].reveal_hand();
			players[1].book_num_change2();
		}
	}	
	delete [] exchange;
}

/***************************************
 *Function:		deal_p1()
 *Description:		deals a card from the top of the deck to player 1 
 *Parameters:		N/A
 *Pre-conditions:	game started 
 *Post-conditions:	player is dealt a card 
 *Return:		N/A
*****************************************/

void Game::deal_p1(){
	players[0].add_to_hand(cards.draw());
}
 
/***************************************
 *Function:		deal_p2()
 *Description:		deals a card to player 2 
 *Parameters:		N/A
 *Pre-conditions:	game started 
 *Post-conditions:	computer is dealt a card 
 *Return:		N/A
*****************************************/

void Game::deal_p2(){
	players[1].add_to_hand(cards.draw());
}
 
/***************************************
 *Function:		winner()
 *Description:		compares the number of books the player and the computer have 
 *Parameters:		N/A
 *Pre-conditions:	the card sin the deck equa zero
 *Post-conditions:	one player wins 	
 *Return:		N/A
*****************************************/

void Game::winner(){
	if(players[0].get_book_num() > players[1].get_book_num())
		cout << "You win!" <<endl;
	else if(players[0].get_book_num() < players[1].get_book_num())
		cout <<"You lose!" <<endl;
	else{
		cout <<"Its a draw!" <<endl;
	}
}
