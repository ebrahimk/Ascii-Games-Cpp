#include<iostream>
#include"zoo.hpp"
#include<cstdlib>
#include<cstdlib>

using namespace std; 

int main(){
	srand(time(NULL));
	Zoo my_zoo;

	int t = 1;
	int count = 1;	

	while(t){
		cout<<"Its day " << count <<"."<<endl; 
		my_zoo.print_info();
		int extra = 0; 
		my_zoo.purchase_animal();
		bool affordable = my_zoo.pay_food();
		if(affordable == false){				
			t=0;
			break;
		}
		int event = rand()%4;
		if(event == 0)
			my_zoo.event1();
		if(event == 1)
			my_zoo.event2();
		if(event == 2)
			extra = my_zoo.event3();
		else if(event == 3)
			cout<<"The zoo operates as normal today and nothing out of the ordinary occurs." <<endl;
		my_zoo.collect_rev(extra); 
		my_zoo.increase_age(); 
		my_zoo.make_adult();
		count++;
	}

	return 0; 
}
