#include "DiceRoller.h"
#include <iostream>
#include "Classes.h"
#include "ItemList.h"
#include "Character.h"
#include <stdlib.h>
#include <conio.h>
#include <iomanip>


using namespace std;
const string SAVED_CHARACTERS_FILE = "saved_characters.txt";



bool isNumeric(string str){
    for (unsigned int i=0; i< str.length(); i++){
        if (isdigit(str[i])==false){
            return false;
        }
        return true;
    }
}

/**
 * @brief validates the user input either a Y, y, N, or n, and returns if their answer was yes (true) or no (false)
 * 
 * @param prompt 
 * @return true 
 * @return false 
 */
bool validateSelection(string prompt){
    char choice;
    cout<< prompt+" (Y/N) ";
        cin>>choice;
    while (!(choice =='Y' | choice == 'N' | choice=='y' | choice=='n')){
        choice = 'a';
        cout<<"(Y/N) ";
        cin>>choice;
    }
    if(choice=='Y'|choice=='y'){
        return true;
    }
    else{
        return false;
    }
}


//temporary void return while testing build
Character* create_character(ostream& out){
    //Choose a Class
    out<<"Please choose a class:"<<endl<<endl;
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
    out<<"Enter your choice: ";
    cin>>choice;

    system("cls");

    //store class Choice
    // class_choice = ClassList[choice];
    class_choice = ClassList[choice-1];
    string character_string = "Class: "+class_choice.get_name()+"\n";



    //Race
        //Because race is a string right now, just doing a cin
    out<<character_string<<endl;
    string race;
    out<<"Please type in your selected race: ";
    cin>>race;
    character_string = character_string+"Race: "+race+"\n";

    //stats
    system("cls");
    out<<character_string<<endl;

    vector<int> stats = generate_stats();
    
    string stat_string = " | ";
    string adjusted_stat_str;
    for(unsigned int i = 0 ; i<stats.size(); i++){
        adjusted_stat_str=to_string(stats[i]);
        if (stats[i]<10) adjusted_stat_str=" "+adjusted_stat_str;
        stat_string=stat_string + adjusted_stat_str + " | ";
    }

        //I feel like this should be made better. I want to display the choices made thus far across the top.
    
    //    SELECT STATS

    bool stats_selected = false;
    vector<int> modified_stats;
    
    do{
        modified_stats.clear();
        unsigned int cursor_pos = 3;
        int index = 0;
        unsigned int cursor_delta = (stat_string.size())/stats.size();
        int c=0;
        const int KEY_LEFT = 75, KEY_RIGHT=77;
        vector<string> stat_selection_indicators(6,"");
        string current_stat;
        vector<string> stat_indicators{"S","D","Co","W","I","Ch"};
        vector<string> stat_options{"Strength","Dexterity","Constitution","Wisdom","Intelligence","Charisma"};
        
        int selected_stats=0;
    
        out<<"Please select "<<stat_options[selected_stats]<<'\n'<<'\n';
        out<<stat_string<<'\n';

        while(selected_stats<6){
            c = 0;

            out<<string(cursor_pos,' ')<<"^"<<string(stat_string.length()-cursor_pos,' ')<<'\r';
            // cout<<'\r'; //carriage return goes to beginning of former line
            c=_getch();
            if (c==KEY_LEFT){
                if (cursor_pos>=3+cursor_delta){
                    cursor_pos-=cursor_delta;
                    index-=1;
                }
            }
            else if(c==KEY_RIGHT){
                if(cursor_delta+cursor_pos<stat_string.length()){
                    cursor_pos+=cursor_delta;
                    index+=1;
                }
            }
            else if(c=='\r'){
                

                //index Selection and choice storage
                
                if(stat_selection_indicators.at(index)!=""){
                    out<<"Stat has already been selected!"<<endl;
                }else{
                    selected_stats+=1;
                    stat_selection_indicators.at(index)=stat_indicators[selected_stats-1];
                    modified_stats.push_back(stats[index]);
                    

                    system("cls");  // This works but is flickery
                    
                
                    if(selected_stats<6){
                        out<<character_string<<endl;
                        out<<"Please select "<<stat_options[selected_stats]<<'\n'<<'\n';

                        // Print and format the indicators
                        for(size_t i=0; i<6; i++){
                            if (stat_selection_indicators[i].length()<2){
                            out<<string(4,' ')<<stat_selection_indicators[i];
                            }else{
                            out<<string(3,' ')<<stat_selection_indicators[i];
                            }
                        }
                        out<<endl;
                        out<<stat_string<<'\n';
                    }
                }
                
                
            }

        }
        
        // system("cls");
        out<<character_string<<endl;   //print character string thus far

            // Print and format the indicators
        for(size_t i=0; i<6; i++){
            if (stat_selection_indicators[i].length()<2){
            out<<string(4,' ')<<stat_selection_indicators[i];
            }else{
            out<<string(3,' ')<<stat_selection_indicators[i];
            }
        }
        out<<endl;
        out<<stat_string<<endl;
        char stat_choice='a';
        out<<endl;
        out<<"Are you happy with your stat selection? (Y/N) ";
        cin>>stat_choice;
        while (!(stat_choice =='Y' | stat_choice == 'N' | stat_choice=='y' | stat_choice=='n')){
            stat_choice = 'a';
            out<<"(Y/N) ";
            cin>>stat_choice;
        }
        if(stat_choice=='Y'|stat_choice=='y'){
            stats_selected=true;
        //add stat indicators to character string
            character_string = character_string+"Stats: "+'\n';
            for(size_t i=0; i<6; i++){
                if (stat_selection_indicators[i].length()<2){
                    character_string=character_string+string(4,' ')+stat_selection_indicators[i];
                }else{
                    character_string=character_string+string(3,' ')+stat_selection_indicators[i];
            }
        }
        character_string = character_string+'\n'+stat_string;
        }else{
            system("cls");
            out<<character_string<<endl;
        }
    }while(!stats_selected);


    //prints the modified stat block in order
    // for (size_t i=0; i<6; i++){
    //     out<<modified_stats[i]<<" ";
    // }    

    //          CHARACTER NAME
    // new menu (I might put this bit into a method... I am repeating myself a lot, but it's also only 2 lines of code and a method would need to pass the string anyways.)
    // perhaps put a character limit on the character name.
    bool name_selected = false;
    string character_name;
    while(!name_selected){
        system("cls");
        out<<character_string<<endl;
        out<<endl;
        out<<"Please enter your Character's name: ";
        cin>>character_name;
        out<<endl;
        name_selected = validateSelection("Do you confirm your character's name?");
    }
    character_string=character_string+'\n'+"Name: "+character_name;

    //         PROFICIENCY SELECTION
    //given that I haven't implemented proficiencies yet, this one can wait.

    //         STARTING INVENTORY
    // Again, given that I don't have an inventory system working, this one can also wait

    //      CHARACTER HEIGHT
    bool height_selected = false;
    float height = 68;
    while(!height_selected){
        system("cls");
        cout<<character_string<<endl;
        cout<<"Please enter your Character's height in total inches: ";
        cin>>height;
        height_selected = validateSelection("Do you confirm your character's height ?");
    }

    //Final Character Creation
    system("cls");
    cout<<character_string<<endl<<endl;
    cout<<"Please welcome "<<character_name<<" to the world!";

    //modified_stats order: "Strength","Dexterity","Constitution","Wisdom","Intelligence","Charisma"


//failing to create character object.
    Character* character= new Character(character_name,race,height,modified_stats,1,class_choice);
    // int breakout;
    // cin>>breakout;
    cout<<"Character created";
    return character;

}

