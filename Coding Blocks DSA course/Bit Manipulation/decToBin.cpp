// convert decimal to binary

#include<iostream>
using namespace std;

int main(){

    int n = 13;
    int p = 1;
    int ans = 0;
    while(n>0){
        // Below code gives us reverse of the binary representation
        // int lastbit = n&1;
        // cout<<lastbit;
        // n = n>>1;

        // To get the actual bin rep, we can convert this binary representation into base 10 integer
        int lastbit = n&1;
        ans += p*lastbit;
        p = p*10;
        n = n>>1;
    }

    cout<<ans;
    
    return 0;

}