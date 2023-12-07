#ifndef ITEM_H
#define ITEM_H
#include <iostream>
/**
 * @brief An Item Interface
 * literally just defines the get weight method.
 */

class Item{
    public:
        virtual double get_weight()const=0;
        virtual std::string get_name()const=0;
        virtual std::string get_description()const=0;
        

};

#endif