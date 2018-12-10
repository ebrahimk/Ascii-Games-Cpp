//#include"card.hpp"
#include"deck.hpp"
#pragma once
class Hand {
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand.
  public:
        Hand();
        ~Hand();	
        void set_hand(Card dealt); 
	void reveal();// 
	int get_rank_last();
	int get_num();
	int get_rank_h(int x);
	void swap_hand(int x, Card location []);
	bool lay_book();
};
