#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <class T>
struct Item {
    T item;
    Item<T> *pol;
    Item() {
        this->item = 0;
        this->pol = nullptr;
    }
    Item(T value) {
        this->item = value;
        this->pol = nullptr;
    }
};
template <class T>
struct List {
    T* pHead = nullptr;
    void add(int value) {
        if (!pHead) {
            pHead = new T(value);
        }
        else {
            T* lastone = pHead;
            while (lastone->pol) {
                lastone = lastone->pol;
            }
            lastone->pol = new T(value);
        }
        
    }
    void delete_Last() {
        T* current = pHead;
        while (current->pol->pol) {
            current = current->pol;
        }
        delete current->pol;
        current->pol = nullptr;
    }
    void print() {
        const T* current = pHead;
        while (current) {
            cout << current->item << " ";
            current = current->pol;
        }
    }
    void DeleteWthIndex(int index) {
        T* current = pHead;
        if (index == 0) {
            pHead = current->pol;
        }
        else {
            for (int i = 0; i < index - 1 && current->pol != nullptr; i++) {
                current = current->pol;
            }
            T* next = current->pol;
            current->pol = next->pol;
            delete next;
        }
    }
    void AddWthIndex(int index, int val) {
        if (index == 0) {
            T* newItem = new T(val);
            newItem->pol = pHead;
            pHead = newItem;
        }
        else {
            T* NewIt = new T(val);
            T* current = pHead;
            for (int i = 0; i < index - 1 && current->pol != nullptr; i++) {
                current = current->pol;
            }
            NewIt->pol = current->pol;
            current->pol = NewIt;
        }
    }
    int getItem(int index) {
        T* current = pHead;
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
        T* current = pHead;
        while (current->pol != nullptr) {
            current = current->pol;
            count++;
        }
        return count;
    }
    void swap(int indexOne, int indexTwo, List it) {
        int n = (indexOne > indexTwo) ? indexOne : indexTwo;
        int k = (indexOne < indexTwo) ? indexOne : indexTwo;
        if (indexOne == indexTwo || n > it.count()-1 || k > it.count() - 1) {
            cout << "Error" << endl;
        }
        else {
            int a = it.getItem(k);
            int b = it.getItem(n);
            T* current = pHead;
            for (int i = 0; i < it.count(); i++) {
                if (i == k) current->item = b;
                if (i == n) current->item = a;
                current = current->pol;
            }
        }
    }
    void sort(List list, int first, int last) {
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
    
};

int main() {
    List<Item<int>> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.print();
    cout << endl;
    list.delete_Last();
    list.print();
    cout << endl;
    list.DeleteWthIndex(3);
    list.print();
    cout << endl;
    cout << list.getItem(0) << endl;
    list.AddWthIndex(0, 7);
    list.print();
    cout << endl;
    cout << list.count() << endl;
    list.swap(3, 0, list);
    list.print();
    cout << endl;
    list.sort(list, 0, list.count()-1);
    list.print();
    return 0;
}