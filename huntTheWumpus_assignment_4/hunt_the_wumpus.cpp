#include<iostream>
#include<string> 
#include"caves.hpp"
#include"adventurer.hpp" 
#include"useful_functions.hpp"
#include"event.hpp"
#include"wumpus.hpp"
#include"gold.hpp"
#include"pits.hpp"
#include"bats.hpp"
#include"empty.hpp"
#include"room.hpp"
#include<cstdlib>

using namespace std; 

int main(int argc, char** argv){
	srand(time(NULL));
	cout<<endl;
	int room_num = 0;  
	if(verify1(argv[1]) == true || convert1(argv[1]) > 5)
		room_num = convert1(argv[1]);
	else{
		cerr<< "Too few rooms"<<endl; 
		exit(0);
	}

	string response; 
	Cave dungeon(room_num); 
dungeon.exposition();
	int count = 1;
	int choice = 0; 
	bool  wumpus_dead = false; 
	while(count){

		dungeon.print_cave(); 
		dungeon.check_precepts();
		int t =1;
		while(t){
			cout<< "Would you like to move or fire an arrow? Enter a '1' to move and a '2' to shoot."<< endl; 
			cin >>  response;
			if(verify1(response) == false || convert1(response) > 2 || convert1(response) < 1){
				cout<<"Please enter either a 1 or 2. " <<endl; 
			}
			else{
				choice = convert1(response); 
				t = 0; 
			}
		} 
		if(choice == 1){
			dungeon.player_move();
		}
		else if(choice == 2){ 
			if(wumpus_dead == false){
				wumpus_dead = dungeon.shoot();	
			}
			else if(wumpus_dead == true){
				cout<<"The Wumpus has already been slain! You best not waste arrows!"<<endl; 
			}
		}
		if(dungeon.what_happens() ==false || dungeon.check_lose_arrows(wumpus_dead) == false || dungeon.check_same() == true){
			cout<<"You lose the game. " <<endl; 
			count = 0;
		}
		if( dungeon.win(wumpus_dead)== true){
			cout<<endl;
			dungeon.ending();
			cout<<"you win!!"<<endl; 
			count = 0;
		}
	}
	return 0; 

}
