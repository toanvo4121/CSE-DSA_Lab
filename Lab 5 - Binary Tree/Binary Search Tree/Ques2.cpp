#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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

    //Helping function
    Node* addRec(Node* node, T value) {
        //TODO
        if (node == NULL) { 
            Node* temp; 
            temp = (Node*)malloc(sizeof(Node)); 
            temp->value = value; 
            temp->pLeft = NULL; 
            temp->pRight = NULL;
            return temp;
        } 
        if (value <= node->value) { 
            node->pLeft = addRec(node->pLeft, value); 
        } 
        else {
            node->pRight = addRec(node->pRight, value); 
        }
        return node;
    }
    Node* del(Node* node, T value) {
        Node* curr = this->root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->value != value) { 
            prev = curr; 
            if (value < curr->value) 
                curr = curr->pLeft; 
            else
                curr = curr->pRight; 
        } 

        if (curr == NULL) { 
            return node; 
        } 

        if (curr->pLeft == NULL || curr->pRight == NULL) { 
            Node* newCurr; 
            if (curr->pLeft == NULL) 
                newCurr = curr->pRight; 
            else
                newCurr = curr->pLeft; 

            if (prev == NULL) 
                return node; 
            if (curr == prev->pLeft) 
                prev->pLeft = newCurr; 
            else
                prev->pRight = newCurr; 
            free(curr); 
        } 
        else { 
            Node* p = NULL; 
            Node* temp; 

            temp = curr->pRight; 
            while (temp->pLeft != NULL) { 
                p = temp; 
                temp = temp->pLeft; 
            } 
            if (p != NULL) 
                p->pLeft = temp->pRight; 
            else
                curr->pRight = temp->pRight; 

            curr->value = temp->value; 
            free(temp); 
        } 
        return node;
    }

    void add(T value){
        //TODO
        this->root = this->addRec(this->root, value);
    }
    
    void deleteNode(T value){
        //TODO
        this->root = this->del(this->root, value);
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
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
};
