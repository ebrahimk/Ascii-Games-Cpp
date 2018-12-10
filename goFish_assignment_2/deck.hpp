#include<iostream>
#include"card.hpp"
#pragma once
class Deck {
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
        Deck();
	int get_num_cards();
        void initialize();
        void shuffle();
        Card draw();
        int draw_rank();
        int draw_suit();
};

