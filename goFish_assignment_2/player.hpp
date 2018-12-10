#include<iostream> 
#include"./card.hpp"
//#include"deck.hpp"
#include"hand.hpp"

#pragma once
class Player {
  private:
    Hand hand;
    int* books;  // Array with ranks for which the player has books.
    int n_books;
  public:
	Player();
	~Player();
	Hand get_hand();
	void add_to_hand(Card new_card)	;
	void reveal_hand();
	//void check_book(int x);
	int get_last();
	int get_book_num();
	int ask_human();
	int ask_pc();
	void swap(int x, Card location []);
	void book_num_change();
	void book_num_change2();
	int get_card_num();
};
	
//bool check();
	//void turn();
	  // must have constructors, destructor, accessor methods, and mutator methods


