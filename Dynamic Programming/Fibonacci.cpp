#include<bits/stdc++.h>
using namespace std;

//simple recursion
int fib_r (int n){
    if(n==0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;
    return fib_r(n-1) + fib_r(n-2);
}

//memoization
int dp[100000];
int fib_m(int n){
    if(n==0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;

    if(dp[n]) return dp[n];
    else dp[n] = fib_m(n-1) + fib_m(n-2);

    return dp[n];
    
}

//tabulation
int fib_t(int n){
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 0;
    fib[2] = 1;
    for(int i=3; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main(){
    int rec = fib_r(8);
    cout<<"using recursion "<<rec<<endl;
    int memoization = fib_m(8);
    cout<<"using memoization "<<memoization<<endl;
    int tabulation = fib_t(8);
    cout<<"using tabulation "<<tabulation<<endl;
    return 0;
}