#include<iostream> 
#include<string> 
#include"wumpus.hpp" 

using namespace std;

/***************************************
 *Function:		Wumpus           
 *Description:         	Wumpus constructor 
 *Parameters:           N/A
 *Pre-conditions:       Wumpus object called 
 *Post-conditions:      Wumpus object created 
 *Return:              	N/A
*****************************************/

Wumpus::Wumpus():type(1), precept("You smell a terrible stench."){
}
 
/***************************************
 *Function:           	get_precept() 
 *Description:         	returns precept string
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      prints the precept
 *Return:              	string
*****************************************/

string Wumpus::get_precept(){
        return precept;
}

/***************************************
 *Function:           	message()
 *Description:         	prints message about room 
 *Parameters:           N/A
 *Pre-conditions:       function is called 
 *Post-conditions:      N/A
 *Return:              	N/A
*****************************************/

void Wumpus::message(){
        cout<<"Hide gray as iron, teeth bright as razors, a towering, hunched, grotesque figure rises before you. The Wumpus has woken and you cannot escape... You lose! "<<endl;
}

/***************************************
 *Function:           	get_type()
 *Description:         	returns the type of event
 *Parameters:           N/A
 *Pre-conditions:       function called 
 *Post-conditions:      int type returned 
 *Return:              	int type
*****************************************/

int Wumpus::get_type(){
        return this-> type;

}
