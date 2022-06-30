// find the rightmost set bit mask

#include<iostream>
using namespace std;

int main(){

    int n=57;
    // cin>>n;

    int rsbm = n & -n;
    cout<<rsbm;

    return 0;

}
