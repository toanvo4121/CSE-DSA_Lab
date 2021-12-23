int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right) return -1;
    int mid = (right + left) / 2;
    if (arr[mid] == x){
        cout << "We traverse on index: " << mid << endl;
        return mid;
    }
    else if(arr[mid] < x) {
        cout << "We traverse on index: " << mid << endl;
        left = mid + 1;
    }
    else {
        cout << "We traverse on index: " << mid << endl;
        right = mid -1;
    }
    return binarySearch(arr, left, right, x);
}