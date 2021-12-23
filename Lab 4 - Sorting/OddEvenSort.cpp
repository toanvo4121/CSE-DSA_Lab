#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end)
    {
        /*TODO*/
        int size = end - start;
        bool isSorted = false;
        while (!isSorted) {
            isSorted = true;
        
            for (int i = 0; i <= size - 2; i = i + 2) 
            { 
                if (start[i] > start[i+1]) 
                { 
                    int temp = start[i];
                    start[i] = start[i+1];
                    start[i+1] = temp;
                    isSorted = false; 
                } 
            }
            
            for (int i = 1; i <= size - 2; i = i + 2) 
            { 
                if (start[i] > start[i+1]) 
                { 
                    int temp = start[i];
                    start[i] = start[i+1];
                    start[i+1] = temp;
                    isSorted = false; 
                } 
            }
            
            Sorting<int>::printArray(start, end);
        }
    }
};