#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        int left_size = middle - left + 1;
        int right_size = right - middle;
            
        int leftArr[left_size], rightArr[right_size];
        for (int i = 0; i < left_size; ++i) 
            leftArr[i] = left[i];
        for (int j = 0; j < right_size; ++j) 
            rightArr[j] = middle[j + 1];
                
        int leftIdx = 0;
        int rightIdx = 0;
        int mergedArrIdx = 0;
            
        while (leftIdx < left_size && rightIdx < right_size) {
            if (leftArr[leftIdx] <= rightArr[rightIdx]) {
                left[mergedArrIdx] = leftArr[leftIdx];
                ++leftIdx;
            }
            else {
                left[mergedArrIdx] = rightArr[rightIdx];
                ++rightIdx;
            }
            ++mergedArrIdx;
        }
            
        while (leftIdx < left_size) 
        {
            left[mergedArrIdx] = leftArr[leftIdx];
            ++leftIdx;
            ++mergedArrIdx;
        }
        while (rightIdx < right_size) {
            left[mergedArrIdx] = rightArr[rightIdx];
            ++rightIdx;
            ++mergedArrIdx;
        }
        
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
        /*TODO*/
        if (start < end) {
            T* mid = start + (end - start) / 2;
            mergeSort(start, mid);
            mergeSort(mid + 1, end);
            merge(start, mid, end);
        }
    }
};
#endif /* SORTING_H */