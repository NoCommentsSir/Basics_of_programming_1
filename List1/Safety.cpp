#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Item {
    int item;
    Item *pol;
    Item() {
        this->item = 0;
        this->pol = nullptr;
    }
    Item(int value) {
        this->item = value;
        this->pol = nullptr;
    }
};
struct List {
    Item* pHead = nullptr;
    void add(int value) {
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
    void delete_Last() {
        Item* current = pHead;
        while (current->pol->pol) {
            current = current->pol;
        }
        delete current->pol;
        current->pol = nullptr;
    }
    string print() {
        const Item* current = pHead;
        string s = "";
        while (current) {
            s = s + to_string(current->item) + " ";
            current = current->pol;
        }
        return s;
    }
    void DeleteWthIndex(int index, List list) {
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
    void AddWthIndex(int index, int val, List list) {
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
    int getItem(int index) {
        Item* current = pHead;
        if (index == 0) {
            return pHead->item;
        }
        for (int i = 0; i <= index - 1 && current->pol != nullptr; i++) {
            current = current->pol;
        }
        return current->item;
    }
    int count() {
        int count = 1;
        Item* current = pHead;
        while (current->pol != nullptr) {
            current = current->pol;
            count++;
        }
        return count;
    }
    void swapListItem(int indexOne, int indexTwo, List it) {
        const int count = it.count();
        int n = (indexOne > indexTwo) ? indexOne : indexTwo;
        int k = (indexOne < indexTwo) ? indexOne : indexTwo;
        if (indexOne == indexTwo || n > count || k > count) {
            cout << "Error" << endl;
            return;
        }
        else if (k == 0) {
            Item* a = pHead;
            Item* b = pHead;
            Item* current = pHead;
            if(n-k > 1){
                for (int i = 0; i < count; i++) {
                    if (i + 1 == n) b = current->pol;
                    current = current->pol;
                }
                current = pHead;
                Item* x;
                x = a->pol;
                Item* y;
                y = b->pol;
                for (int i = 0; i < count; i++) {
                    if (i == 0) {
                        pHead = b;
                        pHead->pol = x;
                    }
                    if (i + 1 == n) {
                        current->pol = a;
                        current->pol->pol = y;
                    }
                    current = current->pol;
                }
            }
            else if (k == 0 && n == 1) {
                b = pHead->pol;
                Item* y;
                y = b->pol;
                pHead = b;
                pHead->pol = a;
                pHead->pol->pol = y;
            }
        }
        else if (k != 0 && n - k > 1) {
            Item* a = pHead;
            Item* b = pHead;
            Item* current = pHead;
            for (int i = 0; i < count; i++) {
                if (k == count - 1) {
                    break;
                }
                if (i + 1 == k) {
                    a = current->pol;
                }
                if (i + 1 == n) {
                    b = current->pol;
                }
                current = current->pol;
            }
            current = pHead;
            Item* x;
            x = a->pol;
            Item* y;
            y = b->pol;
            for (int i = 0; i < count; i++) {
                if (i + 1 == k) {
                    current->pol = b;
                    current->pol->pol = x;
                }
                if (i + 1 == n) {
                    current->pol = a;
                    current->pol->pol = y;
                }
                current = current->pol;
            }
        }
        else if (n - k == 1) {
            Item* a = pHead;
            Item* b = pHead;
            Item* current = pHead;
            for (int i = 0; i < count; i++) {
                if (k == count - 1) {
                    break;
                }
                if (i + 1 == k) {
                    a = current->pol;
                }
                if (i + 1 == n) {
                    b = current->pol;
                }
                current = current->pol;
            }
            current = pHead;
            Item* y;
            y = b->pol;
            for (int i = 0; i < count; i++) {
                if (i + 1 == k) {
                    current->pol = b;
                    current->pol->pol = a;
                    current->pol->pol->pol = y;
                }
                current = current->pol;
            }
        }
    }
    void sort(List &list, int first, int last) {
        const int a = list.count();
        int f = first;
        int l = last;
        int mid = list.getItem((first + last) / 2);
        while (f <= l) {
            while (getItem(f) < mid && f < last) {
                f++;
            }
            while (getItem(l) > mid && l > first) {
                l--;
            }
            if (f == l) {
                f++;
                l--;
            }
            if (f < l) {
                list.swapListItem(f, l, list);
                f++;
                l--;
            }
        }
        if (f < last) list.sort(list, f, last);
        if (first < l) list.sort(list, first, l);
    }
};