/**
 * @brief 
 * 
 */
void load_Characters(vector<Character*> &charList){
    //initialize variables
    vector<string> Character_selection_list;


    ifstream savedCharacters(SAVED_CHARACTERS_FILE);
    if(!savedCharacters){
        cout<<"Failed to open save state file. You might not have created any Characters yet!";
        return;
    }
    //READ DATA AND POPULATE CHARACTER NAME LIST
        //Each line individually will be the characters' name
        //might want to add more validation to that in the future. like an id number as well so that multiple characters
        //can have the same name.
    string Character_name;
    
    while(!savedCharacters.eof()){
        savedCharacters>>Character_name;
        cout<<Character_name<<endl;
        Character_selection_list.push_back(Character_name);
        Character_name = "";
    }

    //CLOSE FILE
    savedCharacters.close();

    //      PRESENT CHARACTER OPTIONS TO USER
    const int selection_array_size = Character_selection_list.size();
    vector<char> selection_array(selection_array_size,' ');

    size_t cursor_index=0;
    char cursor = '>';
    bool selected = false;
    string input;




    while(!selected){
        cout<<"Please select which Characters you would like to load in:"<<endl;

        //rewrite this every time an input is detected
            for(size_t i = 0; i<Character_selection_list.size(); i++){
                char drawCursor = ' ';
                if(cursor_index==i){drawCursor=cursor;}
                cout<<setw(5)<<drawCursor<<setw(2)<<selection_array[i]<<" "<<Character_selection_list[i]<<endl;
            }
            //draw arrow in front of a character's name
            cin>>input;
            if (input=="done"){
                selected = true;
            }

            //open file containing list of character save files
            //read list of character names and populate
            //Present user with options for selecting which characters to load
        //input data for Character into character constructor method
        //Add newly created characters to charList as pointers
    }


}

/**
 * @brief calls save item on each character, and saves the name of the character's save file to another file.
 * 
 * @param charList 
 */
void save_Characters(vector<Character*> &charList){
    ofstream saved_characters;
    saved_characters.open(SAVED_CHARACTERS_FILE,std::ios::app);
    if(!saved_characters){
        cerr<<"failed to open saved characters file";
        return;
    }

        string character_name;
    for(size_t i=0; i<charList.size(); i++){
        character_name = charList[i]->save();
        saved_characters<<character_name<<'\n';
    }

    saved_characters.close();
}










int main(){
    //Prep Random Values
    srand(time(0));
    rand();
//Test area






    //Intialize Character list
    vector<Character*> character_list;
    bool running = true;

    //Main Menu
    int menu_options[]= {1,2,3};
    int menu_size = 3;

    while(running){
        system("cls");  //clear console

        cout<<"DnD Tracker:indev"<<endl<<endl<<endl;
        cout<<"Main Menu:"<<endl<<endl;
        cout<<"Load Characters: (not working yet)"<<menu_options[0]<<endl;
        cout<<"Create new Character: "<<menu_options[1]<<endl;
        cout<<"Quit: "<<menu_options[2]<<endl;
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
                    load_Characters(character_list);
                    break;
                case 2:
                    cout<<"Create new Character"<<endl;
                    //Character creator
                    character_list.push_back(create_character(cout));
                    cout<<"Saving Character to file"<<endl;

                    break;
                case 3:
                    running = false;
                    break;
            }
            option = 0;
            valid=false;
    }
            
    //Select Characters
    //Game/Use
        //Combat
            //Ability uses
            //movement??
            //end combat (goes to normal view)
        //Normal View
            //skill checks
            //rests


            


    //      EXIT GRACEFULLY

    //save Characters
    save_Characters(character_list);
    
    //cleanup character pointers and character list
    for (size_t i=0; i<character_list.size(); i++){
        delete character_list[i];
        character_list[i] = nullptr;
    }

    character_list.clear();


    
    return 0;
}