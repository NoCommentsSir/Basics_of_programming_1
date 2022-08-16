#include <iostream>
#include <string>
using namespace std;
bool String(string str1, string str2) {
    int max = 0;
    int count = 1;
    if (str1.length() > str2.length()) max = str1.length();
    else max = str2.length();
    for (int i = 1; i <= max; i++) {
        if (str1[i] == str2[i] && str1[i - 1] == str2[i - 1]) {
            count++;
        }
    }
    if (count >= 3)return true;
    return false;
}
struct Card {
    long long number;
    string initials;
    string email;
    Card* parent = nullptr;
    Card* leftChild = nullptr;
    Card* rightChild = nullptr;
    bool isRed = false;

    Card(bool isRed, long long num, string init, string em) {
        this->number = num;
        this->initials = init;
        this->email = em;
        this->isRed = isRed;
    }
    Card(Card* parent) {
        this->number = 0;
        this->parent = parent;
    }
};
class RedBlackTree {
    friend class Direct;
public:
    Card* root = nullptr;

    void add(long long num, string init, string em) {
        if (!root) {
            root = new Card(false, num, init, em);
            root->leftChild = new Card(root);
            root->rightChild = new Card(root);
            return;
        }
        Card* card = root;
        Card* newCard = new Card(true, num, init, em);
        newCard->leftChild = new Card(newCard);
        newCard->rightChild = new Card(newCard);
        while (card->leftChild != nullptr && card->rightChild != nullptr) {
            if (card->number > num)
                card = card->leftChild;
            else
                card = card->rightChild;
        }
        newCard->parent = card->parent;
        if (card == card->parent->rightChild)
            card->parent->rightChild = newCard;
        else
            card->parent->leftChild = newCard;
        balanceInsertion(newCard);
    }

    void remove(long long num) {
        Card* card = root;
        Card* balanceCard;
        while (card->number != num) {
            if (card->number < num)
                card = card->rightChild;
            else
                card = card->leftChild;
        }

        bool cardOriginalIsRed = card->isRed;

        if (!card->rightChild->rightChild && !card->leftChild->leftChild) {
            if (card == root) {
                root = nullptr;
                return;
            }
            else {
                if (card == card->parent->leftChild)
                    card->parent->leftChild = new Card(card->parent);
                else
                    card->parent->rightChild = new Card(card->parent);
                return;
            }
        }

        if (card->rightChild->rightChild && !card->leftChild->leftChild) {
            balanceCard = card->rightChild;
            replaceCard(card, card->rightChild);
        }
        else if (!card->rightChild->rightChild && card->leftChild->leftChild) {
            balanceCard = card->leftChild;
            replaceCard(card, card->leftChild);
        }
        else {
            Card* nextCard = card->rightChild;
            while (nextCard->leftChild->leftChild)
                nextCard = nextCard->leftChild;
            balanceCard = nextCard->rightChild;
            cardOriginalIsRed = nextCard->isRed;
            if (nextCard->parent == card) {
                balanceCard->parent = nextCard;
            }
            else {
                replaceCard(nextCard, nextCard->rightChild);
                nextCard->rightChild = card->rightChild;
                nextCard->rightChild->parent = nextCard;
            }
            replaceCard(card, nextCard);
            nextCard->leftChild = card->leftChild;
            nextCard->leftChild->parent = nextCard;
            nextCard->isRed = card->isRed;
        }
        if (!cardOriginalIsRed) {
            balanceRemoving(balanceCard);
        }
    }
public:
    void print(Card* card, int blackHeight) {
        if (!card || !card->leftChild && !card->rightChild)
            return;
        int blackHeightAddition = 0;
        if (card->isRed == false)
            blackHeightAddition = 1;
        print(card->leftChild, blackHeight + blackHeightAddition);
        cout << "Mr/ms " << card->initials << ": phone - +"
            << card->number << ", email - " << card->email << "." << endl;
        print(card->rightChild, blackHeight + blackHeightAddition);
    }

private:
    void balanceInsertion(Card* card) {
        if (card == this->root) {
            card->isRed = false;
            return;
        }

        while (card->parent && card->parent->isRed) {
            Card* uncle = getUncle(card);
            Card* grandFather = getGrandFather(card);
            if (isFatherLeftChild(card)) {
                if (uncle->isRed) {
                    card->parent->isRed = false;
                    uncle->isRed = false;
                    grandFather->isRed = true;
                    card = grandFather;
                }
                else {
                    if (card == card->parent->rightChild) {
                        card = card->parent;
                        leftRotate(card->parent);
                    }
                    card->parent->isRed = false;
                    grandFather->isRed = true;
                    rightRotate(grandFather);
                }
            }
            else {
                if (uncle->isRed == true) {
                    card->parent->isRed = false;
                    uncle->isRed = false;
                    grandFather->isRed = true;
                    card = grandFather;
                }
                else {
                    if (card == card->parent->leftChild) {
                        card = card->parent;
                        rightRotate(card);
                    }
                    card->parent->isRed = false;
                    grandFather->isRed = true;
                    leftRotate(grandFather);
                }
            }
        }
        root->isRed = false;
    }

