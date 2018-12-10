#include<iostream>
#ifndef ADVENTURER_HPP
#define ADVENTURER_HPP

using namespace std; 

class Adventurer {
	protected:
		bool gold; 
		int arrows;	
	public:
		Adventurer();
		void set_gold(bool tf);
		bool get_gold();
		void loose_arrow(); 
		int get_arrows();
};

#endif

