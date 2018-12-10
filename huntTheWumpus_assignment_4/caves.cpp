#include<iostream>
#include<string>
#include"caves.hpp"
#include"adventurer.hpp"
#include"event.hpp"
#include"bats.hpp" 
#include"pits.hpp"
#include"gold.hpp"
#include"wumpus.hpp"
#include"empty.hpp"
#include<cstdlib>

using namespace std;

/****************************************
 *Function: 		verify                      
 *Description:          verifies string to see if int
 *Parameters:          	string input
 *Pre-conditions:      	N/A
 *Post-conditions:      return true or false 
 *Return:               bool
 *****************************************/

bool verify(string str_input){

	int a;
	for(a=0; a <str_input.length(); a++){
		if (str_input.at(a) >= '0' && str_input.at(a) <= '9'){
			return true;
		}
		else {

			return false;
		}
	}
}

/****************************************
 *Function:		convert                       
 *Description:          converts string to int 
 *Parameters:          	string
 *Pre-conditions:       called
 *Post-conditions:      return converted string
 *Return:               int 
 *****************************************/

int convert(string ver){
	float val_final;
	val_final  = atoi(ver.c_str());
	return (val_final);
}

/****************************************
 *Function:              Cave constructor       
 *Description:           creates a vector of room objects
 *Parameters:          	 number of rows 
 *Pre-conditions:        cave object created 
 *Post-conditions:       N/A
 *Return:                N/A
 *****************************************/

Cave::Cave(int num): room_num(num){
	srand(time(NULL));
	for (int i = 0; i < room_num; i++ ) {
		vector<Room*> row;
		for (int j = 0; j < room_num; j++) {
			row.push_back(new Room);
		}
		network.push_back(row);
	}

	int t = 2;
	while(t){
		int row = rand()%room_num;
		int col = rand()%room_num;
		if(network[row][col]->get_event_type() == 5){
			//delete network[row][col]->get_event();
			network[row][col]->set_room(new Pits);
			//network[row][col]->set_dimension(" p ");//delete this when you are done 
			t--;
		}
	}

	t = 2;
	while(t){
		int row2 = rand()%room_num;
		int col2 = rand()%room_num;
		if(network[row2][col2]->get_event_type() == 5){
			// delete network[row2][col2]->get_event();
			network[row2][col2]->set_room(new Bats);
			//network[row2][col2]->set_dimension(" b ");//delete this when you are done 
			t--;
		}
	}

	t = 1;
	while(t){
		int row3 = rand()%room_num;
		int col3 = rand()%room_num;
		if(network[row3][col3]->get_event_type() == 5){
			//delete network[row3][col3]->get_event();
			network[row3][col3]->set_room(new Gold);
				
			//network[row3][col3]->set_dimension(" g ");//delete this when you are done 
			t =0 ;
		}
	}

	t = 1;
	while(t){
		int row4 = rand()%room_num;
		int col4 = rand()%room_num;
		if(network[row4][col4]->get_event_type() == 5){
			//delete network[row4][col4]->get_event();
			network[row4][col4]->set_room(new Wumpus);
			wump_row = row4;
			wump_col = col4;
			//network[row4][col4]->set_dimension(" w ");//delete this when you are done 
			t =0 ;
		}
	}

	t = 1;
	while(t){
		int row5 = rand()%room_num;
		int col5 = rand()%room_num;
		if(network[row5][col5]->get_event_type() == 5){
			network[row5][col5]->set_dimension(" x ");
			rope_row = row5;
			rope_col = col5;
			location_row = row5;
			location_col = col5;
			t =0;                        
		}
	}
}

/****************************************
 *Function:		~Cave()                       
 *Description:          deletes the memory allocated by the cave
 *Parameters:          	N/A
 *Pre-conditions:       N/A
 *Post-conditions:      memory freed 
 *Return:               N/A
 *****************************************/

Cave::~Cave(){
	for(int i = 0; i < room_num; i++){
		for(int j = 0; j < room_num ; j++){
			delete  network[i][j]; 
		}
	}
} 

/****************************************
 *Function:        	player_move()       
 *Description:          moves the player
 *Parameters:          	N/A
 *Pre-conditions:       player choses to move
 *Post-conditions:      moves the player
 *Return:               N/A
 *****************************************/

