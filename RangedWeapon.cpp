
#include "RangedWeapon.h"

    RangedWeapon::RangedWeapon(){

    }

    RangedWeapon::RangedWeapon(
        std::string _name, 
        std::string _description,
        std::string _weapon_type,
        std::string _damage,
        double _weight,
        int _rangeMin,
        int _rangeMax){
    //Ranged Weapon Constructor
        name = _name;
        description = _description;
        weapon_type = _weapon_type;
        damage = _damage;
        weight = _weight;
        rangeMin = _rangeMin;
        rangeMax = _rangeMax;
        }

std::ostream & operator<<(std::ostream &out, const RangedWeapon&w){
    out<<w.get_name()<<":"<<std::endl;
    out<<w.get_description()<<std::endl;
    out<<"Damage: "<<w.get_damage()<<std::endl;
    out<<"Weapon Attributes: "<<w.get_weapon_type()<<", ("<<w.get_rangeMin()<<"/"<<w.get_rangeMax()<<")"<<std::endl;

}
