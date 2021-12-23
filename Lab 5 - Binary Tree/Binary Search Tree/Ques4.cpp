#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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
        int l = (int)posFromRoot.length();
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

    //Helping functions
    //Helping functions
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
    int getDiaRec(Node* root) {
        if (root == NULL) return 0;
        else {
            int left_Height = Height(root->pLeft);
            int right_Height = Height(root->pRight);
            int left_Dia = getDiaRec(root->pLeft);
            int right_Dia = getDiaRec(root->pRight);
            
            return max(left_Height + right_Height + 1, max(left_Dia, right_Dia));
        }
    }

    int getDiameter(){
        //TODO
        return this->getDiaRec(this->root);
    }
};