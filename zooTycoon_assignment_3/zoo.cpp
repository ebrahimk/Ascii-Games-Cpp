#include<iostream> 
#include"zoo.hpp"
#include"error_check.hpp"
#include<cstdlib>

using namespace std; 
 
/***************************************
 *Function:		Zoo        
 *Description:          Constructor fo zoo class
 *Parameters:          	N/A
 *Pre-conditions:       zoo object initialized 
 *Post-conditions:     	zoo type initialized 
 *Return:               N/A
*****************************************/

Zoo::Zoo(){
	money = 100000;
	num_monkey = 0;
	num_sloth =0;
	num_otter =0; 
	monkey_exhibit = new Monkey [200];
	sloth_exhibit = new Sloth[200];
	otter_exhibit = new Otter[200]; 
}
 
/***************************************
 *Function:		~Zoo            
 *Description:          destructor for zoo class
 *Parameters:          	N/A
 *Pre-conditions:       zoo object leaves scope 
 *Post-conditions:     	all heap memory freed
 *Return:              	N/A
*****************************************/

Zoo::~Zoo(){
	delete [] monkey_exhibit;
	delete [] sloth_exhibit;
	delete [] otter_exhibit;
}
 
/***************************************
 *Function:		pay_food            
 *Description:          calculates the total cost of food for each animal type 
 *Parameters:          	N/A
 *Pre-conditions:       turn is taking place 
 *Post-conditions:     	food is subtracted from money or the player loses 
 *Return:              	true or false 
*****************************************/

bool Zoo::pay_food(){
	cout<<"Its time to pay for you animals."<<endl; 
	int mon_total =0; 
	for(int i = 0; i < num_monkey; i++){
		mon_total = mon_total +  monkey_exhibit[i].food_cost();
		
	}
	cout<<"The monkeys cost " << mon_total << " to feed."<<endl; 
	int slo_total = 0;
	for(int i = 0; i < num_sloth; i++){
		slo_total = slo_total + sloth_exhibit[i].food_cost();
	}
	cout<<"The sloths cost " << slo_total << " to feed."<<endl;
	int ott_total =0;
	for(int i = 0; i < num_otter; i++){
		ott_total = ott_total+ otter_exhibit[i].food_cost();
	}
	cout<<"The otters cost "<< ott_total << " to feed."<<endl; 
	int total = mon_total+slo_total+ott_total;
	if(total > money){
		cout<<"You cannot afford the animals this turn! You lose! "<<endl;  
		return false;
	}
	else{
		cout<<"The total cost is "<<total <<". This amount will be subtracted from your current bank balance."<<endl; 
		money = money - total; 
		return true;
	}
}
 
/***************************************
 *Function:		purchase_animal            
 *Description:          checks to see if the player wants to purchase an animal 
 *Parameters:           N/A
 *Pre-conditions:       turn is taking place 
 *Post-conditions:     	player either has a new animal in exhibit or does not 
 *Return:              	N/A
*****************************************/

void Zoo::purchase_animal(){
	int t =1;
	string response; 
	int num_animals = 0;
	while(t){
		cout<<"Enter the number of animals you would like to purchase this turn: " <<endl; 
		cin>> response;
		if(verify(response) == false || convert(response) >2 || convert(response) < 0)
			cout<< "Please enter either zero, one, or two. "<<endl;  
		else{
			t =0;
			num_animals = convert(response); 
		}
	}
	if(num_animals > 0){	
		string response2; 
		int choice =0; 
		for(int i = 0; i <  num_animals; i++){
			int t = 1;
			while(t){
				cout<<"Monkeys cost $15,000, sea otters cost $5,000 and sloths cost $2,000."<<endl;
				cout <<"Please enter a '1' if you want to buy a monkey, a '2' if you want to buy a sloth, and a '3' if you want  ot buy an otter: "<<endl;	
				cin>>response2;
				if(verify(response2)== false|| convert(response2) >3 || convert(response2) < 1)
					cout<<"You must enter either a 1, 2, or 3."<<endl;
				else{
					choice = convert(response2);
					t = 0; 
				}
			}
			if(choice == 1){
				money = money - 15000;
				monkey_exhibit[num_monkey] = Monkey(1096, 200, 1500, true);//monkey of age 3
				num_monkey++;
				cout<< monkey_exhibit[num_monkey-1].get_cost()<<endl;  
			}
			if(choice == 2){
				money = money - 2000;
				sloth_exhibit[num_sloth] = Sloth(1096, 50, 100, true);//monkey of age 3
				num_sloth++;

			}
			if(choice == 3){
				money = money - 5000;
				otter_exhibit[num_otter] = Otter(1096, 100, 250, true);//monkey of age 3
				num_otter++;
			}
		}
	}
}
 
