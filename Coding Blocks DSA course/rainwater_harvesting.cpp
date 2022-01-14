//Given an array having the heights of adjacent bars
//You need to find the max amount of water that can be collected between them

#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;

    int a[n]; //height of bars
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    //dynamic programming
    //pre-computing highest bar to the left and right of the ith bar

    int l[n];
    int r[n];

    l[0] = a[0];
    r[n-1] = a[n-1];

    for(int i=1; i<n; i++){
        l[i] = max(l[i-1],a[i]);
    }

    for(int i=n-2; i>=0; i--){
        r[i] = max(r[i+1],a[i]);
    }

    int water = 0;
    for(int i=0; i<n; i++){
        water += min(r[i], l[i]) - a[i];
    }

    cout<<water;

    return 0;

}