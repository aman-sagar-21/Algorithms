// TRAILING ZEROES
// count the number of zeros in n!

#include<iostream>
using namespace std;

int main(){

    int n = 100;
    int count = 0;

    int p = 5;

    while(n/p>0){
        count += (n/p);
        p = p*5;
    }

    cout<<count;

    return 0;

}