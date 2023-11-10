
#include "MeleeWeapon.h"

    MeleeWeapon::MeleeWeapon(){

    }

    MeleeWeapon::MeleeWeapon(
        std::string _name, 
        std::string _description,
        std::string _weapon_type,
        std::string _damage,
        double _weight){
    //Ranged Weapon Constructor
        name = _name;
        description = _description;
        weapon_type = _weapon_type;
        damage = _damage;
        weight = _weight;
        }


        