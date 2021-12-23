#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}

    void printInorderRec(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printInorderRec(node->pLeft); 
        cout << node->data << " "; 
        printInorderRec(node->pRight); 
    } 

    bool findRec(Node* node, T i) {
        if (node == NULL) return false;
        else if (node->data == i) return true;
        else if (node->data > i) return findRec(node->pLeft, i);
        else return findRec(node->pRight, i);
    }

    void clear() {};

    void printInorder() {
        // TODO
        this->printInorderRec(this->root);
    }

    bool search(T value) {
        // TODO
        return this->findRec(this->root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};