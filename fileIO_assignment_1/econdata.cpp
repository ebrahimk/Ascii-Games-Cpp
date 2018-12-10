#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;


struct county {
        std::string name;
        float unemployed_2007;
        float unemployed_2015;
        int med_income;
};


struct state {
        std::string name;
        float unemployed_2007;
        float unemployed_2015;
        int med_income;
        struct county* counties;
        int n_counties;
};

/******************************************
 *  *Function: Verify 
 *   *Description: This function determines is a string is an integer
 *    *Parameters: string input 
 *     *Pre-Conditions: a string is passed to the function 
 *      *Post-Conditions: The string has been checked and is either an integer or not 
 *       * ****************************************/

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

/******************************************
 *  *Function: Convert
 *   *Description:Converts a string of an integer  into an integer type
 *    *Parameter: string input 
 *     *Pre-Conditions: String passd to function
 *      *Post-Conditions: string converted to int
 *       * ****************************************/

int convert(string ver){
        float val_final;
        val_final  = atoi(ver.c_str());
        return (val_final);
}

/******************************************
 *  *Function: allocate_states 
 *   *Description: allocates a 1-D array of type state
 *    *Parameter: passed the number of states 
 *     *Pre-Conditions: text file is read 
 *      *Post-Conditions: 
 *       * ****************************************/

struct state* allocate_states(int n){
        state* array_states = new state[n];
}

/******************************************
 *  *Function: allocate_counties 
 *   *Description: Allocates an array of the county struct 
 *    *Parameter: the number of counties present within the given state 
 *     *Pre-Conditions: All state arrays have been allocated 
 *      *Post-Conditions: An array of county structs has been created 
 *       * ****************************************/

struct county* allocate_counties(int n){
        county* county_array  = new county[n];
}

/******************************************
 *  *Function: read_county_data 
 *   *Description: This function reads the data regarding counties in the text file argument
 *    *Parameter: arrray of state classes, text file, and the number of counties 
 *     *Pre-Conditions: state data has been read 
 *      *Post-Conditions: data for the counties is stored in county arrays 
 *       * ****************************************/

void  read_county_data(struct county* county_array, int county_num, std::ifstream& infile){
        for(int i = 0; i < county_num; i++){
                infile >> county_array[i].name >> county_array[i].unemployed_2007 >> county_array[i].unemployed_2015 >>county_array[i].med_income;
        }
}

/******************************************
 *  *Function: read_state_data 
 *   *Description: This function reads the state data of the textfile into srrays of state structs 
 *    *Parameter: array of state structs, the number of states, and the information within the text file 
 *     *Pre-Conditions: the text file has been opened 
 *      *Post-Conditions: the array of state structs has been filled with data from the text file.  
 *       * ****************************************/

void read_state_data(struct state* state_array, int n, std::ifstream& infile){
        for(int i = 0;i <n; i++){
                infile >> state_array[i].name >>  state_array[i].unemployed_2007 >> state_array[i].unemployed_2015 >> state_array[i].med_income >> state_array[i].n_counties;
                state_array[i].counties = allocate_counties(state_array[i].n_counties);
                read_county_data(state_array[i].counties, state_array[i].n_counties, infile);
        }
}

/******************************************
 *  *Function: free_state_data 
 *   *Description: This function deletes all of the memory allocated on the heap 
 *    *Parameter: array of states 
 *     *Pre-Conditions: the program has ran at least once and the user no longer whats to perform another search 
 *      *Post-Conditions: heap meory is freed 
 *       * ****************************************/

void free_state_data(struct state* state_array, int n){

        for(int i =0; i < n; i++){
                delete [] state_array[i].counties;
        }
        delete [] state_array;
}

/******************************************
 *  *Function: print_choices1  
 *   *Description: This function prints the search choicce which sort through the reaid-in data 
 *    *Parameter:N/A
 *     *Pre-Conditions: the data has been read into their respective arrays 
 *      *Post-Conditions: The user has selected one of the avaliable options
 *       * ***************************************/