void Cave::player_move(){

	string response;
	int direction = 0;
	int t = 1;
	while(t){
		cout<<"Which direction would you like to move? Enter a '1' for north a '2' for east, a '3' for south and a '4' for west."<<endl;
		cin>> response;
		if(verify(response) == false || convert(response) < 1 || convert(response) > 4){
			cout<<"Please enter either a 1, 2, 3, or 4. "<<endl;
		}

		else{
			t = 0;
			direction = convert(response);
		}
	}
	if(direction == 1){ //Corresponds to north
		if(location_row  > 0){
			network[location_row][location_col]->set_dimension("|_|");
			network[location_row-1][location_col]->set_dimension(" x ");
			location_row--;
		}
		else{
			cout<<"There is no cave north of you. "<<endl;
		}
	}
	if(direction == 3){ //Corresponds to south
		if(location_row < room_num-1){
			network[location_row][location_col]->set_dimension("|_|");
			network[location_row+1][location_col]->set_dimension(" x ");
			location_row++;
		}
		else{
			cout<<"There is no cave south of you."<<endl;
		}
	}
	if(direction == 4){ //Corresponds to west
		if(location_col  > 0){
			network[location_row][location_col]->set_dimension("|_|");
			network[location_row][location_col-1]->set_dimension(" x ");
			location_col--;
		}	
		else{
			cout<<"There is no cave west of you."<<endl;
		}
	}
	if(direction == 2){ //Corresponds to east
		if(location_col < room_num-1){
			network[location_row][location_col]->set_dimension("|_|");
			network[location_row][location_col+1]->set_dimension(" x ");
			location_col++;
		}
		else{
			cout<<"There is no cave east of you." <<endl;  
		}
	}
}

/****************************************
 *Function:        	check_precepts()       
 *Description:          checks the surrounding rooms for precepts 
 *Parameters:          	N/A
 *Pre-conditions:       turn takes place
 *Post-conditions:      N/A 
 *Return:               N/A
 *****************************************/

void Cave::check_precepts(){ 
	if(location_row == room_num-1  && location_col < room_num-1 && location_col > 0){     //south middle
		cout<< 	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row-1][location_col]->get_precept()<<endl;
	}

	if(location_row == room_num-1 && location_col == room_num-1){        //bottom right
		cout<<	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<	network[location_row-1][location_col]->get_precept()<<endl;
	}

	if(location_row == room_num-1 && location_col == 0){              //bottum left 
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row-1][location_col]->get_precept()<<endl;
	}

	if(location_row == 0 && location_col < room_num-1 && location_col > 0){           // top middle
		cout<<	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row+1][location_col]->get_precept()<<endl;

	}

	if(location_row == 0 && location_col == room_num-1){              //top right
		cout<<	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<	network[location_row+1][location_col]->get_precept()<<endl;
	}

	if(location_row == 0 && location_col == 0){                     //top left 
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row+1][location_col]->get_precept()<<endl;

	}

	if(location_row > 0 && location_row < room_num-1  && location_col == 0){                  //west middle 
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row-1][location_col]->get_precept()<<endl;
		cout<<	network[location_row+1][location_col]->get_precept()<<endl;
	}

	if(location_row > 0 && location_row < room_num-1 && location_col == room_num-1){            //east middle 
		cout<<	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<	network[location_row-1][location_col]->get_precept()<<endl;
		cout<<	network[location_row+1][location_col]->get_precept()<<endl;
	}
	else if(location_row > 0 && location_row <room_num -1 && location_col > 0 && location_col < room_num-1){
		cout<<	network[location_row][location_col+1]->get_precept()<<endl;
		cout<<	network[location_row][location_col-1]->get_precept()<<endl;
		cout<<  network[location_row-1][location_col]->get_precept()<<endl;
		cout<<  network[location_row+1][location_col]->get_precept()<<endl;

	}	
}

/****************************************
 *Function:        	check_same()       
 *Description:          checks to see if the bats dropped you in the wumpus square 
 *Parameters: 		N/A         
 *Pre-conditions:       N/A
 *Post-conditions:      N/A
 *Return:               bool
 *****************************************/

bool Cave::check_same(){
	int act = network[location_row][location_col]->check();
	if(act == 1 || act == 2){
		return true; 
	}
	else{
		return false;
	}
}

/****************************************
 *Function:        	what_happens()      
 *Description:          determines what happens based off players location
 *Parameters:          	N/A
 *Pre-conditions:       turn took place 
 *Post-conditions:      event is triggered 
 *Return:               bool
 *****************************************/

