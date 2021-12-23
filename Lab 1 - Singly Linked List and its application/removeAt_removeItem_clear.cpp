template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
    T       removeAt(int index);
    bool    removeItem(const T &removeItem);
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

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= this->count)
        throw std::out_of_range("The index is out of range!");
    T dataDel;
    Node* temp = this->head;
    if (this->count == 1) {
        dataDel = this->head->data;
        delete this->head;
        this->head = this->tail = NULL;
    }
    else if (index == 0) {
        dataDel = temp->data;
        this->head = temp->next;
        delete temp;
        temp = this->head;
    }
    else if (index == this->count - 1) {
        while (temp->next->next != NULL) temp = temp->next;
        dataDel = this->tail->data;
        delete this->tail;
        this->tail = temp;
        temp->next = NULL;
    }
    else {
        Node* prev = this->head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;
        temp = prev->next;
        dataDel = temp->data;
        prev->next = temp->next;
        delete temp;
        temp = NULL;
    }
    --this->count;
    return dataDel;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = indexOf(item);
    if (index != -1) {
        this->removeAt(index);
        return true;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->count != 0) removeAt(0);
}