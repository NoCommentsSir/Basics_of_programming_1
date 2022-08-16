#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
struct Item {
    int data;
    Item* pNext = nullptr;
    Item* pPrev = nullptr;
    Item(int data) {
        this->pNext = nullptr;
        this->pPrev = nullptr;
        this->data = data;
    }
};
struct List {
    Item* Head = nullptr;
    Item* Tail = nullptr;
    void add(int value) {
        if (!Head) {
            //Если пустой -> создаем головной элемент
            Item* newItem = new Item(value);
            Head = newItem;
            Tail = newItem;
            return;
        }
        Item* newit = new Item(value);
        Tail->pNext = newit;
        newit->pPrev = Tail;
        Tail = newit;
    }
    void delete_Last() {
        if (Tail == nullptr) return;
        if (!Head->pNext) {
            delete Tail;
            Tail = nullptr;
            Head = nullptr;
            return;
        }
        else {
            Tail = Tail->pPrev;
            delete Tail->pNext;
            Tail->pNext = nullptr;
        }
    }
    void print() {
        Item* current = Head;
        while (current) {
            cout << current->data << " ";
            current = current->pNext;
        }
        cout << endl;
    }
    void printReverse() {
        Item* current = Tail;
        while (current) {
            cout << current->data << " ";
            current = current->pPrev;
        }
        cout << endl;
    }
    void DeleteWthIndex(int index, int count) {
        int a = count;
        Item* current = Head;
        if (index >= a) cout << "Error" << endl;
        if (index == 0) {
            Head = current->pNext;
            delete Head->pPrev;
            Head->pPrev = nullptr;
        }
        else if (index == count - 1) {
            Tail = Tail->pPrev;
            delete Tail->pNext;
            Tail->pNext = nullptr;
        }
        else if (index < count - 1) {
            for (int i = 0; i < index && current->pNext != nullptr; i++) {
                current = current->pNext;
            }
            Item* next = current->pNext;
            current = current->pPrev;
            delete current->pNext;
            current->pNext = next;
            next->pPrev = current;
        }
    }
    void AddWthIndex(int index, int val) {
        if (index == 0) {
            Item* newItem = new Item(val);
            newItem->pNext = Head;
            Head->pPrev = newItem;
            Head = newItem;
        }
        else{
            Item* NewIt = new Item(val);
            Item* current = Head;
            for (int i = 0; i < index - 1 && current->pNext != nullptr; i++) {
                current = current->pNext;
            }
            current->pNext->pPrev = NewIt;
            NewIt->pNext = current->pNext;
            NewIt->pPrev = current;
            current->pNext = NewIt;
           
        }
    }
    int count() {
        int count = 1;
        Item* current = Head;
        while (current->pNext != nullptr) {
            current = current->pNext;
            count++;
        }
        return count;
    }
    Item* getItem(int index) {
        
        Item* current = Head;
        int count = 0;
        while (current && count != index) {
            current = current->pNext;
            count++;
        }
        return current;
    }
    int getItem2(int index, int count) {
        Item* current = Head;
        if (index == 0) {
            return Head->data;
        }
        for (int i = 0; i < index && current->pNext != nullptr; i++) {
            current = current->pNext;
        }
        return current->data;
    }
    void swapListItem(int indexOne, int indexTwo, int count) {
        int n = (indexOne > indexTwo) ? indexOne : indexTwo;
        int k = (indexOne < indexTwo) ? indexOne : indexTwo;
        if (indexOne == indexTwo || n > count || k > count) {
            cout << "Error" << endl;
            return;
        }
        else if (k == 0) {
            if (n != count - 1) {
                Item* a = Head;
                Item* b = nullptr;
                Item* current = Head;
                if (n - k > 1) {
                    for (int i = 0; i < count; i++) {
                        if (i + 1 == n) b = current->pNext;
                        current = current->pNext;
                    }
                    current = Head;
                    Item* y;
                    y = b->pNext;
                    for (int i = 0; i < count; i++) {
                        if (i == 0) {
                            b->pNext = Head->pNext;
                            Head = b;
                            b->pPrev = nullptr;
                            b->pNext->pPrev = b;
                        }
                        if (i + 1 == n) {
                            current->pNext = a;
                            a->pPrev = current;
                            a->pNext = y;
                            y->pPrev = a;
                        }
                        current = current->pNext;
                    }
                }
                else if (k == 0 && n == 1) {
                    b = Head->pNext;
                    Item* y;
                    y = b->pNext;
                    Head = b;
                    Head->pNext = a;
                    Head->pPrev = nullptr;
                    a->pPrev = Head;
                    a->pNext = y;
                    y->pPrev = a;
                }
            }
            else {
                Item* a = Head;
                Item* b = Tail;;
                b->pNext = a->pNext;
                a->pNext = nullptr;
                b->pNext->pPrev = b;
                a->pPrev = b->pPrev;
                b->pPrev = nullptr;
                a->pPrev->pNext = a;
                Head = b;
                Tail = a;
            }
        }
        if (n == count - 1) {
            if (k != 0) {
                Item* a = nullptr;
                Item* b = Tail;
                Item* current = Head;
                if (n - k > 1) {
                    for (int i = 0; i < count; i++) {
                        if (i + 1 == k) a = current->pNext;
                        current = current->pNext;
                    }
                    current = Head;
                    Item* x;
                    x = a->pNext;
                    Item* y;
                    y = b->pPrev;
                    for (int i = 0; i < count; i++) {
                        if (i + 1 == k) {
                            current->pNext = b;
                            b->pPrev = current;
                            b->pNext = x;
                            x->pPrev = b;
                        }
                        if (i == count - 1) {
                            Tail = a;
                            Tail->pPrev = y;
                            Tail->pNext = nullptr;
                            y->pNext = Tail;
                        }
                        current = current->pNext;
                    }
                }
                else if (k == count - 2) {
                    a = Tail->pPrev;
                    Item* y;
                    y = a->pPrev;
                    Tail = a;
                    Tail->pPrev = b;
                    Tail->pNext = nullptr;
                    b->pNext = Tail;
                    b->pPrev = y;
                    y->pNext = b;
                }
            }

        }
        else if (k != 0 && n - k > 1) {
            Item* a = nullptr;
            Item* b = nullptr;
            Item* current = Head;
            for (int i = 0; i < count; i++) {
                if (k == count - 1) {
                    break;
                }
                if (i + 1 == k) {
                    a = current->pNext;
                }
                if (i + 1 == n) {
                    b = current->pNext;
                }
                current = current->pNext;
            }
            current = Head;
            Item* x;
            x = a->pNext;
            Item* y;
            y = b->pNext;
            for (int i = 0; i < count; i++) {
                if (i + 1 == k) {
                    current->pNext = b;
                    b->pPrev = current;
                    b->pNext = x;
                    x->pPrev = b;
                }
                if (i + 1 == n) {
                    current->pNext = a;
                    a->pPrev = current;
                    a->pNext = y;
                    y->pPrev = a;
                }
                current = current->pNext;
            }
        }
        else if (n - k == 1) {
            Item* a = nullptr;
            Item* b = nullptr;
            Item* current = Head;
            for (int i = 0; i < count; i++) {
                if (k == count - 1) {
                    break;
                }
                if (i + 1 == k) {
                    a = current->pNext;
                }
                if (i + 1 == n) {
                    b = current->pNext;
                }
                current = current->pNext;
            }
            current = Head;
            Item* y;
            y = b->pNext;
            for (int i = 0; i < count; i++) {
                if (i + 1 == k) {
                    current->pNext = b;
                    b->pPrev = current;
                    a->pPrev = b;
                    b->pNext = a;
                    a->pNext = y;
                    y->pPrev = a;
                }
                current = current->pNext;
            }
        }
    }
    void sortQ(List& list, int first, int last) {
        const int a = list.count();
        int f = first;
        int l = last;
        int mid = list.getItem2((first + last) / 2, a);
        while (f <= l) {
            while (list.getItem2(f, a) < mid && f < last) {
                f++;
            }
            while (list.getItem2(l, a) > mid && l > first) {
                l--;
            }
            if (f == l) {
                f++;
                l--;
            }
            if (f < l) {
                list.swapListItem(f, l, a);
            }
        }
        if (f < last) list.sortQ(list, f, last);
        if (first < l) list.sortQ(list, first, l);
    }
    void sortB(List& list) {
        const int a = list.count();
        for (int i = 0; i < a; i++) {
            for (int j = a - 1; j>=i+1; j--) {
                if (list.getItem2(j, a) < list.getItem2(j - 1, a)) {
                    list.swapListItem(j, j-1, a);
                }
            }
        }
    }
    void sortH(List& list) {
        const int a = list.count();
        double factor = 1.2473309;
        int stepfactor =  a - 1;
        while (stepfactor >= 1) {
            for (int i = 0; i + stepfactor < a; i++) {
                if (list.getItem2(i, a) > list.getItem2(i+stepfactor, a)) {
                    list.swapListItem(i+stepfactor, i, a);
                }
            }
            stepfactor /= factor;
        }
    }
    void sortS(List& list) {
        const int a = list.count();
        int j = 0;
        int tmp = 0;
        for (int i = 0; i < a; i++) {
            j = i;
            for (int k = i; k < a; k++) {
                if (list.getItem2(j, a) < list.getItem2(k, a)) {
                    j = k;
                }
            }
            list.swapListItem(j, i, a);
        }
    }
};

int main() {
    List list;
    int value, count;
    char x;
    bool y;
    cout << "Vvedite kolichestvo: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Vvedite element: ";
        cin >> value;
        list.add(value);
        cout << endl;
    }
    cout << "Vvedite tip sortirovki: Q-quick; B - Bubble; S - Selection, H - Hairbush: " << endl;
    cin >> x;
    cout << "Vvedite kak nuzhno sortirovat 1 - po vozrastaniu; 0 - po ubivaniu: " << endl;
    cin >> y;
    switch (x) {
        case 'Q':
            list.sortQ(list, 0, list.count() - 1);
            if (y == 1) list.print();
            else list.printReverse();
            break;
        case 'B':
            list.sortB(list);
            if (y == 1) list.print();
            else list.printReverse();
            break;
        case 'S':
            list.sortS(list);
            if (y == 1) list.printReverse();
            else list.print();
            break;
        case 'H':
            list.sortH(list);
            if (y == 1) list.print();
            else list.printReverse();
            break;
    }
    return 0;
}