    void balanceRemoving(Card* card) {
        while (card->isRed == false && card != root) {
            if (card == card->parent->leftChild) {
                Card* brother = card->parent->rightChild;
                if (brother->isRed) {
                    brother->isRed = false;
                    card->parent->isRed = true;
                    leftRotate(card->parent);
                    brother = card->parent->rightChild;
                }
                if (brother->leftChild->isRed == false && brother->rightChild->isRed == false) {
                    brother->isRed = true;
                    card = card->parent;
                }
                else {
                    if (brother->rightChild->isRed == false) {
                        brother->leftChild->isRed = false;
                        brother->isRed = true;
                        rightRotate(brother);
                        brother = card->parent->rightChild;
                    }
                    brother->isRed = card->parent->isRed;
                    card->parent->isRed = false;
                    brother->rightChild->isRed = false;
                    leftRotate(card->parent);
                    card = root;
                }
            }
            else {
                Card* brother = card->parent->leftChild;
                if (brother->isRed) {
                    brother->isRed = false;
                    card->parent->isRed = true;
                    rightRotate(card->parent);
                    brother = card->parent->leftChild;
                }
                if (brother->leftChild->isRed == false && brother->rightChild->isRed == false) {
                    brother->isRed = true;
                    card = card->parent;
                }
                else {
                    if (brother->leftChild->isRed == false) {
                        brother->rightChild->isRed = false;
                        brother->isRed = true;
                        leftRotate(brother);
                        brother = card->parent->leftChild;
                    }
                    brother->isRed = card->parent->isRed;
                    card->parent->isRed = false;
                    brother->leftChild->isRed = false;
                    rightRotate(card->parent);
                    card = root;
                }
            }
        }
        root->isRed = false;
    }

    Card* getUncle(Card* card) {
        if (isFatherLeftChild(card))
            return card->parent->parent->rightChild;
        return card->parent->parent->leftChild;
    }

    Card* getGrandFather(Card* card) {
        return card->parent->parent;
    }

    bool isFatherLeftChild(Card* card) {
        return card->parent == card->parent->parent->leftChild;
    }

    void leftRotate(Card* card) {
        Card* pivot = card->rightChild;
        pivot->parent = card->parent;
        if (card->parent) {
            if (card == card->parent->leftChild)
                card->parent->leftChild = pivot;
            else
                card->parent->rightChild = pivot;
        }
        else {
            root = pivot;
        }

        if (pivot->leftChild)
            pivot->leftChild->parent = card;
        card->parent = pivot;
        card->rightChild = pivot->leftChild;
        pivot->leftChild = card;
    }

    void rightRotate(Card* card) {
        Card* pivot = card->leftChild;
        pivot->parent = card->parent;
        if (card->parent) {
            if (card == card->parent->leftChild)
                card->parent->leftChild = pivot;
            else
                card->parent->rightChild = pivot;
        }
        else {
            root = pivot;
        }
        if (pivot->rightChild)
            pivot->rightChild->parent = card;
        card->parent = pivot;
        card->leftChild = pivot->rightChild;
        pivot->rightChild = card;
    }