int print_choices1(){
        int c =2;
        string choice;
        while(c == 2){
                cout<<"Enter the number corresponding to the operation you would like to execute: " <<endl;
                cout<<"1: Print the state with the highest median household income. "<<endl;
                cout<<"2: Print the state with the lowest median household income. " <<endl;
                cout<< "3: Print the state with the highest unemployment in 2015. " <<endl;
                cout<<"4: Print the state with the lowest unemployment in 2015. " << endl;
                cout<< "5: Print the states in sorted order by change in unemployment from 2007 to 2015. " <<endl;
                cout << "6: Print the states in sorted order based on median household income. "<<endl; //STILL NEED TO BE WRITTEN
                cout<< "7: Select a state and choose from a menu of accessible data. "<<endl; //STILL NEEDS TO BE WRITTEN
                cin >> choice;
                if(verify(choice) == false || convert(choice) < 1 || convert(choice) > 7){
                        cout << "Invalid input, please enter a number ranging from 1 to 7. " <<endl;
                }
                else{
                        c =1;
                }
        }
        return convert(choice);
}

/******************************************
 *  *Function: print_choices2 
 *   *Description: This function prints the avaliable search options within counties 
 *    *Parameter: N/A 
 *     *Pre-Conditions: The user has selected to search county data 
 *      *Post-Conditions: the user chooses an avaliable option 
 *       * ****************************************/

int print_choices2(){
        int c =2;
        string choice;
        while(c == 2){
                cout<<"Enter the number corresponding to the operation you would like to execute: " <<endl;
                cout<<"1: Print the county with the highest median household income. "<<endl;
                cout<<"2: Print the county with the lowest median household income. " <<endl;
                cout<< "3: Print the county with the highest unemployment in 2015. " <<endl;
                cout<<"4: Print the county with the lowest unemployment in 2015. " << endl;
                cout<< "5: Print the counties in sorted order by change in unemployment from 2007 to 2015. " <<endl;
                cout << "6: Print the counties in sorted order based on median household income. "<<endl; //STILL NEED TO BE WRITTEN 
                cin >> choice;
                if(verify(choice) == false || convert(choice) < 1 || convert(choice) > 6){
                        cout << "Invalid input, please enter a number ranging from 1 to 7. " <<endl;
                }
                else{
                        c =1;
                }
        }
        return convert(choice);
}

/******************************************
 *  *Function: choice_1 
 *   *Description: This function prints the state with the greatest median income 
 *    *Parameter: array of states and the number of states 
 *     *Pre-Conditions: user selected option one for states
 *      *Post-Conditions: N/A
 *       * ****************************************/

void choice_1(struct state* state_array, int n){
        int temp = 0;
        int state = 0;
        for(int i = 0; i < n; i++){
                if(state_array[i].med_income > temp){
                        temp = state_array[i].med_income;
                        state = i;
                }
        }
        cout<<"The state with the highest median income is " << state_array[state].name << endl;
}

/******************************************
 *  *Function: bchoice_1 
 *   *Description: This function prints the county, within a specified state, with the highest median income  
 *    *Parameter: array of states and the chosen state 
 *     *Pre-Conditions: user chose to search county data 
 *      *Post-Conditions: N/A
 *       * ****************************************/

void bchoice_1(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        int temp = 0;
        int county = 0;
        for(int i = 0; i < county_num; i++){
                if(state_array[n].counties[i].med_income > temp){
                        temp = state_array[n].counties[i].med_income;
                        county = i;
                }
        }
        cout<<"The county with the highest median income within the state of " << state_array[n].name   <<" is " << state_array[n].counties[county].name <<endl;
}

