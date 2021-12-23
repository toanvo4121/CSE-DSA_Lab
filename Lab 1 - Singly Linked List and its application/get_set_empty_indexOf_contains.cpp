template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0);
    ~SLinkedList() { };
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
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
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index > this->count) {
        throw std::out_of_range("The index is out of range!");
    } 
    if (this->empty()) throw("List is empty");
    else {
    Node* temp = this->head;
    for (int i = 0; i < index
    ; i++) temp = temp->next;
    return temp->data;
    }
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    if (index < 0 || index > this->count) {
        throw std::out_of_range("The index is out of range!");
        return;
    }
    if (this->empty()) throw("List is empty");
    else {
    /* Assign new value for element at given index in the list */
    Node* temp = this->head;
    for (int i = 0; i < index; i++) temp = temp->next;
    temp->data = e;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (this->count == 0);
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (!this->empty()) {
        int index = 0;
        Node* temp = this->head;
        for (int i = 0; i < this->count; i++) {
            if (temp->data == item) {
                index = i;
                break;
            }
            else 
                temp = temp->next;
        }
        if (temp != NULL) return index;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return (this->indexOf(item) != -1);
}