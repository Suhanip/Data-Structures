#include <iostream>

using namespace std;

void linear_search(int arr[],int ele){
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if(ele == arr[i]){
            flag = 1;
            cout<<"Element found at position "<<i+1;
        }
    }
    if(flag == 0){
        cout<<"Element not found";
    }
}

 int main(){
     int n;
     int arr[5] = {1,5,2,7,88};
     cout<<"Please the element you want to search:";
     cin>>n;

    linear_search(arr,n);
 }