#include "Iterator.h"
Iterator::Iterator(List* collection){
    this->item = collection->pHead;
};
bool Iterator::Has_Next(){
    return item!=nullptr;
};
Item* Iterator::getItem(){
    if(item == nullptr)return nullptr;
    Item* current = item;
    item = item->pol;
    return current;
};