#include <iostream>
#include <string>
using namespace std;
template <class T>
struct Node {
    T field;
    Node<T>* pLeft = nullptr;
    Node<T>* pRight = nullptr;
    Node<T>* parent = nullptr;
    bool checked = false;

    Node(Node<T>* par, T value) {
        this->field = value;
        this->pLeft = nullptr;
        this->pRight = nullptr;
        this->parent = par;
        this->checked = false;
    }

    bool isLeaf() {
        if (!pLeft && !pRight) return true;
        else return false;
    }
};

template <class T>
struct Tree {
    Node<T>* root = nullptr;
    void Add(Node<T>* currentnode, T value) {
        if (value >= currentnode->field) {
            if (!currentnode->pRight)
                currentnode->pRight = new Node<T>(currentnode, value);
            else Add(currentnode->pRight, value);
        }
        else {
            if (!currentnode->pLeft) {
                currentnode->pLeft = new Node<T>(currentnode, value);
            }
            else Add(currentnode->pLeft, value);
        }
    }
    void addnode(T value) {
        if (root == NULL) root = new Node<T>(nullptr, value);
        else {
            Add(root, value);
        }
    }
    void treeprint(Node<T>* current) {
        if (current != nullptr) {
            if (current->pLeft) treeprint(current->pLeft);
            cout << current->field << " ";
            if (current->pRight) treeprint(current->pRight);
        }
    }
    struct Iterator {
        Tree<T>* collection = nullptr;
        Node<T>* current = nullptr;
        bool started = false;

        Iterator(Tree<T>* col) {
            this->collection = col;
            this->current = col->root;
        }

        bool HasMore(Iterator* it) {
            bool hasElements = it->collection != NULL;
            bool started = it->current != NULL;

            if (!hasElements) {
                return false;
            }
            else {
                if (!started) return true;
                else return (Last(it->current, it));
            }
        }
        bool Last(Node<T>* it, Iterator* tree) {
            Node<T>* current = it;
            if (it == tree->collection->root) return true;
            do {
                if (current->isLeaf()) {
                    current = current->parent;
                }
                else {
                    if((current->parent->pLeft && current->parent->pLeft->checked == true) || (current->parent->pRight && current->parent->pRight->checked == true)) current = current->parent;
                    else return true;
                }
            } while (current != tree->collection->root);
            return false;
        }
        Node<T>* getMin(Node<T>* it) {
            if (!it->pLeft) return it;
            return getMin(it->pLeft);
        }
        const Node<T>* MoveNext(Iterator* it) {
            if (!it->started) it->started = true;
            if (!it->current) {
                it->current = it->getMin(it->current);
                it->current->checked = true;
                return it->current;
            }
            if (it->current->isLeaf() && it->current->parent && it->current->parent->pLeft == it->current) {
                it->current = it->current->parent;
                it->current->checked = true;
                return it->current;
            }
            else {
                if (!it->current->isLeaf()) {
                    if (it->current->pRight) {
                        if (!it->current->pRight->isLeaf()) {
                            it->current = it->getMin(it->current->pRight);
                            it->current->checked = true;
                            return it->current;
                        }
                        else {
                            it->current = it->current->pRight;
                            it->current->checked = true;
                            return it->current->pRight;
                        }
                    }
                    else {
                        it->current = it->current->parent;
                        it->current->checked = true;
                        return it->current;
                    }
                }
                if (!it->current->parent) {
                    if (it->current->pRight) {
                        if (!it->current->pRight->isLeaf()) {
                            it->current = it->getMin(it->current->pRight);
                            it->current->checked = true;
                            return it->current;
                        }
                        else {
                            it->current = it->current->pRight;
                            it->current->checked = true;
                            return it->current->pRight;
                        }
                    }
                    else {
                        return nullptr;
                    }
                }
                if (it->current->parent->pLeft != it->current) {
                    it->current = it->current->parent->parent;
                    it->current->checked = true;
                    return it->current;
                }
            }
            return nullptr;
        }
    };
    Iterator* getIterator() {
        return new Iterator(this);
    }
};
int main() {
    int count = 0;
    Tree<string> tree;
    tree.addnode("Assembler");
    tree.addnode("Kotlin");
    tree.addnode("C++");
    tree.addnode("Basic");
    tree.addnode("Haskell");
    tree.addnode("Ruby");
    tree.addnode("PHP");
    tree.treeprint(tree.root);
    Tree<string>::Iterator* it = tree.getIterator();
    while (it->HasMore(it)) {
        cout << it->current->field << " ";
        it->MoveNext(it);
        count++;
        cout << count << " ";
    }
    cout << count;
    return 0;
}