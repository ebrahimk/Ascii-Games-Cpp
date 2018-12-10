#include<iostream>
#include<string>
#include"maze.hpp"
#include<cstdlib>
#include<cstring>
#define LEVELS "maze.txt"

using namespace std;
 
/****************************************
 *Function:             Maze()                                               
 *Description:          constructor for Maze object          
 *Parameters:           N/A
 *Pre-conditions:       Maze object initialized
 *Post-conditions:      Maze object created 
 *Return:               N/A
 *****************************************/

Maze::Maze(){
	srand(time(NULL));
	ifstream infile;
	infile.open(LEVELS);
	if(infile.fail()){
		cerr <<"Failed to open file." <<endl;
		exit(0);
	}

	infile >> level_num;
	infile >> height;
	infile >> width;
	string line;
	getline(infile, line); 

	levels = new MazeLevel*[level_num];
	for(int i = 0; i < level_num; i++){
		levels[i] = new MazeLevel(infile, height, width);
	}

	Rob_the_cruel = new Instructor;
	Kamron = new IntrepidStudent;
	
	minions = new TA*[6];	
	for(int i = 0; i < 6; i++){
		minions[i] = new TA;
	}



	for(int a =0; a < level_num ; a++){
		for(int i =0; i< height; i++){
			for(int j = 0; j <width; j++){
				if(a == 0 && levels[a]->check_start(i,j) == true && levels[a]->wall_open(i,j) ==true){
					Kamron->set_location(i,j);
					levels[a]->set_student(i,j, true);
				}
				if(levels[a]->check_instructor(i,j) == true){
					Rob_the_cruel->set_location(i,j);
					levels[a]->set_instructor(i,j,true);
				}
			}
		}
	}

	int t = 1;
	int count = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0;j < 2; j++){
			while(t){
				int rand_row =rand()%height;
				int rand_col =rand()%width;
				if(levels[i]->wall_open(rand_row, rand_col) == true && levels[i]->check_ta(rand_row,rand_col) == false){
					levels[i]->set_ta(rand_row, rand_col, true);
					minions[count]->set_floor(i);
					minions[count]->set_location(rand_row, rand_col);
					t =0;
				}
			}
			count++;
			t =1;
		}
	}
	t = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0;j < 3; j++){
			while(t){
				int rand_row2 =rand()%height;
				int rand_col2 =rand()%width;
				if(levels[i]->wall_open(rand_row2, rand_col2) == true && levels[i]->check_ta(rand_row2,rand_col2) == false && levels[i]->check_skill(rand_row2, rand_col2) ==false){
					levels[i]->set_skill(rand_row2, rand_col2, true);
					t =0;
				} 
			}
			t =1;
		}
	}
}
 
/****************************************
 *Function:          	~Maze()                                                
 *Description:          destructorfor Maze object   
 *Parameters:           N/A
 *Pre-conditions:      	Maze object leaves scope
 *Post-conditions:      memory freed
 *Return:               N/A
 *****************************************/

Maze::~Maze(){
	delete Rob_the_cruel;
	delete Kamron;
	for(int i = 0; i <6; i++){
		delete minions[i];
	}
	delete [] minions; 
	for(int j = 0; j< level_num; j++){
		delete levels[j];
	}
	delete [] levels;
}
 
/****************************************
 *Function:           	turn()                                           
 *Description:          simulates player turn    
 *Parameters:           N/A
 *Pre-conditions:      	Maze object created
 *Post-conditions:      player moves
 *Return:               N/A
 *****************************************/

