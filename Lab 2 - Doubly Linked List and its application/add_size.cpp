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
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* pNew = new Node(e);
    if (this->head == NULL) {
        this->head = this->tail = pNew;
    }
    else {
        this->tail->next = pNew;
        pNew->previous = this->tail;
        this->tail = pNew;
    }
    ++this->count;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    if (index > this->count || index < 0) {
		throw ("out of range");
		return;
	}
		
	if (index == this->count && this->count != 0) {
		add(e);
		return;
	}
	
	Node* pNew = new Node(e);
	if (this->count == 0) 
        this->head = this->tail = pNew;
    else if (index == 0) {
        pNew->next = this->head;
        this->head->previous = pNew;
        this->head = pNew;
    }
    else {
        Node* prev = this->head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;
        Node* cur = prev->next;
        pNew->next = prev->next;
        cur->previous = pNew;
        pNew->previous = prev;
        prev->next = pNew;
    }
    ++this->count;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}