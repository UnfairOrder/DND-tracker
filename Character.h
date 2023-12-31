#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "PlayerClass.h"
#include <cmath>
#include <map>
#include <fstream>
#include "Classes.h"
#include "ItemList.h"
#include "Inventory.h"

/**
 * @brief The Character class, contains all the information and variables that would be needed for a dnd character.
 * 
 * 
 */
class Character{

    public:
        Character(std::string _name, std::string _race, float _height, int _str, int _dex, int _con, int _wis, int _int, int _chr, int level, PlayerClass& _CharacterClass);
        Character(std::string _name, std::string _race, float _height, std::vector<int> stat_vector,int level, PlayerClass& _CharacterClass);
        Character();
        //the big 3
        Character(const Character & player);
        Character& operator=(const Character&);
        ~Character();

        
        std::string getName() const;
        void setName(std::string);

        //Inventory
        Inventory player_inventory;

        // at the moment, these are not going to scan the equipped items for bonuses from items.
        // setters only used at creation.
        int getStrength() const;
        void setStrength(int str);

        int getDexterity() const;
        void setDexterity(int dex);

        int getConstitution() const;
        void setConstitution(int con);

        int getWisdom() const;
        void setWisdom(int wis);

        int getIntelligence() const;
        void setIntelligence(int intelligence);

        int getCharisma() const;
        void setCharisma(int _cha);

        int getStr_mod()const;
        int getDex_mod()const;
        int getCon_mod()const;
        int getWis_mod()const;
        int getInt_mod()const;
        int getCha_mod()const;

        std::string get_race()const{return race;} //If the race class is added then this will change some.
        
        float get_height()const{return height;};


        int get_level()const{return level;}
        void set_level(int level);
        int get_movespeed()const;
        int get_proficiency_bonus()const{return prof_bonus;}
        int get_armor_class()const;

        void setPlayerClass(PlayerClass c){character_class = c;}
        PlayerClass getPlayerClass(){return character_class;}

        //  HP stuff

        int get_max_hp()const{return max_hp;}
        /**
         * @brief Set the current hp object
         * validates that the hp does not go over max, though it can go below zero.
         * @param hp the hp to set
         */
        void set_current_hp(int hp);

        int get_current_hp()const{return current_hp;}

        /**
         * @brief damages the character by reducing their hitpoints
         * 
         * @param damage 
         */
        void damage(int damage);

        /**
         * @brief heals the character by increasing their hitpoints, capping at their max hp.
         * 
         * @param healing 
         */
        void heal(int healing);

        //      PROFICIENCIES

        //Using a map for this. We haven't learned it in class yet, but it seems to work like a python dict, so that sounds good

        std::map<std::string, int> skill_list;

        int proficiency_bonus(){return round(1.5+0.25*level);}
        void set_prof_bonus(int bonus);

    /**
     * @brief saves the character to a file with named : CharacterName.txt
     * 
     * @return std::string the name of the file
     */
        std::string save();



    private:
    /**
     * @brief calculates the character's proficiency bonus based off their level
     * 
     * @return int 
     */
   
    int prof_bonus;


    /**
     * @brief sets all stat variables with values from vector of stats
     * 
     * @param stats vector of stats form: [str, dex, con, wis, int]
     */
    void set_stats(std::vector<int>stats);


    std::string name;
    int strength, dexterity, constitution, wisdom, intelligence, charisma;
    int strength_mod, dex_mod, con_mod, wis_mod, int_mod, cha_mod;
    std::string race;   //This could be made an object, time permitting
    float height;   //in Inches
    int current_hp;


    // pointer to player's class object. pointer allows for polymorphism.
    // I don't think I need a destructor yet
    // Doing an internal pointer because I don't think that runtime inheritence is a thing, at least that we've learned yet, and this also opens the door for multiclassing.
    // This also provides access to class specific leveling mechanics and feature access. 
    PlayerClass character_class;



    /*
    All of the proficiency vectors may end up being bool vectors with the certain skills or item types indexed to certain values
    I'd like to use something like a python dictionary for this, so I'm going to wait to begin implementing these till
    we learn how that sort of thing works for c++.
    */
    std::vector<std::string> skill_prof;
    std::vector<std::string> weapon_prof;
    std::vector<std::string> armor_prof;

    int max_hp;
    int level;
    int move_speed;
    int armor_class;

    /**
     * @brief calculates the maximum hp for a Character based on their Character Class and level
     * 
     * @return int 
     */
    int calculate_max_hp()const;
    void set_max_hp(int hp);

/*
Implement these once the Item class is done. I think I'd like to use an array or some other data type for the
inventory where I can keep track of the quantities of the items. The alternative is to create an ItemStack object
that will keep the item quantity data inside of it, only issue then is then having the methods in character
that use the ItemStack remove it from inventory if the value hits zero. Having to check that in each item might be tedious.
So I'd like to use a different data structure. Maybe two parallel vectors?
*/
    // Item equipped_weapon;
    // Item equipped_Armor;
    // std::vector<Item>; 

};

/**
 * @brief verifys that stats are within the bounds of 0->30 and bounds the stat passed
 * 
 * @param stat integer for the stat
 */
void verifyStat(int & stat);
/**
 * @brief generates character stats using 4d6 drop 1 method
 * 
 * @return std::vector<int> [str, dex, con, wis, int]
 */
std::vector<int> generate_stats();

/**
 * @brief loads a character from a file stream
 * 
 * @return pointer to character object.
 */
Character* load_Character( std::ifstream &fin );


#endif
