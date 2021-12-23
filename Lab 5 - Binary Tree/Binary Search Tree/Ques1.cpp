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
    T minRec(Node* node) {
        if (node->pLeft == NULL) return node->value;
        else return minRec(node->pLeft);
    }

    T maxRec(Node* node) {
        if (node->pRight == NULL) return node->value;
        else return maxRec(node->pRight);
    }

    T getMin() {
        //TODO: return the minimum values of nodes in the tree.
        return minRec(this->root);
    }

    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        return maxRec(this->root);
    }

    // STUDENT ANSWER END
};
