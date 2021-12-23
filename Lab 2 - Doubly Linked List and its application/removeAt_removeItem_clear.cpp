template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item); 
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
T DLinkedList<T>::removeAt(int index)
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
        this->head->previous = NULL;
    }
    else if (index == this->count - 1) {
        while (temp->next->next != NULL) temp = temp->next;
        dataDel = this->tail->data;
        delete this->tail;
        this->tail = temp;
        temp->next = NULL;
    }
    else {
        for (int i = 0; i < index; i++) temp = temp->next;
        dataDel = temp->data;
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        delete temp;
        temp = NULL;
    }
    --this->count;
    return dataDel;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = this->indexOf(item);
    if (index != -1) {
        this->removeAt(index);
        return true;
    }
    return false;
}

template <class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (this->count != 0) this->removeAt(0);
}
