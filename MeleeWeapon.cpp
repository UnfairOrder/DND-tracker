
#include "MeleeWeapon.h"

    MeleeWeapon::MeleeWeapon(){

    }
    /**
     * @brief Copy Constructor
     * 
     * @param w
     */
    MeleeWeapon::MeleeWeapon(const MeleeWeapon& w){
        name = w.get_name();
        description = w.get_description();
        weapon_type = w.get_weapon_type();
        damage = w.get_damage();
        weight = w.get_weight();
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


std::ostream & operator<<(std::ostream &out, const MeleeWeapon&w){
    out<<w.get_name()<<":"<<std::endl;
    out<<w.get_description()<<std::endl;
    out<<"Damage: "<<w.get_damage()<<std::endl;
    out<<"Weapon Attributes: "<<w.get_weapon_type()<<std::endl;
    return out;
}        