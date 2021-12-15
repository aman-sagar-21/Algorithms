/*
COUNT BINARY STRINGS
1. You are given a number n.
2. You are required to print the number of binary strings of length n with no consecutive 0's.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;

    //SOLUTION 1, using extra space, O(n). We are using classic dp approach using array
    
    //bse0 : stores count of 'binary strings ending in 0', that follow the rule
    vector<int> bse0(n+1);
    vector<int> bse1(n+1);

    bse0[0] = 0; bse1[0] = 0;
    bse0[1] = 1; bse1[1] = 1;

    for(int i=2; i<=n; i++){
        bse0[i] = bse1[i-1];
        bse1[i] = bse0[i-1] + bse1[i-1];
    }

    cout<<bse0[n] + bse1[n];

    //----------------------next solution-------------------------------------------

    cout<<endl;

    // SOLUTION 2, without extra space

    int ocbs0 = 1;
    int ocbs1 = 1;

    for(int i=2; i<=n; i++){
        int ncbs0 = ocbs1;
        int ncbs1 = ocbs0 + ocbs1;

        ocbs0 = ncbs0;
        ocbs1 = ncbs1; 
    }

    cout<<ocbs0+ocbs1;

    return 0;

}