template
class Heap{
protected:
    T *elements;
    int capacity;
    int count;
    
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete []elements;
    }
    void push(T item);
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    
private:
    void ensureCapacity(int minCapacity); 
    void reheapUp(int position);
};

// Your code here
template<class T>
void Heap<T>::push(T item){
    if (this->count == this->capacity) this->ensureCapacity(this->capacity * 2);
    this->elements[count] = item;
    ++this->count;
    this->reheapUp(this->count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* newElements = new T[minCapacity];
    for (int i = 0; i < this->count; ++i) {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->capacity = minCapacity;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position <= 0 || position >= this->count) return;
    int parent = (position - 1) / 2;
    if (this->elements[parent] < this->elements[position]) {
        int temp = this->elements[parent];
        this->elements[parent] = this->elements[position];
        this->elements[position] = temp;
        reheapUp(parent);
    }
    return;
}