bool Cave::what_happens(){                                                      //called after player moves in turn 
	int action = network[location_row][location_col]->check();
	if(action == 1){
		network[location_row][location_col]->message(); //message for the thing 
		return false;
	}
	if(action == 3){
		network[location_row][location_col]->message();
		return false;
	}
	if(action == 2){
		network[location_row][location_col]->message();
		network[location_row][location_col]->set_dimension("|_|");
		location_row = rand()%room_num;
		location_col = rand()%room_num;                 //call this function twice in a row 
		network[location_row][location_col]->set_dimension(" x ");

		return true;
	}
	if(action == 4){
		network[location_row][location_col]->message();
		network[location_row][location_col]->set_room(new Empty);
		hero.set_gold(true);
		return true;
	}
	else{
		return true;
	}
}

/****************************************
 *Function:       	shoot()                
 *Description:          simulates shooting an arrow 
 *Parameters:          	N/A
 *Pre-conditions:       player chooses to shoot instead of move
 *Post-conditions:      killed wupus or not 
 *Return:               bool
 *****************************************/

bool Cave::shoot(){                                     //called if player decides to shoot instead of move 
	int killed = 2;
	string response;
	int direction = 0;
	int t = 1;
	while(t){
		cout<<"Which direction would you like to fire an arrow? Enter a '1' for north a '2' for east, a '3' for south and a '4' for west."<<endl;
		cin>> response;
		if(verify(response) == false || convert(response) < 1 || convert(response) > 4){
			cout<<"Please enter either a 1, 2, 3, or 4. "<<endl;
		}

		else{
			t = 0;
			direction = convert(response);
		}
	}
	cout<<"THWANG.... You loose an arrow into the dark."<<endl;
	int distance = 3;
	if(direction == 1){
		if(location_row < 3) //iterate 
			distance = location_row;
		//cout<<"This is distance: " <<  distance  <<endl;
		for(int i  = 0; i < distance; i++){
			if(network[location_row-i-1][location_col]->get_event_type() == 1){
				cout<<"THUD!!!! You hear a terrible howl. The Wumpus has been slain!"<<endl;
				killed = 1;
			}
		}
	}
	if(direction == 2){
		if(location_col > room_num-4)
			distance = room_num - location_col-1;
		//cout<<"This is distance: " <<  distance  <<endl;
		for(int i  = 0; i < distance; i++){
			if(network[location_row][location_col+i+1]->get_event_type() == 1){
				cout<<"THUD!!!! You hear a terrible howl. The Wumpus has been slain!"<<endl;
				killed = 1;
			}
		}
	}
	if(direction == 3){
		if(location_row > room_num-4)
			distance = room_num - location_row -1;
		//cout<<"This is distance: " <<  distance  <<endl;
		for(int i  = 0; i < distance; i++){
			if(network[location_row+i+1][location_col]->get_event_type() == 1){
				cout<<"THUD!!!! You hear a terrible howl. The Wumpus has been slain!"<<endl;
				killed = 1;
			}
		}
	}
	if(direction ==4){
		if(location_col < 2)
			distance = location_col;
		//cout<<"This is distance: " <<  distance  <<endl;
		for(int i  = 0; i < distance; i++){
			if(network[location_row][location_col-i-1]->get_event_type() == 1){
				cout<<"THUD!!!! You hear a terrible howl. The Wumpus has been slain!"<<endl;
				killed = 1;
			}
		}
	}
	if(killed == 2){
		cout<<"CLANG!!! Your arrow echoes as it strikes a cold stone surface of the cave."<<endl;
		cout<<"Deep within the cave complex you hear the echoes of a stirring body."<<endl;
	}
	hero.loose_arrow();


	network[wump_row][wump_col]->set_room(new Empty);
	network[wump_row][wump_col]->set_dimension("|_|");

	if(killed == 2){  //Wumpus is not killed 
		int c = 1;
		while(c){
			wump_row = rand()%room_num;
			wump_col = rand()%room_num;
			if(network[wump_row][wump_col]->get_event_type() == 5 && wump_row != location_row && wump_col != location_col){
				network[wump_row][wump_col]->set_room(new Wumpus);	
				c =0 ;
			}
		}
		return false;
	}
	else if(killed == 1){
		return true; 
	}
}

/****************************************
 *Function:       	check_lose_arrows()      
 *Description:          checks to see if you have at least one arrow and if not checks to see if the wumpus is dead 
 *Parameters:          	bool wumpus_dead
 *Pre-conditions:       turn took place
 *Post-conditions:      N/A
 *Return:               bool lose or win 
 *****************************************/

