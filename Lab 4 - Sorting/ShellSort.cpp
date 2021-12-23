#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        // TODO
        int size = end - start;
        int key, j;
        for (int i = 1; i * cur_segment_total + segment_idx < size; ++i) {
            key = start[i * cur_segment_total + segment_idx];
            j = i - 1;
                
            while (j >= 0 && start[j * cur_segment_total + segment_idx] > key) 
            {  
                start[(j + 1) * cur_segment_total + segment_idx] = start[j * cur_segment_total + segment_idx];  
                j = j - 1;  
            }  
            start[(j + 1) * cur_segment_total + segment_idx] = key;
        }
    }

public:
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
        // TODO
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        for (int i = num_phases - 1; i >= 0; --i) {
            for (int segment = 0; segment < num_segment_list[i]; ++segment) {
                sortSegment(start, end, segment, num_segment_list[i]);
            } 
            cout << num_segment_list[i] << " segments: ";
            printArray(start, end);
        }
    }
};

#endif /* SORTING_H */