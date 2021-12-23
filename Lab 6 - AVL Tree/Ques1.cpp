#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    int getBalance(Node* N)
    {
        if (N == NULL)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }
    Node* insert(Node* node, T key)
    {
        if (node == NULL)
            return(new Node(key));

        if (key < node->data)
            node->pLeft = insert(node->pLeft, key);
        else if (key >= node->data)
            node->pRight = insert(node->pRight, key);
        
        int balance = getBalance(node);
        // Left Left Case  
        if (balance > 1 && key < node->pLeft->data)
            return rightRotate(node);

        // Right Right Case  
        if (balance < -1 && key >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && key >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && key < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;
    }
    void insert(const T& value)
    {
        // TODO
        this->root = insert(this->root, value);
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