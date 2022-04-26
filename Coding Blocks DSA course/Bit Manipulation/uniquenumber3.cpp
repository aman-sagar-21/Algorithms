// We have been given an array that contains all the numbers 3 times excpet one number.
// We need to find that unique number

#include<iostream>
using namespace std;

int main(){

    int count[64];
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        int j = 0;
        while(num>0){
            int lastbit = (num & 1);
            count[j] += lastbit;
            j++;
            num = num>>1;
        }

    }

    int p = 1;
    int ans = 0;

    for(int i=0; i<64; i++){
        count[i] %= 3;
        ans += (count[i]*p);
        p = p<<1; // doubles p
    }

    cout<<ans;

}