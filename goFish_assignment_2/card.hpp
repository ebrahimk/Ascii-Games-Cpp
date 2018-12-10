#include<iostream>
#pragma once
class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:
        Card();
        void set_rank(int x);
        void set_suit(int x);
        int get_rank();
        int get_suit();
};
