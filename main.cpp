#include "DiceRoller.h"
#include "iostream"
#include "Classes.h"
#include "ItemList.hpp"
#include "Character.h"
#include <stdlib.h>

using namespace std;


bool isNumeric(string str){
    for (unsigned int i=0; i< str.length(); i++){
        if (isdigit(str[i])==false){
            return false;
        }
        return true;
    }
}


//temporary void return while testing build
void create_character(ostream& out){
    //Choose a Class
    cout<<"Please choose a class:"<<endl<<endl;
    PlayerClass class_choice;
    int choice;
    
    //Print Class Options
    for (size_t i=0; i<ClassList.size(); i++){
        out<<ClassList[i].get_name()<<" : "<<i+1<<endl;
    }

    //get and Check player input
// Input validation not working right now
    // bool valid_input=false;
    // while (!valid_input){
    //     cin>>choice;
    //     for (size_t i=1; i<ClassList.size()+1; i++){    //This breaks if non numeric characters are used. It also doesn't continue after the while loop.
    //         if (choice<=ClassList.size() && choice==i){
    //             valid_input=true;
    //             break;
    //         }
    //     }
    //     if(!valid_input){
    //         cout<<"invalid input"<<endl;
            
    //     }
    // }

    //TODO show class description, confirm selection or return to choice.
    cout<<"Enter your choice: ";
    cin>>choice;

    system("cls");

    //store class Choice
    // class_choice = ClassList[choice];
    class_choice = ClassList[choice-1];
    string character_string = "Class: "+class_choice.get_name()+"\n";



    //Race
        //Because race is a string right now, just doing a cin
    cout<<character_string<<endl;
    string race;
    cout<<"Please type in your selected race: ";
    cin>>race;
    character_string = character_string+"Race: "+race+"\n";

    //stats
    system("cls");
    cout<<character_string<<endl;

    vector<int> stats = generate_stats();
    cout<<" | ";
    for(unsigned int i = 0 ; i<stats.size(); i++){
        cout<<stats[i]<<" | ";
    }
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

    system("cls");  //clear console

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
    system("cls");  //clear console
    switch(option){
        case 1:
            cout<<"Load Characters"<<endl;
            break;
        case 2:
            cout<<"Create new Character"<<endl;
            //Character creator
            create_character(cout);
            break;
    }
            
    //Select Characters
    //Game/Use
        //Combat
        //Normal View




    return 0;
}