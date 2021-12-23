template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T> *pList, bool begin)
{
	/*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
	this->pList = pList;
	if (begin == true)
	{
		if (this->pList == NULL)
		{
			this->current = NULL;
			this->index = -1;
		}
		else
		{
			this->current = this->pList->head;
			this->index = 0;
		}
	}
	else
	{
		this->current = NULL;
		this->index = (this->pList->count == 0) ? (this->pList->size()) : 0;
	}
}

template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
	/*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
	this->pList = iterator.pList;
	this->current = iterator.current;
	this->index = iterator.index;
	return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
	/*
        Remove a node which is pointed by current
        * After remove, current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	else if (this->current == this->pList->head)
	{
		this->current = NULL;
		this->pList->removeAt(this->index);
		this->index = -1;
	}
	else
	{
		Node *prev = this->pList->head;
		while (prev->next != this->current)
			prev = prev->next;
		this->current = prev;
		this->pList->removeAt(this->index);
		--this->index;
	}
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
	/*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	else
		this->pList->set(this->index, e);
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
	/*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
	if (this->current == NULL)
		throw std::out_of_range("Segmentation fault!");
	return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
	/*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
	return (this->pList != iterator.pList || this->current != iterator.current);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
	/*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
	if (this->current == NULL && this->index == this->pList->size())
		throw std::out_of_range("Segmentation fault!");
	else if (this->current == NULL && this->index == -1)
	{
		this->current = this->pList->head;
		this->index = 0;
	}
	else
	{
		this->current = this->current->next;
		++this->index;
	}
	return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
	/*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator newIterator(this->pList, true);
	if (this->current == NULL && this->index == this->pList->size())
		throw std::out_of_range("Segmentation fault!");
	else
	{
		newIterator.current = this->current;
		newIterator.index = this->index;
		++this->index;
		if (this->current == NULL && this->index == -1)
			this->current = this->pList->head;
		else
			this->current = this->current->next;
	}
	return newIterator;
}