/***************************************
 *Function:		event1            
 *Description:          causes a random animal to get sick 
 *Parameters:          	N/A
 *Pre-conditions:       random number generated corresponding to the first event 
 *Post-conditions:     	animal gets sick and dies or player has enough money to save it 
 *Return:              	N/A
*****************************************/

int Zoo::event1(){
	if(num_monkey > 0 ||num_sloth > 0||num_otter > 0){
		cout<< "OH NO! One of your animals has fallen ill."<<endl; 
		int z =1;
		int sick = 0;
		while(z){
			sick = rand()%3+1;
			cout <<"This is sick "<< sick << "."<<endl;
			if(sick == 1 && num_monkey > 0) 
				z=0;
			if(sick == 2 && num_sloth > 0)
				z=0;
			if(sick == 3 && num_otter >0)
				z=0;
		}
		if(sick == 1){ //Randomly generate monkey if baby take that into account 
			Monkey chosen = monkey_exhibit[rand()%num_monkey]; 
			if(chosen.get_age() < 30){
				cout<<"One of your baby monkeys is sick! Itll cost $15,000 to get it medical attention."<<endl; 
				if(money< 15000){
					cout<<"You cannot afford the medical procedures, the sick baby monkey dies!" <<endl; 
					chosen.set_living_status(false);
					for(int i =0; i < num_monkey; i++){
						if(monkey_exhibit[i].get_living_status() == false){
							monkey_exhibit[i] = monkey_exhibit[i+1];
							monkey_exhibit[i+1].set_living_status(false);
						}
					}
					num_monkey--;
				}
				else{
					cout<<"you can afford the procedure! The baby monkey is saved."<<endl; 
					money = money - 15000;
				}	
			}		
			else{	
				cout<<"One of your adult monkeys is sick, itll cost $7,500 to get it medical attention." <<endl; 
				if(money < 7500){
					cout<<"You cant afford the procedure the sick monkey dies!" <<endl;
					chosen.set_living_status(false);
					for(int i =0; i < num_monkey; i++){
						if(monkey_exhibit[i].get_living_status() == false){
							monkey_exhibit[i] = monkey_exhibit[i+1];
							monkey_exhibit[i+1].set_living_status(false);
						}
					}	
					num_monkey--;  
				}
				else{
					cout<<"you can afford the procedure! The adult monkey is saved."<<endl;
					money = money - 7500;
				}
			}
		}
		if(sick == 2){  
			Sloth chosen = sloth_exhibit[rand()%num_sloth];
			if(chosen.get_age() < 30){
				cout<<"One of your baby sloths is sick! Itll cost $2,000 to get it medical attention."<<endl;
				if(money< 2000){
					cout<<"You cannot afford the medical procedures, the sick baby sloth dies!" <<endl;
					chosen.set_living_status(false);
					for(int i =0; i < num_sloth; i++){
						if(sloth_exhibit[i].get_living_status() == false){
							sloth_exhibit[i] = sloth_exhibit[i+1];
							sloth_exhibit[i+1].set_living_status(false);
						}
					}
					num_sloth--;
				}
				else{
					cout<<"you can afford the procedure! The baby sloth is saved."<<endl;
					money = money - 2000;
				}
			}
			else{
				cout<<"One of your adult sloths is sick, itll cost $1,000 to get it medical attention." <<endl;
				if(money < 1000){
					cout<<"You cant afford the procedure the sick sloth dies!" <<endl;
					chosen.set_living_status(false);
					for(int i =0; i < num_sloth; i++){
						if(sloth_exhibit[i].get_living_status() == false){
							sloth_exhibit[i] = sloth_exhibit[i+1];
							sloth_exhibit[i+1].set_living_status(false);
						}
					}
					num_sloth--;
				}
				else{
					cout<<"you can afford the procedure! The adult sloth is saved."<<endl;
					money = money - 1000;
				}
			}
		}
		if(sick == 3){                                                          
			Otter chosen = otter_exhibit[rand()%num_otter];
			if(chosen.get_age() < 30){
				cout<<"One of your baby otters is sick! Itll cost $5,000 to get it medical attention."<<endl;
				if(money<5000){
					cout<<"You cannot afford the medical procedures, the sick baby otter dies!" <<endl;
					chosen.set_living_status(false);
					for(int i =0; i < num_otter; i++){
						if(otter_exhibit[i].get_living_status() == false){
							otter_exhibit[i] = otter_exhibit[i+1];
							otter_exhibit[i+1].set_living_status(false);
						}
					}
					num_otter--;
				}
				else{
					cout<<"you can afford the procedure! The baby otter is saved."<<endl;
					money = money - 5000;
				}
			}
			else{
				cout<<"One of your adult otters is sick, itll cost $2,500 to get it medical attention." <<endl;
				if(money < 2500){
					cout<<"You cant afford the procedure the sick otters dies!" <<endl;
					chosen.set_living_status(false);
					for(int i =0; i < num_otter; i++){
						if(otter_exhibit[i].get_living_status() == false){
							otter_exhibit[i] = otter_exhibit[i+1];
							otter_exhibit[i+1].set_living_status(false);
						}
					}
					num_otter--;
				}
				else{
					cout<<"You can afford the procedure! The adult otter is saved."<<endl;
					money = money - 2500;
				}
			}
		}
	}
}
 
