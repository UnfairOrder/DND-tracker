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
        virtual std::string get_weapon_type()=0;
        virtual std::string get_damage()=0;
        virtual int get_rangeMin()=0;
        virtual int get_rangeMax()=0;
        

};


#endif