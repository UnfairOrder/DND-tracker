#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <string>

/**
 * @brief Weapon Interface
 * 
 */

class IWeapon : public Item{
    public:
        virtual std::string get_weapon_type()const=0;   //weapon type might need to be a vector
        virtual std::string get_damage()const=0;
        virtual int get_rangeMin()const=0;
        virtual int get_rangeMax()const=0;
        

};


#endif