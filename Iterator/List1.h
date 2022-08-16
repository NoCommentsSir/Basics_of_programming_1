#ifndef LIST1_H
#define LIST1_H
#pragma once
#include "Item.h"
#include <iostream>
using namespace std;
struct Iterator;
struct List {
    Item* pHead = nullptr;
    void add(int);
    void delete_Last();
    string print();
    void DeleteWthIndex(int , List);
    void AddWthIndex(int, int, List);
    int getItem(int);
    int count();
    void swap(int, int, List);
    void sort(List, int, int);
    Iterator *create();
};
#endif