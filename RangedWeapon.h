#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "IWeapon.h"

class RangedWeapon : public IWeapon{
    public:
        RangedWeapon();
        RangedWeapon(
            std::string _name, 
            std::string _description,
            std::string _weapon_type,
            std::string _damage,
            double _weight,
            int _rangeMin,
            int _rangeMax); //non default constructor.


        double get_weight(){return weight;}
        std::string get_name(){return name;}
        std::string get_description(){return description;}
        std::string get_weapon_type(){return weapon_type;}
        std::string get_damage(){return damage;}
        int get_rangeMin(){return rangeMin;}
        int get_rangemax(){return rangeMax;}

    private:
        double weight;
        std::string name;
        std::string description;
        std::string weapon_type;
        std::string damage;
        int rangeMin;
        int rangeMax;
        // ConsumableItem for ammunition


};



#endif