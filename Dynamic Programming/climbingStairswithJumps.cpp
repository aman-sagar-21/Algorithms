// In this problem, 

// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step  you could jump to in a single move.  
// 4. You are required to print the count of different paths via which you can climb to the top.

//no. of paths to go from ith to ith is 1
//no. of moves is 0

#include<iostream>
using namespace std;

int main(){

    int n = 5;
    int a[] = {1, 2, 3, 4, 5};

    int *dp = new int[n+1]; //dp[i] = count of paths to reach nth floor from dp[i] where i=0,...,n
    for(int i=0; i<n; i++) dp[i] = 0;
    dp[n] = 1;


    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=a[i] && i+j<n+1; j++){
            // if(i+j<n+1)
                dp[i] += dp[i+j]; 
        }
    }

    cout<<dp[0];
    return 0;
}