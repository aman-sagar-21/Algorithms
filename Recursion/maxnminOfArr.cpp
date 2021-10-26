#include<iostream>
using namespace std;

int maxOfArr(int array[], int n, int idx){

    if(idx == n-1) return array[idx];
    
    int maxOfSmallArr = maxOfArr(array,n, idx+1);
    
    if(maxOfSmallArr>array[idx]){
        return maxOfSmallArr;
    }else
         return array[idx];
}

int maxArr(int arr[], int n){

    if(n==1) return arr[0];

    int max = maxArr(arr, n-1);

    if(max>arr[n-1]) return max;
    return arr[n-1];
    
}

int minArr(int arr[], int n){
    if(n==1) return arr[0];
    int min = minArr(arr, n-1);
    if(min<arr[n-1]) return min;
    else return arr[n-1];
}

int main(){

    int arr[] = {10, 20, 50, 30, 40, 60, 25, 46};
    int index = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = maxArr(arr,n);
    cout<<max;
    int min = minArr(arr, n);
    cout<<endl<<min;

    return 0;
}