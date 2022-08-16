#ifndef ITEM_H
#define ITEM_H
#pragma once
struct Item {
    int item;
    Item *pol;
    Item();
    Item(int);
};
#endif