/******************************************
 *  *Function: choice_2 
 *   *Description: prints state with lowest med income 
 *    *Parameter: arra of states, number of states 
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void choice_2(struct state* state_array, int n){
        int temp = 0;
        int state = 0;
        for(int i = 0; i < n; i++){
                if(state_array[i].med_income < temp){
                        temp = state_array[i].med_income;
                        state = i;
                }
        }
        cout<<"The state with the lowest median income is " << state_array[state].name << endl;
}

/******************************************
 *  *Function: bchoice_2  
 *   *Description: prints county within specified state with lowest med income 
 *    *Parameter: arroay of state and number corresponding to selected state 
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void bchoice_2(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        int temp = 0;
        int county = 0;
        for(int i = 0; i < county_num; i++){
                if(state_array[n].counties[i].med_income < temp){
                        temp = state_array[n].counties[i].med_income;
                        county = i;
                }
        }
        cout<<"The county with the lowest median income within the state of " << state_array[n].name   <<" is " << state_array[n].counties[county].name <<endl;
}

/******************************************
 *  *Function: choice_3  
 *   *Description: prints state with highest unemployment rate for 2015 
 *    *Parameter: array of states and the number of states 
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void choice_3(struct state* state_array, int n){
        float temp = 0;
        int state = 0;
        for(int i = 0; i < n; i++){
                if(state_array[i].unemployed_2015 > temp){
                        temp = state_array[i].unemployed_2015;
                        state = i;
                }
        }
        cout<<"The state with the highest unemployment rate of 2015 is " << state_array[state].name << endl;
}

/******************************************
 *  *Function: bchoice_3  
 *   *Description: prints county, within specified state, with highest 2015 unemployment 
 *    *Parameter: array of states and a number corresponding to chosen state 
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void bchoice_3(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        float temp = 0;
        int county = 0;
        for(int i = 0; i < county_num; i++){
                if(state_array[n].counties[i].unemployed_2015 > temp){
                        temp = state_array[n].counties[i].unemployed_2015;
                        county = i;
                }
        }
        cout<<"The county with the highest unemployment rate of 2015 within the state of " << state_array[n].name << " is " << state_array[n].counties[county].name << endl;
}

/******************************************
 *  *Function: choice_4  
 *   *Description: prints state with lowest unemployment rate 2015 
 *    *Parameter: state array and number of states
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void choice_4(struct state* state_array, int n){
        float temp = 0;
        int state = 0;
        for(int i = 0; i < n; i++){
                if(state_array[i].unemployed_2015 < temp){
                        temp = state_array[i].unemployed_2015;
                        state = i;
                }
        }
        cout<<"The state with the lowest unemployment rate of 2015 is " << state_array[state].name << endl;
}

/******************************************
 *  *Function: bchoice_4 
 *   *Description: prints county, within specified state, with lowest 2015 unemployment 
 *    *Parameter: state array, number corresponding to chosen state 
 *     *Pre-Conditions: selected by user 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void bchoice_4(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        float temp = 0;
        int county = 0;
        for(int i = 0; i < county_num; i++){
                if(state_array[n].counties[i].unemployed_2015 < temp){
                        temp = state_array[n].counties[i].unemployed_2015;
                        county = i;
                }
        }
        cout<<"The county with the lowest unemployment rate of 2015 within the state of " << state_array[n].name << " is " << state_array[n].counties[county].name << endl;
}

/******************************************
 *  *Function: choice_5 
 *   *Description: prints states in order of change in unemployment rate  
 *    *Parameter: state array, number corresponding to chosen states
 *     *Pre-Conditions: selected by user  
 *      *Post-Conditions: N/A 
 *       * ****************************************/


void choice_5(struct state* state_array, int n){
        float* diff_arr = new float[n];
        float temp = 100 ;
        int location =0;
        cout<< "These are the states sorted from smallest increase in unemployment to largest increase in unemployment: "<<endl;
        for(int i =0; i< n; i++){
                diff_arr[i] = state_array[i].unemployed_2015 - state_array[i].unemployed_2007;
        }
        for(int j =0; j < n; j++){
                for(int i = 0; i <n; i++){
                        if(diff_arr[i] < temp){
                                location = i;
                                temp = diff_arr[i];
                        }
                }
                temp = 100;
                diff_arr[location] =1000;
                cout<< state_array[location].name <<endl;;
        }
        delete [] diff_arr;
}

/******************************************
 *  *Function: bchoice_5 
 *   *Description: prints counties, within specified state, in order of change in unemployment rate  
 *    *Parameter: state array, number corresponding to chosen states
 *     *Pre-Conditions: selected by user  
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void bchoice_5(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        float* diff_arr = new float[county_num];
        float temp = 100 ;
        int location =0;
        cout<< "These are the counties in "<< state_array[n].name << " sorted from smallest increase in unemployment to largest increase in unemployment: "<<endl;
        for(int i =0; i< county_num; i++){
                diff_arr[i] = state_array[n].counties[i].unemployed_2015 - state_array[n].counties[i].unemployed_2007;
        }
        for(int j =0; j < county_num; j++){
                for(int i = 0; i < county_num; i++){
                        if(diff_arr[i] < temp){
                                location = i;
                                temp = diff_arr[i];
                        }
                }
                temp =100;
                diff_arr[location] =1000;
                cout<< state_array[n].counties[location].name <<endl;
        }
        delete [] diff_arr;
}

/******************************************
 *  *Function: choice_6 
 *   *Description: prints states in order of median income   
 *    *Parameter: state array, number of states
 *     *Pre-Conditions: selected by user  
 *      *Post-Conditions: N/A 
 *       * ****************************************/

