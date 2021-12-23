#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN 
    int Height(Node* root) {
        if (root == NULL)
            return 0;
        else
        {
            int l = Height(root->pLeft);
            int r = Height(root->pRight);
            return max(l,r) + 1;
        }
    }

    int getHeight() {
        return Height(root);
    }


    void printInorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printInorder(node->pLeft); 
        cout << node->value << " "; 
        printInorder(node->pRight); 
    } 

    void printPreorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        cout << node->value << " "; 
        printPreorder(node->pLeft);  
        printPreorder(node->pRight); 
    }  

    void printPostorder(Node* node) 
    { 
        if (node == NULL) 
            return; 
        printPostorder(node->pLeft); 
        printPostorder(node->pRight); 
        cout << node->value << " "; 
    } 

    string preOrder() {
        printPreorder(root);
        return "";
    }

    string inOrder() {
        printInorder(root);
        return "";
    }

    string postOrder() {
        printPostorder(root);
        return "";
    }
    // STUDENT ANSWER END
};
