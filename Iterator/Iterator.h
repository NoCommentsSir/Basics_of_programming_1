#ifndef ITERATOR_H
#define ITERATOR_H
#pragma once
#include "Item.h"
#include "List1.h"
struct Iterator{
    List collection;
    Item* item;
    Iterator(List* collection);
    bool Has_Next();
    Item *getItem();
};
#endif