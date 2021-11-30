/*
In this problem, 

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.

5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3). 

Sample Input
5 5
2 8 4 1 6
6 0 9 5 3
1 4 3 4 0
6 4 7 2 4
1 0 3 7 1

Sample output 
24

*/

#include<bits/stdc++.h>
using namespace std;

int maxVal(int a, int b, int c=0){

    if (a>b && a>c) {
      return a;
   } else if (b>c && b>a) {
      return b;
   } else {
      return c;
   }


}

int findMaxGold(vector<vector<int>> v){

    int m = v.size();
    int n = v[0].size();

    vector<vector<int>> dp(m,vector<int>(n));

    int maxGold = INT_MIN;

    for(int j=n-1; j>=0; j--){

        for(int i=0; i<m; i++){

            if(j==n-1) dp[i][j] = v[i][j];

            else if (i==0) dp[i][j] = v[i][j] + maxVal(dp[i][j+1], dp[i+1][j+1]);

            else if (i==n-1) dp[i][j] = v[i][j] + maxVal(dp[i][j+1], dp[i-1][j+1]);

            else dp[i][j] = v[i][j] + maxVal(dp[i][j+1], dp[i-1][j+1], dp[i+1][j+1]);



            if(dp[i][j]>maxGold) maxGold = dp[i][j];

        }


    }

    return maxGold;


}


int main(){
    int n, m;
    cin>>n>>m; //size of array

    vector<vector<int>> v(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    int maxGold = findMaxGold(v);

    cout<<maxGold<<endl;

    return 0;

}























