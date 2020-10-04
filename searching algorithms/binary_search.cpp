#include <iostream>

using namespace std;

int binarysearch(int arr[],int n){
    int left = 0;
    int right = 9;
    int mid;
    while (left<=right)
    {
        mid = left+right/2;
        if(n == arr[mid]) return mid;
        else if(n > arr[mid]) left = mid+1;
        else
        {
            right = mid-1;
        }
    }

    return -1;
    
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,11};
    int n;
    cout<<"Please enter the element you want to search:";
    cin>>n;
    
    int result = binarysearch(arr,n);

    if(result == -1){
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at pos "<<result + 1;
    }

    return 0;
    
}