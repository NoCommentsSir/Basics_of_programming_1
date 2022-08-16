#pragma once
#include "Item.h"
    Item::Item() {
        this->item = 0;
        this->pol = nullptr;
    }
    Item::Item(int value) {
        this->item = value;
        this->pol = nullptr;
    }
