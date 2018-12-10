#include<iostream> 
#include<string> 
#include<cstdlib> 
#ifndef USEFUL_FUNCTIONS_HPP
#define USEFUL_FUNCTIONS_HPP

using namespace std; 

/***************************************
 **Function:              verify
 **Description:           Verifies that the input is a proper unsigned integer
 **Parameters:            string
 **Pre-conditions:        string input 
 **Post-conditions:       the input is a proper unsigned integer
 **Return:                true or false 
 ******************************************/

bool verify1(string str_input){

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

/***************************************
 **Function:              convert
 **Description:           converts string to an unsigned integer
 **Parameters:            string
 **Pre-conditions:        string input 
 **Post-conditions:       the input is a proper unsigned integer
 **Return:                integer
 *****************************************/

int convert1(string ver){
        float val_final;
        val_final  = atoi(ver.c_str());
        return (val_final);
}

#endif 