void Maze::turn(){
	int error = 1;
	while(error){
		char move = Kamron->get_move();
		if(move == 'u'){
			if(levels[Kamron->get_floor()]->check_ladder(Kamron->get_row(),Kamron->get_col()) == true){
				cout<<"You ascend to the next level of the maze..."<<endl;
				error = 0;
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), false);
				Kamron->set_floor(Kamron->get_floor()+1);
				for(int i = 0; i < height; i++){
					for(int j = 0; j< width; j++){
						if(levels[Kamron->get_floor()]->check_start(i,j) ==true){
							levels[Kamron->get_floor()]->set_student(i,j,true);
							Kamron->set_location(i,j);
						}
					}
				}
			}
			else{
				cout<<"You must be on a ladder to climb."<<endl;
			}
		}
		if(move == 'p'){
			if(Kamron->get_skills() == 0){
				cout<<"You have no more programming skills"<<endl;
			}
			else{
				Kamron->decrease_skills();
				cout<<"Whipping out your computer, beautiful, efficient, lines of code erupt from your  fingertips as you type away at 2000 words per minute."<<endl;
				error = 0;
				for(int i = 0; i< 6; i++){
					if(minions[i]->get_floor() == Kamron->get_floor()){
						minions[i]->set_counter();
					}
				}
				error = 0;
			}
		}

		if(move == 'w'){
			if(levels[Kamron->get_floor()]->wall_open(Kamron->get_row()-1,Kamron->get_col())==true){
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), false);
				Kamron->set_location(Kamron->get_row()-1, Kamron->get_col());
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), true);
				error =0;
				if(levels[Kamron->get_floor()]->check_skill(Kamron->get_row(), Kamron->get_col())==true){
					Kamron->increase_skills();
					cout<<"You pick up a skill, you now have " <<Kamron->get_skills()<< " programming skills."<<endl;
					levels[Kamron->get_floor()]->set_skill(Kamron->get_row(), Kamron->get_col(), false);
					levels[Kamron->get_floor()]->set_student(Kamron->get_row(), Kamron->get_col(), true);
				}
			}


			else{
				cout<<"You cannot move that direction."<<endl;
			}
		}
		if(move == 'a'){
			if(levels[Kamron->get_floor()]->wall_open(Kamron->get_row(),Kamron->get_col()-1)==true){
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), false);
				Kamron->set_location(Kamron->get_row(), Kamron->get_col()-1);
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), true);
				error =0;

				if(levels[Kamron->get_floor()]->check_skill(Kamron->get_row(), Kamron->get_col())==true){
					Kamron->increase_skills();
					cout<<"You pick up a skill, you now have " <<Kamron->get_skills()<< " programming skills."<<endl;
					levels[Kamron->get_floor()]->set_skill(Kamron->get_row(), Kamron->get_col(), false);
					levels[Kamron->get_floor()]->set_student(Kamron->get_row(), Kamron->get_col(), true);
				}
			}

			else{
				cout<<"You cannot move that direction."<<endl;
			}
		}
		if(move == 's'){
			if(levels[Kamron->get_floor()]->wall_open(Kamron->get_row()+1,Kamron->get_col())==true){
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), false);
				Kamron->set_location(Kamron->get_row()+1, Kamron->get_col());
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), true);
				error = 0;

				if(levels[Kamron->get_floor()]->check_skill(Kamron->get_row(), Kamron->get_col())==true){
					Kamron->increase_skills();
					cout<<"You pick up a skill, you now have " <<Kamron->get_skills()<< " programming skills."<<endl;
					levels[Kamron->get_floor()]->set_skill(Kamron->get_row(), Kamron->get_col(), false);
					levels[Kamron->get_floor()]->set_student(Kamron->get_row(), Kamron->get_col(), true);
				}
			}

			else{
				cout<<"You cannot move that direction."<<endl;
			}
		}
		if(move == 'd'){
			if(levels[Kamron->get_floor()]->wall_open(Kamron->get_row(),Kamron->get_col()+1)==true){
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), false);
				Kamron->set_location(Kamron->get_row(), Kamron->get_col()+1);
				levels[Kamron->get_floor()]->set_student(Kamron->get_row(),Kamron->get_col(), true);
				error =0;

				if(levels[Kamron->get_floor()]->check_skill(Kamron->get_row(), Kamron->get_col())==true){
					Kamron->increase_skills();
					cout<<"You pick up a skill, you now have " <<Kamron->get_skills()<< " programming skills."<<endl;
					levels[Kamron->get_floor()]->set_skill(Kamron->get_row(), Kamron->get_col(), false);
					levels[Kamron->get_floor()]->set_student(Kamron->get_row(), Kamron->get_col(), true);
				} 
			}

			else{
				cout<<"You cannot move that direction."<<endl;
			}
		}
	}
}
 
/****************************************
 *Function:         	turn_ta()                                               
 *Description:          simulates a TA's turn 
 *Parameters:           N/A
 *Pre-conditions:      	Maze object created
 *Post-conditions:      TA's on each floor move
 *Return:               N/A
 *****************************************/

