// KADANE'S ALGORITHM

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
    int curr = 0;

    for(int i=0; i<n; i++){
        curr = curr + a[i];
        maxsum = max(maxsum, curr);
        if(curr<0) curr = 0;
    }

    cout<<maxsum;
    return 0;
}

//similar kind of approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_till_now = INT_MIN;
        int curr_sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            curr_sum = nums[i]>curr_sum+nums[i]?nums[i]:curr_sum+nums[i];
            
            max_till_now = max(max_till_now, curr_sum);
        }
        
        return max_till_now;
    }
};