void choice_6(struct state* state_array, int n){
        int location = 0;
        int temp = -100;
        int* med_arr = new int[n];
        for(int i =0; i < n; i++){
                med_arr[i] = state_array[i].med_income;
        }
        cout<<"From largest income to smallest median income: "<<endl;
        for(int i = 0; i < n ; i ++){
                for(int j = 0; j < n; j++){
                        if(med_arr[j] > temp){
                                location = j;
                                temp = med_arr[j];
                        }
                }
                temp =-100;
                med_arr[location] = -1000;
                cout<< state_array[location].name <<endl;
        }
        delete [] med_arr;
}

/******************************************
 *  *Function: bchoice_6  
 *   *Description: prints counties in order of median income   
 *    *Parameter: state array, number corresponding to chosen states
 *     *Pre-Conditions: selected by user  
 *      *Post-Conditions: N/A 
 *       * ****************************************/


void bchoice_6(struct state* state_array, int n){
        int county_num = state_array[n].n_counties;
        int* med_arr = new int[county_num];
        int temp = -100 ;
        int location =0;
        for(int i =0; i < county_num ; i++){
                med_arr[i] = state_array[n].counties[i].med_income;
        }
        cout<< "From largest median income to smallest median income: "<<endl;
        for(int j =0; j < county_num; j++){
                for(int i = 0; i < county_num; i++){
                        if(med_arr[i] > temp){
                                location = i;
                                temp = med_arr[i];
                        }
                }
                temp =-100;
                med_arr[location] = 0;
                cout<< state_array[n].counties[location].name <<endl;
        }
        delete [] med_arr;
}

/******************************************
 *  *Function: choice_7 
 *   *Description: Determines what state to search county data in
 *    *Parameter: number of states 
 *     *Pre-Conditions:  selected by user 
 *      *Post-Conditions: user selected a number corresponding to state 
 *       * ****************************************/

int choice_7(int n){
        string choice;
        int t = 1;
        while(t ==1){
                cout<< " Please the number corresponding to the state you would like specific county data read from. Enter 0, if you want to read data from the first state, enter 1 if you want to read datat from the second state etc. etc. " <<endl;
                cin >> choice;
                if(verify(choice) == false || convert(choice) < 0 || convert(choice) > n-1){
                        cout << "Invalid input, please enter a number ranging from 0 to "<< n-1  <<"." <<endl;
                }
                else{
                        t =2 ;
                }
        }
        return convert(choice);
}

/******************************************
 *  *Function: run_counties 
 *   *Description: runs the function based off of user input 
 *    *Parameter: array of state and the number corresponding to the chosen state 
 *     *Pre-Conditions:  selected by user 
 *      *Post-Conditions: another function is run 
 *       * ****************************************/

void run_counties(struct state* state_array, int choice, int n){
        if(choice == 1)
                bchoice_1(state_array, n);
        if(choice ==2)
                bchoice_2(state_array, n);
        if(choice ==3)
                bchoice_3(state_array, n);
        if(choice == 4)
                bchoice_4(state_array, n);
        if(choice ==5)
                bchoice_5(state_array, n);
        if(choice ==6)
                bchoice_6(state_array, n);
}

/******************************************
 *  *Function: run_choice 
 *   *Description: runs the function based off of user input 
 *    *Parameter: array of state and the number of states 
 *     *Pre-Conditions:  selected by user 
 *      *Post-Conditions: another function is run 
 *       * ****************************************/

int run_choice(struct state*  state_array, int choice, int n){
        if(choice == 1)
                choice_1(state_array, n);
        if(choice ==2)
                choice_2(state_array, n);
        if(choice ==3)
                choice_3(state_array, n);
        if(choice == 4)
                choice_4(state_array, n);
        if(choice ==5)
                choice_5(state_array, n);
        if(choice ==6)
                choice_6(state_array, n);
        if(choice == 7){
                int state_choice = choice_7(n);
                int operation_choice = print_choices2();
                run_counties(state_array, operation_choice, state_choice); // state to explore, operation of exploration        
        }
}

/******************************************
 *  *Function: run_again
 *   *Description: determines if the user wants t orun another search 
 *    *Parameter: N/A
 *     *Pre-Conditions:  Search has been run once 
 *      *Post-Conditions: N/A 
 *       * ****************************************/

int run_again(){
        string answer;
        int t = 1;
        while(t ==1){
                cout<<" Would you like ot run another search? Enter a 1 for 'yes' or a 0 for 'no'. "<<endl;
                cin >> answer;
                if(convert(answer) !=  0 || convert(answer) != 1){
                        t = 0;
                }
                else{
                        cout<<" Please enter a valid response! " <<endl;
                }
        }
        return convert(answer);
}


