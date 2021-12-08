/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the amount "amt" can be paid.
Note1 - You have an infinite supply of each coin denomination i.e. same coin denomination can be used for many installments in payment of "amt"
Note2 - You are required to find the count of combinations and not permutations i.e.
2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same combination. You should treat them as 1 and not 3.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    
    int target; cin>>target;

    vector<int> dp(target+1);
    dp[0] = 1; //there is always one combination for adding upto 0 i.e. use nothing

    for(int i=0; i<n; i++){
        //starting from coins[i] because if start j from 0, and if j<coins[i] then dp[j-coins[i]] will be a negative address and it will give us a segmentation fault
        for(int j=coins[i]; j<=target; j++){ 

            dp[j] += dp[j-coins[i]];

        }
    }
    
    cout<<dp[target];

    return 0;
}