// FINDING MAXIMUM SUBARRAY SUM
// CUMULATIVE SUM METHOD (PRECOMPUTING SUM)
// WE CREATE A CUMULATIVE SUM ARRAY, CSUM[], CSUM[i] STORES CUMULATIVE SUM TILL Ith INDEX. 
// WE CAN FIND THE SUM OF A SUBARRAY OF RANGE [I,J] BY SUBTRACTING CSUM[J]-CSUM[I-1].
// FOR EXAMPLE: IF ARR IS 1 2 3 4 5 6  (1 INDEXED)
// CSUM = 1 3 6 10 15 21
// SUM[3, 5] = CSUM[5] - CSUM[2] = 15-3 = 12
// this is because if sum of first five elements is 15, then to get the sum of 3rd element till 5th element,
// we need to subtract the sum of first two elements. 

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int maxsum = INT_MIN;

    vector<int> csum(n);
    csum[0] = a[0];

    for(int i=1; i<n+1; i++){
        csum[i] = csum[i-1] + a[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            int sum = csum[j] - csum[i-1];
            maxsum = max(sum, maxsum);

        }
    }

    cout<<maxsum;
    return 0;    

}
