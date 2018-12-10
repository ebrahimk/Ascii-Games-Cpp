#include<iostream>
#include<string>
#include"animal.hpp" 
#include"monkey.hpp"
#include"sea_otter.hpp"
#include"sloth.hpp"
#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo {
	private:
		int money; 
		int num_monkey;
		int num_sloth;
		int num_otter; 
		Monkey* monkey_exhibit; 
		Sloth* sloth_exhibit;
		Otter* otter_exhibit; 
	public:
                Zoo();
                ~Zoo();
		void purchase_animal(); //maybe split into three function one per animal type 
		bool pay_food(); 
		int event1();
		void event2();
		int event3(); 
		void collect_rev(int extra);
		void increase_age();
		void make_adult();
		void print_info();
};
#endif
