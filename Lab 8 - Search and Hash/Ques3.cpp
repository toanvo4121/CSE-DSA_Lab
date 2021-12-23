int interpolationSearch(int arr[], int left, int right, int x)
{
    if (left > right || arr[left] > x || arr[right] < x) return -1;
    int mid= left + ((x-arr[left])*(right-left))/(arr[right] - arr[left]);
    if (mid<left) return -1;
    if (mid>right) return -1;
    
        if(arr[mid] == x){
            cout<<"We traverse on index: "<<mid <<endl;
            return  mid ;
        }
        else if(arr[mid] < x) {
            cout<<"We traverse on index: "<<mid <<endl;
            left=mid + 1  ;
        }
        else {
            cout<<"We traverse on index: "<<mid <<endl;
            right=mid-1 ;
        }
        return interpolationSearch(arr, left, right, x);
}