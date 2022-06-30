// given a number, count number of set bits (i.e. number of 1s in bin representation of a number)

#include<iostream>
using namespace std;

int countBits(int n){
    int ans  = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}

int countBitsFast(int n){
    int ans = 0;
    while(n>0){
        cout<<n<<endl;
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    int n = 13;
    cout<<countBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;

    return 0;
}
