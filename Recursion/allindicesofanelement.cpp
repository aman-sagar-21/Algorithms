// Given an array of size n, we need to return all indices of an element x as an array
#include<iostream>
#include<vector>
using namespace std;

// fsf keeps track of number of times the element is found so far
// int * allindices(int arr[], int n, int x, int fsf){

//     if(n==0){
//         int *indexes = new int [fsf];
//         return indexes;
//     }

//     if(arr[n-1]==x) {
//         int *indexes = allindices(arr, n-1, x, fsf+1);
//         indexes[fsf] = n-1;
//         return indexes;
//     }else{
//         int *indexes = allindices(arr, n-1, x, fsf);
//         return indexes;
//     }
    
// }
// The above didn't work out for me\
using vector instead

vector<int> allindices(int arr[], int n, int x){
    if(n==0){
        vector<int> v;
        return v;
    }

    vector<int>v = allindices(arr, n-1, x);
    if(arr[n-1]==x) v.push_back(n-1);

    return v;

}

int main(){

    int arr[] = {8, 2, 3, 4, 5, 6, 4, 8, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v = allindices(arr, n, 8);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}