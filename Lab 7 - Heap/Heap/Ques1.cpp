#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
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
        delete[]elements;
    }
    void push(T item);
    void clear();
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};


//Your code goes here
template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (this->count == 0);
}

template<class T>
T Heap<T>::peek(){
    if (this->isEmpty()) return -1;
    return this->elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    if (this->isEmpty()) return false;
    for (int i = 0; i < this->count; ++i) {
        if (this->elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (this->isEmpty()) return false;
    this->elements[0] = this->elements[this->count - 1];
    --this->count;
    this->reheapDown(0);
    return true;
}