#include<fstream> 
#include<string> 
#include<cstring>

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

bool verify(std::string str_input);
int convert(std::string ver);
struct state* allocate_states(int n);
struct county* allocate_counties(int n);
void read_county_data(struct county* county_array, int county_num, std::ifstream& infile);
void read_state_data(struct state* state_array, int n, std::ifstream& infile);
void free_state_data(struct state* state_array, int n);
int print_choices1();
int print_choices2();
void choice_1(struct state* state_array, int n);
void bchoice_1(struct state* state_array, int n);
void choice_2(struct state* state_array, int n);
void bchoice_2(struct state* state_array, int n);
void choice_3(struct state* state_array, int n);
void bchoice_3(struct state* state_array, int n);
void choice_4(struct state* state_array, int n);
void bchoice_4(struct state* state_array, int n);
void choice_5(struct state* state_array, int n);
void bchoice_5(struct state* state_array, int n);
void choice_6(struct state* state_array, int n);
void bchoice_6(struct state* state_array, int n);
int choice_7(int n);
void run_counties(struct state* state_array, int choice, int n);
int run_choice(struct state*  state_array, int choice, int n);
int run_again();

