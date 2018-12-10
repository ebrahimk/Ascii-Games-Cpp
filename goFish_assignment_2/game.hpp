#include<iostream>
#include"player.hpp"

#pragma once 

class Game {
  private:
    Deck cards;
    Player players[2];
  public:
	Game();
	//~Game(); 
	void p1_show_hand();	
	void deal_p1();
	void deal_p2();
	void winner();
	bool over();
	void p2_turn();
	void p1_turn();
};