bool Cave::check_lose_arrows(bool wump_dead){
	if(hero.get_arrows() == 0 && wump_dead == false ){
		cout<<"You have fired your last arrow!! You have no weapon to kill the Wumpus with now! You lose." <<endl;
		return false;
	}
	else{
		cout<<"You now only have " << hero.get_arrows() <<" arrows left."<<endl;
		return true;
	}
}

/****************************************
 *Function:        	win()
 *Description:          checks to see if the player has won 
 *Parameters:          	bool wumpus_dead
 *Pre-conditions:       turn took place 
 *Post-conditions:      N/A
 *Return:               bool 
 *****************************************/

bool Cave::win(bool wump_dead){
	if(wump_dead == true && hero.get_gold() == true && location_row == rope_row && location_col == rope_col){
		cout<< "You have slain the Wumpus, recliamed his hoarded treasure, and navigated back to your escape rope. You win!"<<endl;
		return true;
	}
}

/****************************************
 *Function:        	print_cave()     
 *Description:          prints the dimension corresponding to each room 
 *Parameters:          	N/A
 *Pre-conditions:       N/A
 *Post-conditions: 	printed cave system       
 *Return:               N/A
 *****************************************/

void Cave::print_cave(){
	cout<<endl;	
	for(int i = 0; i < room_num; i++){
		for(int j = 0; j <  room_num; j++){
			cout<<network[i][j]->get_dimension();
		}
		cout<<endl;
	}
	cout<<endl; 
}

/****************************************
 *Function:         	exposition()       
 *Description:          BS function I wrote because I thought it would be funny..... I still think its funny 
 *Parameters:          	N/A
 *Pre-conditions:       The Wumpus has been terrorizing Chesterville
 *Post-conditions:      N/A
 *Return:               N/A
 *****************************************/

void Cave::exposition(){

	cout<<"||||||| HUNT THE WUMPUS |||||||||"<<endl; 
	cout<< endl;



	cout<<"You are a fearless, quick-witted young lad, whos deeds of bravery, fighting prowess and fantastic adventures are told throughout the land. Bards sing odes in you honor and men toast to your health and longevity. You go by the name Kamron the Brave. You have heard tales of a fearsome creature known as the WUmpus, who has stolen the princess of the small kingdom of Chesterville. The King has offered a reward of a man's weight in gold to any brave, handsome, suave, stoic hero who can slay this beast and rescue the princess. it just so happens that you fit the profile of such a man perfectly. You reputation preceeds you, and upon your arrival to Chesterville you are welcomed to the castle to meet the king. The king's court Wizard, Zarbalor tells you of the Wumpus."<<endl;
	cout<<endl;
	cout<< "<in an old man voice> 'The Wumpus is an ancient creature of power and mystery. Only a blessed arrow, dipped in the blood of a infant lamb and consecrated with magical runes can pierce its hide. To fire such a arrow my son, you must use a bow carved from a felled tree in the Elven woods. May I present to you this bow and three arrows. Go now brave adventurer and slay this mighty foe, the fate of Chesterville lies in you hands...'" <<endl;
	cout<<endl;

	cout<<"You walk many hours until you find the cave of the wumpus. Taking out a rope you fearlessly  descend into the depths of the cave....."<<endl;

}

/****************************************
 *Function:        	ending()       
 *Description:          Gives a beautiful monolouge about the ending of the tale 
 *Parameters:          	N/A
 *Pre-conditions:       you won the game
 *Post-conditions:     	Everyone thinks that Kam the Rogue is a Hero
 *Return:               N/A
 *****************************************/

void Cave::ending(){
	cout<< "You return to Chesterville and are greeted as a hero. The kindgon celebrates for the next week with feasting and games. The king offers you your weight in gold. Stoically you refuse, saying that the ultimate reward is taking solace in the fact the princess has been saved. (What a guy)"<<endl;
	cout<<endl; 
	cout<<"At the end of the week, you realize it is time to leave... Mounting your noble steed Stardust, you begin to ride out of town when suddenly you hear a cry. It is the princess...."<<endl;
	cout<<endl; 
	cout<<"'Oh noble Kam, will you not stay. The Kingdom of Chesterville could use a man like you, titles, lordship and lands could all be yours', she says trailing off. 'No princess, I must go, for as long as their is injustice in this world I cannot rest..." <<endl;
	cout<<endl;
	cout<<"The princess burst into tears as you turn and ride off into the sunset.........."<<endl;
}
