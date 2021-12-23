#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    bool findRec(Node* node, T i) {
        if (node == NULL) return false;
        else if (node->value == i) return true;
        else if (node->value > i) return findRec(node->pLeft, i);
        else return findRec(node->pRight, i);
    }

    T sumRec(Node* node, T l, T r) {
        if (node == NULL) return 0;
        else if (node->value < l) return sumRec(node->pRight, l, r);
        else if (node->value > r) return sumRec(node->pLeft, l, r);
        else return node->value + sumRec(node->pLeft, l, r) + sumRec(node->pRight, l, r);
    }

    bool find(T i) {
        // TODO: return true if value i is in the tree; otherwise, return false.
        return findRec(this->root, i);
    }

    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return this->sumRec(this->root, l, r);
    }

    // STUDENT ANSWER END
};