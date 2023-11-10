#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "IWeapon.h"

class RangedWeapon : public IWeapon{
    public:
        RangedWeapon();
        RangedWeapon(const RangedWeapon& w);
        RangedWeapon(
            std::string _name, 
            std::string _description,
            std::string _weapon_type,
            std::string _damage,
            double _weight,
            int _rangeMin,
            int _rangeMax); //non default constructor.


        double get_weight()const override{return weight;}
        std::string get_name()const override{return name;}
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
        int rangeMin;
        int rangeMax;
        // ConsumableItem for ammunition


};

std::ostream & operator<<(std::ostream &out, const RangedWeapon&w);



#endif