#include "DiceRoller.h"
#include "iostream"
#include "Classes.h"

using namespace std;
int main(){
    //Prep Random Values
    srand(time(0));
    rand();

//welcome to the world dale!
    cout<<Bard.get_hit_dice();
    cout<<endl;
    cout<<Bard;


    return 0;
}