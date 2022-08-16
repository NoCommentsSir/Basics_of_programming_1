#include <iostream>
#include "Item.cpp"
#include "List2Cop.cpp"
#include "Iterator.cpp"
int main(){
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    Iterator* it = list.create();
    while(it->Has_Next()){
        cout<<it->getItem()->item<<endl;
    }
    return 0;
}