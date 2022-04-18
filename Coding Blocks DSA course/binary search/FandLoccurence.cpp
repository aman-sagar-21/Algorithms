// Find first and last occurence of given element in the array using binary search
#include<iostream>
using namespace std;

int first_occurence(int a[], int key, int n){

    int l = 0;
    int r = n-1;

    int ans = -1;

    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==key){
            ans = mid;
            r = mid+1;
        }else if(a[mid]<key){
            l = mid+1;
        }else{
            r = mid=1;
        }
    }

    return ans;

}

int main(){
    int arr[] = {1, 2, 5, 8, 8, 8, 8, 8, 10, 12, 15, 20}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<first_occurence(arr, 8, n);

    return 0;
}