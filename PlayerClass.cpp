#include "PlayerClass.h"

    PlayerClass::PlayerClass(
    std::string _description,
    std::string _hit_dice,
    std::vector<std::string> _weapon_proficiencies,
    std::vector<std::string> _armor_proficiencies,
    std::vector<std::string> _tool_proficiencies,
    std::vector<std::string> _saving_throw_proficiencies,
    std::vector<std::string> _skill_proficiencies
    ){
        description=_description;
        hit_dice=_hit_dice;
        weapon_proficiencies=_weapon_proficiencies;
        armor_proficiencies=_armor_proficiencies;
        tool_proficiencies=_tool_proficiencies;
        saving_throw_proficiencies = _saving_throw_proficiencies;
        skill_proficiencies = _skill_proficiencies;
    }

int PlayerClass::calculate_class_hitpoints(int level)const{
    if (level==1){
        return stoi(hit_dice.substr(hit_dice.find('d')+1,hit_dice.size()));
    }
    else{
        int hp_sum =0;
        for (int i=0; i<level; i++){
            hp_sum+=roll(hit_dice);
        }
        return hp_sum;
    }
}

