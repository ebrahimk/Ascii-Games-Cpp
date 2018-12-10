#include<iostream>
#include"player.hpp"
#include"game.hpp"

using namespace std;

int main(){

 
Game go_fish; 

for(int i = 0; i < 7; i++){
go_fish.deal_p1();
go_fish.deal_p2();
}

go_fish.p1_show_hand();
while(go_fish.over()){
go_fish.p1_turn();
go_fish.p2_turn();
}

go_fish.winner();

}
