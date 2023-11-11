#include "DiceRoller.h"
#include "iostream"
#include "Classes.h"
#include "ItemList.hpp"
#include "Character.h"

using namespace std;



Character* create_character(ostream& out){
    //Choose a Class
    cout<<"Please choose a class:"<<endl<<endl;
    PlayerClass class_choice;
    int choice;
    
    //Print Class Options
    for (int i=0; i<ClassList.size(); i++){
        out<<ClassList[i].get_name()<<" : "<<i+1<<endl;
    }

    //get and Check player input
    cin>>choice;
    bool valid_input=false;
    while (!valid_input){
        for (int i=1; i<ClassList.size()+1; i++){
            if (choice==i){
                valid_input=true;
                break;
            }
        }
        if(!valid_input){
            cout<<"invalid input"<<endl;
            cin>>choice;
        }
    }
    //store class Choice
    class_choice = ClassList[choice];

    //Race
        //Because race is a string right now, just doing a cin
    string race;
    cout<<"Please type in your selected race: ";
    cin>>race;
        //I feel like this should be made better. I want to display the choices made thus far across the top.

}





int main(){
    //Prep Random Values
    srand(time(0));
    rand();

    //Intialize Character list
    vector<Character*> character_list;

    //Main Menu
    int menu_options[]= {1,2};
    int menu_size = 2;

    cout<<"DnD Tracker:indev"<<endl<<endl<<endl;
    cout<<"Main Menu:"<<endl<<endl;
    cout<<"Load Characters: "<<menu_options[0]<<endl;
    cout<<"Create new Character: "<<menu_options[1]<<endl;
    bool valid=false;
    int option;
    cin>>option;
    while(!valid){
        for (int i=0; i<menu_size; i++){
            if (option == menu_options[i]){
                valid=true;
                break;
            }
        }
        if (!valid){
            cout<<"invalid option"<<endl;
            cin>>option;
        }
    }
    switch(option){
        case 1:
            cout<<"Load Characters"<<endl;
            break;
        case 2:
            cout<<"create new Character"<<endl;
            //Character Creator goes here
            break;
    }
            
    //Select Characters
    //Game/Use
        //Combat
        //Normal View




    return 0;
}