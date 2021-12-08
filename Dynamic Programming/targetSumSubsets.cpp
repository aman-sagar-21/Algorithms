/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add 
     up to "tar" or not.
*/

#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> nums, int target){

    int m = nums.size()+1;
    int n = target+1;

    vector<vector<bool>> dp(m, vector<bool>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = true;
            else if(i==0) dp[i][j] = false;
            else if(j==0) dp[i][j] = true;
            else {
                if(dp[i-1][j]==true){
                    dp[i][j] = true;
                }else{
                    
                    if(j>=nums[i-1])
                        dp[i][j] = dp[i-1][j-nums[i-1]];
                    
                }
            }
        }
    }
    
    return dp[m-1][n-1];

}

int main(){

    int n; cin>>n; 
    vector<int> nums;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        nums.push_back(x);
    }

    int target; cin>>target;

    bool isSubsetPresent = isSubset(nums, target);

    // cout<<isSubsetPresent;
    if(isSubsetPresent) cout<<"true";
    else cout<<"false";

    return 0;
}