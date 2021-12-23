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
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
void SLinkedList<T>::add(const T& e) {
	/* Insert an element into the end of the list. */
	Node* pNew = new Node(e, NULL);
	if (this->count == 0) {
		this->head = this->tail = pNew;
	}
	else {
		this->tail->next = pNew;
		this->tail = pNew;
	}
	++this->count;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
	/* Insert an element into the list at given index. */
	if (index > this->count || index < 0) {
		throw ("out of range");
		return;
	}
		
	if (index == this->count && this->count != 0) {
		add(e);
		return;
	}

	Node* pNew = new Node(e, NULL);
	if (this->count == 0) {
		this->head = this->tail = pNew;
	}
	else if (index == 0) {
		pNew->next = this->head;
		this->head = pNew;
	}
	else {
		Node* temp = this->head;
		for (int i = 0; i < index - 1; i++) temp = temp->next;
		pNew->next = temp->next;
		temp->next = pNew;
	}
	++this->count;
}

template<class T>
int SLinkedList<T>::size() {
	/* Return the length (size) of list */
	return this->count;
}