#ifndef INVENTORY_H
#define INVENTORY_h

#include "Item.h"

class Inventory {
public:
    Inventory();
    ~Inventory();

    int size() const;
    Item* get_item(const int POS) const;
    int get_quantity(const int POS)const;
    void set(const int POS, Item* VALUE, const int Q);
    void insert(const int POS, Item* VALUE, const int Q);
    void remove(const int POS);
    int find(const Item* VALUE) const;

private: 
    struct Node {
        Item* value;
        int quantity;
        Node* pNext;
        Node* pPrev;
    };

    Node* _pHead;
    Node* _pTail;
    int _size;
};

#endif