/***************************************
 *Function:		event2             
 *Description:          simulates a baby animal being created 
 *Parameters:          	N/A
 *Pre-conditions:       random number generated corrresponding to event 2 
 *Post-conditions:     	animal of age zero added to exhibit 
 *Return:              	N/A
*****************************************/

void Zoo::event2(){
	int type = rand()%3+1; 
	if(type == 1){
		for(int i= 0; i < num_monkey; i++){
			if(monkey_exhibit[i].get_age() > 1095){
				cout<<"One of your adult monkies had a baby!"<<endl; 
				monkey_exhibit[num_monkey].set_living_status(true); //maybe num_monkey + 1  
				num_monkey++;
				break;
			}
		}
	}
	if(type ==2){
		for(int i = 0; i < num_sloth; i++){
			if(sloth_exhibit[i].get_age() > 1095){
				cout<<"One of your adult sloths had babies!" <<endl; 
				for(int i = 0; i < 3; i++){
					sloth_exhibit[num_sloth].set_living_status(true);
					num_sloth++;
				}
			}
		}
	}
	if(type ==3){ 
		for(int i = 0; i < num_otter; i++){
			if(otter_exhibit[i].get_age() > 1095){
				cout<<"One of your adult sea otters had babies!" <<endl;
				for(int i = 0; i < 2; i++){
					otter_exhibit[num_otter].set_living_status(true);
					num_otter++;
				}
			}
		}
	}
}
 
/***************************************
 *Function:		event3             
 *Description:          generates more money based off the number of monkeys present in exhibit 
 *Parameters:          	N/A
 *Pre-conditions:       random number generated 
 *Post-conditions:     	money added if monkeys are present 
 *Return:              	N/A
*****************************************/

int Zoo::event3(){
	if(num_monkey>0){
		cout<<"Today was a busy day, you had alot of visitors come and see the monkey exhibit!"<<endl; 
		int bonus =0; 
		for(int i = 0; i < num_monkey; i++){
			bonus += rand()%250; 
		}
		cout<<"Your monkeys made you an extra " << bonus << " dollars. Way to extort animals for your own personal gain!"<<endl; 
		return bonus; 
	}
}

