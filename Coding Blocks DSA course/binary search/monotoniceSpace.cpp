// BINARY SEARCH ON MONOTONIC SEARCH SPACE
// Find the floor of square root of a number using Binary Search

#include<iostream>
using namespace std;

int root(int n){

    int l = 0;
    int r = n;

    int ans;

    while(l<=r){
        int mid = l + (r-l)/2;
        int square = mid*mid;
        if(square<=n){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    // cout<<ans;
    return ans;

}


int main(){
    int n = 50;
    cout<<root(n)<<endl;

    return 0;
}