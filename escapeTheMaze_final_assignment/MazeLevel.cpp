#include<iostream>
#include<string>
#include"MazeLevel.hpp"
#include<fstream>
#include<cstring>

using namespace std;
 
/****************************************
 *Function:  		MazeLevel()                                               
 *Description:		constructor for MazeLevel object          
 *Parameters:           int height, int width, ifstream level
 *Pre-conditions:      	MazeLevel object initialized
 *Post-conditions:     	MazeLevel object created 
 *Return:              	N/A
 *****************************************/

MazeLevel::MazeLevel(ifstream& level, int height, int width): row(height), col(width){		

	this -> locations = new MazeLocation**[height];
	for(int i = 0; i < height; i++){
		this -> locations[i] = new MazeLocation*[width];
	}

	string line;
	char* mazeline = new char[width];
	char c;

	for(int i = 0; i < height; i++){
		getline(level, line);
		strcpy(mazeline, line.c_str());
		for(int j = 0; j < width; j++){
			c = mazeline[j];
			if(c == '#'){
				this->locations[i][j] = new Wall;
			}
			else if(c == ' '){
				this->locations[i][j] = new OpenSpace;
			}
			else if(c == '@'){
				this->locations[i][j] = new OpenSpace;
				this->locations[i][j]->set_has_start(true);
			}
			else if(c == '^'){
				this->locations[i][j] = new OpenSpace;
				this->locations[i][j]->set_has_ladder(true);
			}
			else if(c == '%'){
				this->locations[i][j] = new OpenSpace;
				this->locations[i][j]->set_has_instructor(true);			
			}
		}
	}
	delete [] mazeline;
}

/****************************************
 *Function:         	~MazeLevel()            
 *Description:          destructor for MazeLevel object
 *Parameters:           N/A
 *Pre-conditions:       MazeLevel object leaves scope
 *Post-conditions:      MazeLevel object memory freed
 *Return:               N/A
 *****************************************/

MazeLevel::~MazeLevel(){
	for(int i = 0; i <row; i++){
		for(int j = 0; j <col; j++){
			delete locations[i][j];
		}
	}
	for(int i =0 ; i< row; i++){
		delete locations[i];
	}

	delete [] locations;
}

/****************************************
 *Function:          	display_maze()           
 *Description:          prints maze level
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      MazeLevel printed   
 *Return:               N/A
 *****************************************/

void MazeLevel::display_maze(){
	for(int i = 0; i <row; i++){
		for(int j = 0; j < col; j++){
			cout<< locations[i][j]->get_display_character();
		}
		cout<<endl;
	}
}

/****************************************
 *Function:         	set_location_symbol()           
 *Description:          sets location symbol 
 *Parameters:           int row, int col, char sym
 *Pre-conditions:       MazeLevel created 
 *Post-conditions:      symbol changed
 *Return:             	N/A
 *****************************************/

void MazeLevel::set_location_symbol(int row5, int col5, char sym){
	this->locations[row5][col5]->set_symbol(sym);
}

/****************************************
 *Function:          	get_location_symbol()           
 *Description:          returns location symbol
 *Parameters:           int row, int col
 *Pre-conditions:       MazeLevel object created 
 *Post-conditions:     	returns location symbol 
 *Return:              	char symbol 
 *****************************************/

char MazeLevel::get_location_sym(int row1, int col1){
	return this->locations[row1][col1]->get_display_character();
}

/****************************************
 *Function:           	set_ta()	  
 *Description:          sets location to have a ta 
 *Parameters:          	int row, int col, bool tf
 *Pre-conditions:       MazeLevel object created
 *Post-conditions:   	location set to have a TA
 *Return:              	N/A
 *****************************************/

void MazeLevel::set_ta(int row, int col, bool tf){
	locations[row][col]->set_has_ta(tf); 
}

/****************************************
 *Function:         	check_ta()                  
 *Description:         	checks to see if loction has a ta object 
 *Parameters:          	int row, int col
 *Pre-conditions:      	MazeLevel objects created 
 *Post-conditions:   	return bool
 *Return:               bool   
 *****************************************/

bool MazeLevel::check_ta(int row4, int col4){
	return this->locations[row4][col4]->has_ta();
}

/****************************************
 *Function:         	set_instructor()         
 *Description:          sets location to have an instructor object
 *Parameters:           int row, int col, bool tf
 *Pre-conditions:       MazeLevel object created
 *Post-conditions:    	location has instructor object 
 *Return:             	N/A
 *****************************************/

void MazeLevel::set_instructor(int row1, int col1, bool tf2){
	locations[row1][col1]->set_has_instructor(tf2); 
}

/****************************************
 *Function:          	check_instructor()           
 *Description:          checks to see if location has a instructor object 
 *Parameters:           int row, int col
 *Pre-conditions:       MazeLevel objct created 
 *Post-conditions:     	return bool
 *Return:               bool  
 *****************************************/

bool MazeLevel::check_instructor(int row7, int col7){
	return this->locations[row7][col7]->has_instructor();
}

/****************************************
 *Function:          	set_skill()                 
 *Description:          sets location to have a skill
 *Parameters:           int row, int col, bool tf
 *Pre-conditions:       MazeLevel created 
 *Post-conditions:   	location has skill                    
 *Return:               N/A
 *****************************************/

void MazeLevel::set_skill(int row3, int col3, bool tf3){
	locations[row3][col3]->set_has_skill(tf3);
}

/****************************************
 *Function:          	check_skill()           
 *Description:          checks to see if location has a skill
 *Parameters:           int row, int col
 *Pre-conditions:       MazeLevel created
 *Post-conditions:      returns bool                 
 *Return:               bool 
 *****************************************/

bool MazeLevel::check_skill(int row8, int col8){
	return this->locations[row8][col8]->has_skill();
}

/****************************************
 *Function:         	wall_open()          
 *Description:          checks to see if location is occupiable
 *Parameters:           int row, int col
 *Pre-conditions:       N/A
 *Post-conditions:      bool returned               
 *Return:               bool
 *****************************************/

bool MazeLevel::wall_open(int row6, int col6){
	return locations[row6][col6]->is_occupiable();
}

/****************************************
 *Function:     	set_student()                      
 *Description:   	sets location to have student 
 *Parameters:           int row, int col, bool tf
 *Pre-conditions:       Maze level created 
 *Post-conditions:      location has student object  
 *Return:               N/A
 *****************************************/

void MazeLevel::set_student(int row, int col, bool tf){
	locations[row][col]->set_has_student(tf);
}

/****************************************
 *Function:           	check_student()           
 *Description:          checks to see if location has student
 *Parameters:           int row, int col
 *Pre-conditions:       maze level created
 *Post-conditions:      returned bool
 *Return:               bool             
 *****************************************/

bool MazeLevel::check_student(int row, int col){
	return this->locations[row][col]->has_student();
} 

/****************************************
 *Function:        	check_ladder()                   
 *Description:          checks to see if location has a ladder
 *Parameters:           int row, int col
 *Pre-conditions:       maze level created 
 *Post-conditions:     	return bool
 *Return:               bool             
 *****************************************/

bool MazeLevel::check_ladder(int row, int col){
	return this->locations[row][col]->has_ladder();
}

/****************************************
 *Function:            	check_start()               
 *Description:          checks to see if location is start
 *Parameters:           N/A
 *Pre-conditions:       maze level created 
 *Post-conditions:      return bool                 
 *Return:               bool             
 *****************************************/

bool MazeLevel::check_start(int row, int col){
	return this->locations[row][col]->has_start();
}

