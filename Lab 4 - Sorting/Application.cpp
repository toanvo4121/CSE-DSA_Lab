#ifndef SORTINGAPPLICATION_H
#define SORTINGAPPLICATION_H
#include <iostream>
#include <string>
using namespace std;
/* Your helping functions go here */
string sortString(string a) {
    int len = a.length();
    for (int i = 0; i < len - 1; ++i) {
        int min = a[i];
        int min_index = i;
        for (int j = i + 1; j < len; ++j) {
            if (a[j] < min)  {
                min = a[j];
                min_index = j;
            }
        }
        int temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
    return a;
}

bool isPermutation(string a, string b) {
    //TODO
    return (sortString(a) == sortString(b));
}
#endif /* SORTINGAPPLICATION_H */