#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "IWeapon.h"

class MeleeWeapon : public IWeapon{
    public:
        MeleeWeapon();

        MeleeWeapon(const MeleeWeapon& w);  //Copy Constructor

        MeleeWeapon(
            std::string _name, 
            std::string _description,
            std::string _weapon_type,
            std::string _damage,
            double _weight); //non default constructor.

        void operator=(const MeleeWeapon& weapon);

        double get_weight()const override {return weight;}
        std::string get_name()const override {return name;}
        std::string get_description()const override{return description;}
        std::string get_weapon_type()const override{return weapon_type;}
        std::string get_damage()const override{return damage;}
        int get_rangeMin()const override{return rangeMin;}
        int get_rangeMax()const override{return rangeMax;}

    private:
        double weight;
        std::string name;
        std::string description;
        std::string weapon_type;
        std::string damage;
        int rangeMax=5;
        int rangeMin=0;
    
};

std::ostream & operator<<(std::ostream &out, const MeleeWeapon&w);


#endif