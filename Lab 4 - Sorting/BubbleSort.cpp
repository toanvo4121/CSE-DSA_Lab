#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort()
    {
        if (this->count == 0 || this->count == 1) return;
        Node* unsorted = this->head;
        Node* sorted = this->tail->next;
        Node* sentinel = sorted;
        bool isSwapped = true;
        
        while (isSwapped) {
            sentinel = sorted;
            isSwapped = false;
            unsorted = this->head;
            while (unsorted->next != sorted) {
                if (unsorted->data > unsorted->next->data) {
                    T temp = unsorted->data;
                    unsorted->data = unsorted->next->data;
                    unsorted->next->data = temp;
                    isSwapped = true;
                }
                unsorted = unsorted->next;
            }
            
            sorted = this->head;
            while (sorted->next != sentinel) sorted = sorted->next;
            if (isSwapped) this->printList();
        }
    }
};