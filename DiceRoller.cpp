#include "DiceRoller.h"

// I don't know if this is neccessary, but I think it beats throwing it in the main.
//I might just be able to get away with methods and not using a class at all.
//I thought tha the random was a class not a function.
//This at least assures that we seed the random function before use.
//However this has no dependencies on the class body itself.


int roll_dice(const int times, const int sides, const bool advantage=false, const bool dis_adv=false) {
    int total = 0;
    for (int i=0; i<times; i++){
        int dice_roll = rand()%sides+1;

        if (advantage || dis_adv){
            int adv_roll = rand()%sides+1;
            if (adv_roll>dice_roll && advantage){       //Theres likely a more concise way to do this than using an else if, especially cosnidering the bodies of each are the same.
                dice_roll = adv_roll;
            }
            else if (dis_adv && dice_roll>adv_roll){
                dice_roll = adv_roll;
            }
        }
        total+=dice_roll;
    }
    return total;
}
int roll(std::string roll_descriptor){
    const bool advantage=false;
    const bool dis_adv = false;
    int times = stoi(roll_descriptor.substr(0,roll_descriptor.find('d')));
    int sides = stoi(roll_descriptor.substr(roll_descriptor.find('d')+1,roll_descriptor.size()));      //IDK if this is going to work
    return roll_dice(times,sides, advantage, dis_adv);
}
int roll(std::string roll_descriptor, const bool advantage=false, const bool dis_adv = false){
    int times = stoi(roll_descriptor.substr(0,roll_descriptor.find('d')));
    int sides = stoi(roll_descriptor.substr(roll_descriptor.find('d')+1,roll_descriptor.size()));      //IDK if this is going to work
    return roll_dice(times,sides, advantage, dis_adv);
}
