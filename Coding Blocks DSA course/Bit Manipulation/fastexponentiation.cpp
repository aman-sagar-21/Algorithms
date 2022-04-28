// Calculating power in log(n) time

#include<iostream>
using namespace std;

int power(int a, int n){
    int ans = 1;
    while(n>0){
        int x = n&1;
        if(x==1){
            ans *= a;
        }
        a = a*a;
        n = n>>1;
    }

    return ans;
}

int main(){
    cout<<power(2, 6);
}