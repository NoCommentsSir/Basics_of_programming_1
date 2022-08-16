#pragma once
#include "List1.h"
#include "Iterator.h"
    void List::add(int value) {
        if (!pHead) {
            pHead = new Item(value);
        }
        else {
            Item* lastone = pHead;
            while (lastone->pol) {
                lastone = lastone->pol;
            }
            lastone->pol = new Item(value);
        }
        
    }
    void List::delete_Last() {
        Item* current = pHead;
        while (current->pol->pol) {
            current = current->pol;
        }
        delete current->pol;
        current->pol = nullptr;
    }
    string List::print() {
        const Item* current = pHead;
        string s = "";
        while (current) {
            s = s + to_string(current->item) + " ";
            current = current->pol;
        }
        return s;
    }
    void List::DeleteWthIndex(int index, List list) {
        Item* current = pHead;
        if(index >= list.count()) cout<<"Error"<<endl;
        if (index == 0) {
            pHead = current->pol;
        }
        else if(index < list.count()) {
            for (int i = 0; i < index - 1 && current->pol != nullptr; i++) {
                current = current->pol;
            }
            Item* next = current->pol;
            current->pol = next->pol;
            delete next;
        }
    }
    void List::AddWthIndex(int index, int val, List list) {
        if(index > list.count()) cout<<"Error"<<endl;
        if (index == 0) {
            Item* newItem = new Item(val);
            newItem->pol = pHead;
            pHead = newItem;
        }
        else if(index <= list.count()){
            Item* NewIt = new Item(val);
            Item* current = pHead;
            for (int i = 0; i < index - 1 && current->pol != nullptr; i++) {
                current = current->pol;
            }
            NewIt->pol = current->pol;
            current->pol = NewIt;
        }
    }
    int List::getItem(int index) {
        Item* current = pHead;
        if (index == 0) {
            return pHead->item;
        }
        for (int i = 0; i <= index - 1 && current->pol != nullptr; i++) {
            current = current->pol;
        }
        return current->item;
    }
    int List::count() {
        int count = 1;
        Item* current = pHead;
        while (current->pol != nullptr) {
            current = current->pol;
            count++;
        }
        return count;
    }
    void List::swap(int indexOne, int indexTwo, List it) {
        int n = (indexOne > indexTwo) ? indexOne : indexTwo;
        int k = (indexOne < indexTwo) ? indexOne : indexTwo;
        if (indexOne == indexTwo || n > it.count()-1 || k > it.count() - 1) {
            cout << "Error" << endl;
        }
        else {
            int a = it.getItem(k);
            int b = it.getItem(n);
            Item* current = pHead;
            for (int i = 0; i < it.count(); i++) {
                if (i == k) current->item = b;
                if (i == n) current->item = a;
                current = current->pol;
            }
        }
    }
    void List::sort(List list, int first, int last) {
        int f = first;
        int l = last;
        int mid = list.getItem((first+last) / 2);
        do {
            while (getItem(f) < mid) {
                f++;
            }
            while (getItem(l) > mid) {
                l--;
            }
            if (f == l) {
                f++;
                l--;
            }
            if (f < l) {
                list.swap(f, l, list);
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) list.sort(list, first, l);
        if (f < last) list.sort(list, f, last);
    }
    Iterator* List::create(){
        return new Iterator(this);
    };

