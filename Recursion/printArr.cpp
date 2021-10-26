#include<iostream>
using namespace std;

void printArray(int arr[], int idx){
    if(!arr[idx]) return;
    cout<<arr[idx]<<endl;
    printArray(arr, idx+1);
}

void printArrRev(int arr[], int idx){
    if(!arr[idx]) return;
    printArrRev(arr, idx+1);
    cout<<arr[idx]<<endl;
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int index = 0;

    printArray(arr, index);
    cout<<"in rev"<<endl;
    printArrRev(arr, index);
}