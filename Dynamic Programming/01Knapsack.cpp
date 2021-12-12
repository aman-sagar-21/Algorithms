/*
We are given a knapsack of a given capacity. We are given some objects with certain weight and a certain profit. We need to maximize the 
profit and the total weight of the selected items cannot exceed the capacity of the knapsack. As the name suggest, we either have to take \
the whole object or not take it at all. We cannot take an object partially in the knapsack.

for eg., 
weights = [2, 3, 4, 5]
profits = [1, 2, 5, 6]

output: 8, we can take items with weight 5 and 3 to get maximum possible profit 8

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> w;
    vector<int> v;
    
    for(int i=0; i<n; i++){
        int x; cin>>x;
        w.push_back(x);
    }
    
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }

    int capacity; cin>>capacity;

    vector<vector<int>> dp(n+1, vector<int>(capacity+1));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(w[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+v[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][capacity];

    return 0;

}