void Maze::turn_ta(){
	int count = 0;
	char move;
	int error =1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j< 2; j++){
			while(error){
				move = minions[count]->get_move();
				if(move == 'w'){
					if(levels[minions[count]->get_floor()]->wall_open(minions[count]->get_row()-1,minions[count]->get_col())==true){
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), false);
						minions[count]->set_location(minions[count]->get_row()-1, minions[count]->get_col());
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), true);
						error = 0;
						count++;
					}
				}
				if(move == 'a'){
					if(levels[minions[count]->get_floor()]->wall_open(minions[count]->get_row(),minions[count]->get_col()-1)==true){
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), false);
						minions[count]->set_location(minions[count]->get_row(), minions[count]->get_col()-1);
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), true);
						error = 0;
						count++;
					}
				}
				if(move == 's'){
					if(levels[minions[count]->get_floor()]->wall_open(minions[count]->get_row()+1,minions[count]->get_col())==true){
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), false);
						minions[count]->set_location(minions[count]->get_row()+1, minions[count]->get_col());
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), true);
						error = 0;
						count++;
					}
				}
				if(move == 'd'){
					if(levels[minions[count]->get_floor()]->wall_open(minions[count]->get_row(),minions[count]->get_col()+1)==true){
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), false);
						minions[count]->set_location(minions[count]->get_row(), minions[count]->get_col()+1);
						levels[minions[count]->get_floor()]->set_ta(minions[count]->get_row(),minions[count]->get_col(), true);
						error = 0;
						count++;
					}
				}
			}
			error = 1;
		}
	}
}

/****************************************
 *Function:          	check_ta()                                           
 *Description:        	checks to see if the player is cauht by a TA
 *Parameters:           N/A
 *Pre-conditions:      	Maze object created 
 *Post-conditions:      floor reset or player is fine
 *Return:               N/A
 *****************************************/

void Maze::check_ta(){
	int floor = Kamron->get_floor();
	int row = Kamron->get_row();
	int col = Kamron->get_col();
	int count = Kamron->get_floor() *2;
	for(int i = 0 ;i < 6; i++){	
		if(minions[i]->get_floor() == Kamron->get_floor()){
			minions[i]->counter_step();
		}
	}
	if(minions[count]->get_appeased() == false || minions[count+1]->get_appeased() ==false){
		if(levels[floor]->check_ta(row,col) == true||levels[floor]->check_ta(row,col-1) == true ||levels[floor]->check_ta(row,col+1) == true||levels[floor]->check_ta(row-1,col) == true||levels[floor]->check_ta(row+1,col) == true ){
			cout<<"You've been caught by a TA!!"<<endl;
			Kamron->lose_skills();
			for(int i = 0; i <  height; i++){
				for(int j =0; j <width; j++){
					if(levels[Kamron->get_floor()]->check_ta(i, j)== true)
						levels[Kamron->get_floor()]->set_ta(i,j,false);
					if(levels[Kamron->get_floor()]->check_skill(i,j) == true)
						levels[Kamron->get_floor()]->set_skill(i,j, false);
					if(levels[Kamron->get_floor()]->check_student(i,j)==true)
						levels[Kamron->get_floor()]->set_student(i,j,false);
					if(levels[Kamron->get_floor()]->check_start(i,j) ==true){
						levels[Kamron->get_floor()]->set_student(i,j,true);
						Kamron->set_location(i,j);
					}
				}
			}
			int t = 1;
			int count = Kamron->get_floor()*2;
			for(int j = 0;j < 2; j++){
				while(t){
					int rand_row =rand()%height;
					int rand_col =rand()%width;
					if(levels[Kamron->get_floor()]->wall_open(rand_row, rand_col) == true && levels[Kamron->get_floor()]->check_ta(rand_row, rand_col) == false){
						levels[Kamron->get_floor()]->set_ta(rand_row, rand_col, true);
						minions[count]->set_floor(Kamron->get_floor());
						minions[count]->set_location(rand_row, rand_col);
						count++;
						t =0;
					}
				}
				t = 1;
			}
			t = 1;
			for(int i = 0; i < 3; i++){
				while(t){
					int rand_row2 =rand()%height;
					int rand_col2 =rand()%width;
					if(levels[Kamron->get_floor()]->wall_open(rand_row2, rand_col2) == true && levels[Kamron->get_floor()]->check_ta(rand_row2,rand_col2) == false && levels[Kamron->get_floor()]->check_skill(rand_row2,rand_row2) ==false){
						levels[Kamron->get_floor()]->set_skill(rand_row2, rand_col2, true);
						t =0;
					}
				}
				t =1;
			}
		}
	}
}

/****************************************
 *Function:            	check_win()                                               
 *Description:        	checks to see if the player has won or lost 
 *Parameters:           N/A
 *Pre-conditions:      	Maze object created 
 *Post-conditions:      game reset or player wins 
 *Return:               N/A
 *****************************************/

