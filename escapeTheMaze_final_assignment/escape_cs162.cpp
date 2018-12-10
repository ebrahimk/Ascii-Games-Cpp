#include<iostream>
#include<string>
#include"maze.hpp"
#include<cstdlib>

using namespace std; 

int main(){
	srand(time(NULL));
	Maze* CS162;
	int no_win = 2;	

		while(no_win == 2){

			CS162 = new Maze;
			no_win = 3;
			CS162->display();
			while(no_win == 3){
				CS162->turn();
				CS162->turn_ta();
				CS162->check_ta();
				CS162->set_symbols();
				CS162->display();
				no_win = CS162->check_win();
			}
			delete CS162;
		}	
	return 0;
}
