#include<bits/stdc++.h>

using namespace std;

int main(){

    int n = 5;
    int a[n] = {1, 2, 3, 4, 5};
    int maxsum = INT_MIN;
    int curr;

    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){

            // to get sum of a subarray(i, j)
            curr = 0;
            for(int k=i; k<=j; k++){
                curr += a[k];
            }
            
            maxsum = maxsum<curr?curr:maxsum;

        }

    }

    cout<<maxsum;

    return 0;

}