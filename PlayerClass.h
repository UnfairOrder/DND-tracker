#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H


#include <string>
#include "DiceRoller.h"
#include <vector>
#include <iostream>

// not abstract at the moment
class PlayerClass{

    public:
        PlayerClass();

        void operator=(const PlayerClass& pc);
        
        
        
        /**
         * @brief Construct a new Player Class object
         * 
         * @param _description string description of the class
         * @param _hit_dice string hit dice of form 'nds' where n is number of rolls and s is sides.
         * @param _weapon_proficiencies vector of weapon proficiency strings.
         * @param _armor_proficiencies vector of armor proficiency strings.
         * @param _tool_proficiencies vector of tool proficiency strings.
         * @param _saving_throw_proficiencies vector of saving throw proficencies.
         * @param _skill_proficiencies vector of skill profiencies.
         */
        PlayerClass(
        std::string _name,
        std::string _description,
        std::string _hit_dice,
        std::vector<std::string> _weapon_proficiencies,
        std::vector<std::string> _armor_proficiencies,
        std::vector<std::string> _tool_proficiencies,
        std::vector<std::string> _saving_throw_proficiencies,
        std::vector<std::string> _skill_proficiencies
        );
        std::string get_name()const{return name;}
        std::string get_description()const {return description;}
        std::vector<std::string> get_weapon_proficiencies()const {return weapon_proficiencies;}
        std::vector<std::string> get_armor_proficiencies()const {return armor_proficiencies;}
        std::vector<std::string> get_tool_proficiencies()const {return tool_proficiencies;}
        std::vector<std::string> get_saving_throw_proficiencies() const {return saving_throw_proficiencies;}
        std::vector<std::string> get_skill_proficiencies() const {return skill_proficiencies;}
        std::vector<std::string> get_abilities() const {return abilities;}
        std::string get_hit_dice() const {return hit_dice;}


        // void set_weapon_proficiencies(std::vector<std::string>);
        // void set_armor_proficiencies(std::vector<std::string>);
        // void set_tool_proficiencies(std::vector<std::string>);
        // void set_saving_throw_proficiencies(std::vector<std::string>);
        // void set_skill_proficiencies(std::vector<std::string>);
        // void set_abilities(std::vector<std::string>);
        // void set_hit_dice(std::string hit_dice);
        /**
         * @brief calculates the hitpoints that are due exclusivley to the class component
         *         it does run the full calculation, every time it's run.
         * @param level 
         * @return int 
         */
        int calculate_class_hitpoints(int level)const; 

    private:
        std::string name;
        std::vector<std::string> weapon_proficiencies;
        std::vector<std::string> armor_proficiencies;
        std::vector<std::string> tool_proficiencies;
        std::vector<std::string> saving_throw_proficiencies;
        std::vector<std::string> skill_proficiencies;

        //abilities will be changed to include actual ability objects.
        //level will impact this. switch case perhaps?
        std::vector<std::string> abilities;
        std::string hit_dice;
        std::string description;

};

std::ostream & operator<<(std::ostream &out, const PlayerClass&pc);



#endif