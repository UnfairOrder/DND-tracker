#include "DiceRoller.h"
#include "iostream"
#include "Classes.h"
#include "ItemList.hpp"
#include "Character.h"

using namespace std;
int main(){
    //Prep Random Values
    srand(time(0));
    rand();

//welcome to the world dale!
    // cout<<Bard.calculate_class_hitpoints(1)<<endl;
    // cout<<Bard.calculate_class_hitpoints(2)<<endl;
    // cout<<Bard.calculate_class_hitpoints(3)<<endl;
    // cout<<Bard.get_hit_dice()<<endl;
    // cout<<roll(Bard.get_hit_dice())<<endl;
    // cout<<Bard.calculate_class_hitpoints(1);
    Character dale = Character("dale","human",68,10,10,10,10,10,2,Bard);
    // cout<<dale.getCon_mod()<<endl;
    cout<<dale.get_max_hp()<<endl;
    // cout<<dale.calculate_max_hp()<<endl;

    // Character george = dale;



    return 0;
}