/***************************************
 *Function:		collect_rev            
 *Description:          calculates the total revenue produced by the animals player owns 
 *Parameters:          	int extra 
 *Pre-conditions:       turn taken place 
 *Post-conditions:     	revenue is calculated 
 *Return:              	N/A
 *****************************************/

void Zoo::collect_rev(int extra){
	int mon_rev =0;
	int sloth_rev = 0;
	int otter_rev =0;
	int total_rev =0;
	for(int i =0; i < num_monkey; i++){ 
		mon_rev = mon_rev +  monkey_exhibit[i].get_rev(); 
	}
	cout<< "Your monkeys made you "<< mon_rev <<" dollars today."<<endl; 

	for(int i =0; i <num_sloth; i++){
		sloth_rev = sloth_rev + sloth_exhibit[i].get_rev();
	}
	cout<<"Your sloths made you "<< sloth_rev <<" dollars today."<<endl;

	for(int i = 0; i <num_otter; i++){
		otter_rev = otter_rev + otter_exhibit[i].get_rev();
	}
	cout<<"Your otters made you "<< otter_rev <<" dollars today."<<endl; 

	total_rev = mon_rev + sloth_rev + otter_rev + extra; 	
	money = money+ total_rev;
	cout<<"You now have "<<money<<" dollars."<<endl; 
}
 
/***************************************
*Function:		make_adult            
*Description:          	steps through each exhibit and set adult status based off age 
*Parameters:          	N/A
*Pre-conditions:       	end of turn 
*Post-conditions:     	if age is greater that 1095 sets adult status 
*Return:              	N/A
*****************************************/

void Zoo::make_adult(){
	for(int i = 0 ; i < num_monkey; i++){
		monkey_exhibit[i].set_adult_status(); 
	}
	for(int i = 0; i < num_sloth; i++){
		sloth_exhibit[i].set_adult_status(); 
	}
	for(int i =0; i < num_otter; i++){
		otter_exhibit[i].set_adult_status();
	}
}
 
/***************************************
*Function:		increase_age             
*Description:          	increases all animals in exhibit age by one 
*Parameters:          	N/A
*Pre-conditions:       	end of turn 
*Post-conditions:     	age of each animal in array increased by one 
*Return:              	N/A
*****************************************/

void Zoo::increase_age(){
	for(int i = 0; i< num_monkey; i++){
		monkey_exhibit[i].increase_age();
	}
	for(int i = 0; i< num_sloth; i++){
		sloth_exhibit[i].increase_age();
	}
	for(int i = 0; i< num_otter; i++){
		otter_exhibit[i].increase_age();
	}
}
 
/***************************************
*Function:		print info            
*Description:          	tells player how many animals of each type they have and how many babies of ecah type they have 
*Parameters:          	N/A
*Pre-conditions:       	end of turn
*Post-conditions:     	info printed 
*Return:              	N/A
*****************************************/

void Zoo::print_info(){
	int adult_mon =0;
	int bab_mon = 0; 
	int adult_sloth =0;
	int bab_sloth =0;
	int adult_ott =0;
	int bab_ott =0;
	for(int i = 0; i< num_monkey; i++){
		if(monkey_exhibit[i].get_age() >= 1095)
			adult_mon++;								
		else if(monkey_exhibit[i].get_age() <30)
			bab_mon++;
	}
	cout<<"You have "<< adult_mon <<" adult monkeys."<<endl;
	cout<<"You have " <<bab_mon <<" baby monkeys."<<endl; 

	for(int i = 0; i< num_sloth; i++){
		if(sloth_exhibit[i].get_age() >= 1095)
			adult_sloth++;
		else if(sloth_exhibit[i].get_age() <30)
			bab_sloth++;
	}
	cout<<"You have "<< adult_sloth <<" adult sloths."<<endl;
	cout<<"You have " <<bab_sloth <<" baby sloths."<<endl;

	for(int i = 0; i< num_otter; i++){
		if(otter_exhibit[i].get_age() >= 1095)
			adult_ott++;
		else if(otter_exhibit[i].get_age() <30)
			bab_ott++;
	}
	cout<<"You have "<< adult_ott <<" adult otters."<<endl;
	cout<<"You have " <<bab_ott <<" baby otters."<<endl;
}
