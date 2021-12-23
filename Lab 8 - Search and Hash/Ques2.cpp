int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    int i;
    for (i = 0; i < n; i += step) {
        if (arr[i] <= x) prev = i;
        if (arr[i] == x) {
            cout << i;
            return i;
        }
        cout << i << " ";
        if (arr[i] > x) break;
    }
    if (prev > n - 1) return -1;
    else {
        for (int j = prev; j < i; j++) {
            if (arr[j] == x) {
                cout << j;
                return j;
            }
            if (j != prev) cout << j << " ";
            if (arr[j] > x) break;
        }
    }
    return -1;
}