    void replaceCard(Card* firstCard, Card* secondCard) {
        if (firstCard->parent == nullptr) {
            root = secondCard;
        }
        else if (firstCard == firstCard->parent->leftChild) {
            firstCard->parent->leftChild = secondCard;
        }
        else {
            firstCard->parent->rightChild = secondCard;
        }
        secondCard->parent = firstCard->parent;
    }

};
class Direct {
private:
    void ToLookForNumber(long long num, Card* card, int blackHeight) {
        if (!card || !card->leftChild && !card->rightChild)
            return;
        int blackHeightAddition = 0;
        if (card->isRed == false)
            blackHeightAddition = 1;
        ToLookForNumber(num, card->leftChild, blackHeight + blackHeightAddition);
        if (card->number == num) {
            cout << "Mr/ms " << card->initials << ": phone - +"
                << card->number << ", email - " << card->email << "." << endl;
        }
        ToLookForNumber(num, card->rightChild, blackHeight + blackHeightAddition);
    }
    void ToLookForInitials(string init, Card* card, int blackHeight) {
        if (!card || !card->leftChild && !card->rightChild)
            return;
        int blackHeightAddition = 0;
        if (card->isRed == false)
            blackHeightAddition = 1;
        ToLookForInitials(init, card->leftChild, blackHeight + blackHeightAddition);
        if (String(init, card->initials) && card->number != 0) {
            cout << "Mr/ms " << card->initials << ": phone - +"
                << card->number << ", email - " << card->email << "." << endl;
        }
        ToLookForInitials(init, card->rightChild, blackHeight + blackHeightAddition);
    }
    void AddContact() {
        long long num; string init, em;
        cout << "Enter new options" << endl;
        cin >> num >> init >> em;
        database->add(num, init, em);
        cout << "Successfully!" << endl;
    }
    void EditContact() {
        long long number; string init, email;
        cout << "Enter the telephone number what you want to edit" << endl;
        cin >> number;
        database->remove(number);
        cout << "Enter new options" << endl;
        cin >> number >> init >> email;
        database->add(number, init, email);
        cout << "Successfully!" << endl;
    }
    void OpenDatabase() {
        database->print(database->root, 0);
    }
    void RemoveContact() {
        long long num;
        cout << "Enter the telephone number what you want to edit" << endl;
        cin >> num;
        database->remove(num);
        cout << "Successfully!" << endl;
    }
public:
    void ToLookFor() {
        int x;
        cout << "How do you want to search?" << endl;
        cout << "Enter 1 if you want to search by number" << endl;
        cout << "Enter 2 if you want to search by initials" << endl;
        cin>>x;
        if (x == 1) {
            long long num;
            cout << "Enter the telephone number" << endl;
            cin >> num;
            ToLookForNumber(num, database->root, 0);
        }
        if (x == 2) {
            string init;
            cout << "Enter initials" << endl;
            cin >> init;
            ToLookForInitials(init, database->root, 0);
        }
        if (x != 1 && x != 2) {
            cout << "I'm sorry. There are not such options" << endl;
            return;
        }
    }
public:
    RedBlackTree* database;
    void WorkFunc() {
        int x;
        while (true) {
            cout << "Hello, how can I help you?" << endl;
            cout << "====================================================" << endl;
            cout << "Please, enter: \n1 - if you want to open the database;" << endl;
            cout << "2 - if you want to add the contact; " << endl;
            cout << "3 - if you want to edit the contact; " << endl;
            cout << "4 - if you want to remove the contact; " << endl;
            cout << "5 - if you want to search the contact; " << endl;
            cout << "6 - if you want to close the programm" << endl;
            cout << "====================================================" << endl;
            cin >> x;
            switch (x) {
            case 1:
                OpenDatabase();
                break;
            case 2:
                AddContact();
                break;
            case 3:
                EditContact();
                break;
            case 4:
                RemoveContact();
                break;
            case 5:
                ToLookFor();
                break;
            case 6:
                return;
            default:
                cout << "I'm sorry. There are not such options" << endl;
                break;
            }
        }
    }
};

int main() {
    RedBlackTree tree;
    Direct direct;
    direct.database = &tree;
    direct.database->add(79546789324, "Zubenko Mihail Petrovich", "privet@poka.chto");
    direct.database->add(78005553535, "Malahov Andrei batkovich", "hello@goodbye.cto");
    direct.database->add(77777777777, "Vakulenko Artemii Petrovich", "nihao@neznau.da");
    direct.database->add(70741852963, "Mama Mishi Gavrilkina", "bred@spat.pora");
    direct.database->add(71233211233, "Nezachetov Peresdacha Commisievich", "uze@ne.smeshno");
    direct.WorkFunc();
    return 0;
}