int Maze::check_win(){
	int win = 0;
	if(Kamron->get_skills() >= 3){
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row()+1,Kamron->get_col())==true){
			win =1;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row(),Kamron->get_col()-1)==true){
			win =1;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row()-1,Kamron->get_col())==true){
			win =1;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row(),Kamron->get_col()+1)==true){
			win =1;	
		}
	}
	if(win == 1){
	cout<<"A tall dark menacing, robed figure looks at you. It is the dark overloard Rob the Cruel, destroyed of students free time and social lives. Rob raises his right hand and speaks, 'Impressive, you have evaded my TA minions and climbed to the top of my lair, however..... YOU ARE A FOOL TO BELIEVE YOU HAVE WHAT IT TAKES TO ESCAPE MY CLASS WITH A PASSING GRADE BWAHAHAHAHAHAHAHA!!!!'. Flourishing his hands Rob utters the vocal component of an ancient arcane incantation, 'JUMBALABA GURANDA!!!!!', he yells. You know the words of this powerful spell, it is a piece of extremely complicated dark magic called, 'POLYMORPHISM'. As Rob finishes the incantation you feel you arms and legs grow fatigued, your brain is wracked with a jumbled barrage of confusing information about pointers and inheritence that you forgot ten minutes after lecture. The spell causes you to fall on your knees in confusion and pain. In the midst of the confusion, you remember that polymorphism is method that allows pointer objects of the base class to be treated like members of the derived class so one can access the methods definied in the derived class! Suddenly the confusion abates and the strength returns to your limbs. You have broken Rob's spell!"<<endl;
cout<<"Rob's eyes widen in disbelief, 'You are indeed worthy of a passing grade young student, take this *hands you the letter A, and continue on your quest to become the most powerful computer scientist in all the galaxy. YOU PASS!!!"<<endl;  
	return 1;
	}
	else if(Kamron->get_skills() < 3){
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row()+1,Kamron->get_col())==true){
			cout<<"Rob the Cruel looks at you condescendingly and speaks, 'Knave, you do not posess the skills to proceed! You Fail! BWAHAHAHAHAHAHAHA'"<<endl;
			return  2;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row(),Kamron->get_col()-1)==true){
			cout<<"Rob the Cruel looks at you condescendingly and speaks, 'Knave, you do not posess the skills to proceed! You Fail! BWAHAHAHAHAHAHAHA'"<<endl; 
			return 2;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row()-1,Kamron->get_col())==true){
			cout<<"Rob the Cruel looks at you condescendingly and speaks, 'Knave, you do not posess the skills to proceed! You Fail! BWAHAHAHAHAHAHAHA'"<<endl;
			return 2;
		}
		if(levels[Kamron->get_floor()]->check_instructor(Kamron->get_row(),Kamron->get_col()+1)==true){
			cout<<"Rob the Cruel looks at you condescendingly and speaks, 'Knave, you do not posess the skills to proceed! You Fail! BWAHAHAHAHAHAHAHA'"<<endl;
			return 2; 
		}
	}
	return 3;
}

/****************************************
 *Function:           	set_symbols()                                           
 *Description:          sets symbol hiearchy
 *Parameters:           N/A
 *Pre-conditions:      	turn passed
 *Post-conditions:      symbols reset depending on priority
 *Return:               N/A
 *****************************************/

void Maze::set_symbols(){
	for(int a = 0; a < level_num; a++){
		for(int i = 0; i < height; i++){
			for(int j= 0; j < width; j++){
				if(levels[a]->check_ta(i,j) == true && levels[a]->check_student(i,j) == true)
					levels[a]->set_location_symbol(i,j,'*');
				if(levels[a]->check_skill(i,j) == true && levels[a]->check_student(i,j) == true)
					levels[a]->set_location_symbol(i,j,'*');
				if(levels[a]->check_ladder(i,j) == true)
					levels[a]->set_location_symbol(i,j,'^');
				if(levels[a]->check_instructor(i,j)==true)
					levels[a]->set_location_symbol(i,j,'I');
				if(levels[a]->check_skill(i,j)==true)
					levels[a]->set_location_symbol(i,j,'$');
				if(levels[a]->check_start(i,j) == true)
					levels[a]->set_location_symbol(i,j,'@');
			}
		}
	}
}

/****************************************
 *Function:          	display()                                                 
 *Description:       	displays the maze level the player is on             
 *Parameters:           N/A
 *Pre-conditions:      	turn passed
 *Post-conditions:      maze level occupied by player is printed 
 *Return:               N/A
 *****************************************/

void Maze::display(){
	levels[Kamron->get_floor()]->display_maze();
}

