/*
UNBOUNDED KNAPSACK
This is similar to knapsack but here we have unlimited supply of every item and we can use them any number of times
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

    int capacity;
    cin>>capacity;

    vector<int> dp(capacity+1);

    for(int i=1; i<=capacity; i++){
        int max = 0;
        for(int j=0; j<n; j++){


            // if(w[j]<=i){
            //     if( dp[i - w[j] ] + v[j] > max) max = dp[i - w[j] ] + v[j];
            // }

            if(w[j]<=i){
                int rcap = i-w[j];
                int rval = dp[rcap];
                int val = rval + v[j];

                if(val>max) max = val;

            }
        }

        dp[i] = max;
    }

    cout<<dp[capacity];

    return 0;
}