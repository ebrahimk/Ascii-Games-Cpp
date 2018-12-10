#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include"econdata.hpp"

using namespace std;

int main(int argc, char** argv){

        ifstream infile;
        infile.open(argv[1]);

        int states_num = 0;
        infile>> states_num;
        state* state_array = allocate_states(states_num);
        read_state_data(state_array, states_num, infile);

        int counter =1;
        while(counter == 1){
                int choice = print_choices1();
                run_choice(state_array, choice, states_num);
                int another_one = run_again();
                if(another_one == 0)
                        counter=0;
        }

        free_state_data(state_array, states_num);
        infile.close();
        return 0;
}
