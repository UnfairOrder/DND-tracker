#include "PlayerClass.h"
    PlayerClass::PlayerClass(){
        
    }

    PlayerClass::PlayerClass(
    std::string _name,
    std::string _description,
    std::string _hit_dice,
    std::vector<std::string> _weapon_proficiencies,
    std::vector<std::string> _armor_proficiencies,
    std::vector<std::string> _tool_proficiencies,
    std::vector<std::string> _saving_throw_proficiencies,
    std::vector<std::string> _skill_proficiencies
    ){
        name=_name;
        description=_description;
        hit_dice=_hit_dice;
        weapon_proficiencies=_weapon_proficiencies;
        armor_proficiencies=_armor_proficiencies;
        tool_proficiencies=_tool_proficiencies;
        saving_throw_proficiencies = _saving_throw_proficiencies;
        skill_proficiencies = _skill_proficiencies;
    }

    void PlayerClass::operator=(const PlayerClass& pc){
        name=pc.get_name();
        description=pc.get_description();
        hit_dice=pc.get_hit_dice();
        weapon_proficiencies=pc.get_weapon_proficiencies();
        armor_proficiencies=pc.get_armor_proficiencies();
        tool_proficiencies=pc.get_tool_proficiencies();
        saving_throw_proficiencies = pc.get_saving_throw_proficiencies();
        skill_proficiencies = pc.get_skill_proficiencies();
    }

int PlayerClass::calculate_class_hitpoints(int level)const{
    if (level==1){
        return stoi(hit_dice.substr(hit_dice.find('d')+1,hit_dice.size()));
    }
    else{
        int hp_sum =stoi(hit_dice.substr(hit_dice.find('d')+1,hit_dice.size()));
        for (int i=0; i<level-1; i++){
            hp_sum+=roll(hit_dice);
        }
        return hp_sum;
    }
}

std::ostream & operator<<(std::ostream &out, const PlayerClass&pc){
    out<<pc.get_name()<<":"<<std::endl;
    out<<pc.get_description()<<std::endl;
    out<<"Hit Dice: "<<pc.get_hit_dice()<<std::endl;
    //Vectors should then be printed here with a for loop but I don't feel the need to do that yet.
    return out;
}





