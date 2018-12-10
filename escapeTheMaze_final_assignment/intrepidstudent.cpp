#include<iostream>
#include<cstring>
#include"error_check.hpp"
#include"intrepidstudent.hpp"
 
/****************************************
 *Function:             IntrepidStudent()                                                   
 *Description:          IntrepidStudent object constructor 
 *Parameters:           N/A
 *Pre-conditions:       IntrpidStudent object initialized 
 *Post-conditions:      InstrepidStudent object created 
 *Return:               N/A
 *****************************************/
 
IntrepidStudent::IntrepidStudent(){
        this->row_loc = 0;
        this->col_loc =0;
        this->skills = 0;
	this->floor = 0;
}

/****************************************
 *Function:             get_move()                      
 *Description:          returns a char based off the direction object moves     
 *Parameters:           N/A
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      returns char
 *Return:               char direction
 *****************************************/

char IntrepidStudent::get_move(){
        int action =0;
        int t =1;
        while(t){
                string response_str;
                cout<<"w:  move north" <<endl;
                cout<<"a:  move east" <<endl;
                cout<<"s:  move south" <<endl;
                cout<<"d:  move west" <<endl;
                cout<<"p:  demonstrate programming skill" <<endl;
                cout<<"u:  climb ladder" <<endl;

                cin>> response_str;
		char response = response_str[0];
                
		if( response != 'w' && response != 'a'&&  response != 's' &&  response != 'd' && response  != 'u' && response != 'p'){
                        cout<<"Please enter a valid command."<<endl;
                }
                else{
                        return response;
                        t =0;
                }
        }
}

/****************************************
 *Function:             set_location()           
 *Description:          sets the locaiton of object
 *Parameters:           int row, int col
 *Pre-conditions:       MazePerson object created 
 *Post-conditions:      row_loc and col_loc changed 
 *Return:               N/A
 *****************************************/

void IntrepidStudent::set_location(int row, int col){
        this-> row_loc = row;
        this-> col_loc =col;
}

/****************************************
 *Function:             get_row()                      
 *Description:          returns the row the object is located at      
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the row 
 *Return:               row_loc
 *****************************************/

int IntrepidStudent::get_row(){
        return this-> row_loc;
}

/****************************************
 *Function:             get_col()                  
 *Description:          returns the col the object is located     
 *Parameters:           N/A
 *Pre-conditions:       function called
 *Post-conditions:      returns the column 
 *Return:               int col_loc
 *****************************************/

int IntrepidStudent::get_col(){
        return this-> col_loc;
}
 
/****************************************
 *Function:  		get_skills()                                                  
 *Description:          returns the skills posessed by the student
 *Parameters:           N/A
 *Pre-conditions:       student object created 
 *Post-conditions:      skills returned
 *Return:               int skills
 *****************************************/

int IntrepidStudent::get_skills(){
        return this-> skills;
}

/****************************************
 *Function:          	increase_skills()                             
 *Description:         	increments skills
 *Parameters:           N/A
 *Pre-conditions:       student object created 
 *Post-conditions:      skills increased by one
 *Return:              	N/A
 *****************************************/

void IntrepidStudent::increase_skills(){
        this->skills++;
}

/****************************************
 *Function:          	decrease_skills()                                    
 *Description:       	decreases skills by one
 *Parameters:           N/A
 *Pre-conditions:       student uses skill
 *Post-conditions:     	skills decremented 
 *Return:               N/A
 *****************************************/

void IntrepidStudent::decrease_skills(){
        this-> skills--;
}

/****************************************
 *Function:            	lose_skills()                                    
 *Description:          changes skills value to zero
 *Parameters:           N/A
 *Pre-conditions:       student caught by ta
 *Post-conditions:      skills set to zero
 *Return:               N/A
 *****************************************/

void IntrepidStudent::lose_skills(){
	this->skills =0; 
}

/****************************************
 *Function:             set_floor()                            
 *Description:          sets the floor the object is located at    
 *Parameters:           int num
 *Pre-conditions:       Object created
 *Post-conditions:      floor changed 
 *Return:               N/A
 *****************************************/

void IntrepidStudent::set_floor(int f){
        this-> floor = f;
}

/****************************************
 *Function:             get_floor()                     
 *Description:          returns the floow the object is located at    
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      floor returned 
 *Return:               int floor
 *****************************************/

int IntrepidStudent::get_floor(){
        return this-> floor;
}

