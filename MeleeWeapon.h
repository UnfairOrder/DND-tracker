#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "IWeapon.h"

class MeleeWeapon : public IWeapon{
    public:
        MeleeWeapon();
        MeleeWeapon(
            std::string _name, 
            std::string _description,
            std::string _weapon_type,
            std::string _damage,
            double _weight); //non default constructor.

    
        double get_weight()const{return weight;}
        std::string get_name()const{return name;}
        std::string get_description()const{return description;}
        std::string get_weapon_type()const{return weapon_type;}
        std::string get_damage()const{return damage;}
        int get_rangeMin()const{return rangeMin;}
        int get_rangeMax()const{return rangeMax;}

    private:
        double weight;
        std::string name;
        std::string description;
        std::string weapon_type;
        std::string damage;
        int rangeMax=5;
        int rangeMin=0;
    
};



#endif