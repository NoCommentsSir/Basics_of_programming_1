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
            return (fetchNext() != nullptr);
        }
        Node<T>* getNextParent(Node<T>* currentNode) {
            Node<T>* parent = currentNode->parent;
            if (parent) {
                // going up from Left
                if (parent->pLeft == currentNode) {
                    return parent;
                }
                else { // we're in the right subtree
                    return getNextParent(parent);
                }
            }
            else // nullptr
                return parent;
        }
        Node<T>* fetchNext() {
            Node<T>* next = nullptr;

            // current == 0
            if (this->current == nullptr) {
                next = getMin(this->collection->root);
                return next;
            }

            if (this->current->isLeaf())
            {
                next = getNextParent(this->current);
                return next;
            } 
            else { // not leaf
                if (this->current->pRight) {
                    next = getMin(this->current->pRight);
                    return next;
                }
                else {
                    next = getNextParent(this->current);
                    return next;
                }
            }
        }

        Node<T>* getMin(Node<T>* it) {
            if (!it->pLeft) return it;
            return getMin(it->pLeft);
        }
        
        void MoveNext() {
            this->current = fetchNext();
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
    tree.addnode("qolang");
    tree.treeprint(tree.root);
    Tree<string>::Iterator* it = tree.getIterator();
    while (it->HasMore(it)) {
        cout << it->current->field << " ";
        it->MoveNext();
        count++;
        cout << count << " ";
    }
    cout << count;
    return 0;
}