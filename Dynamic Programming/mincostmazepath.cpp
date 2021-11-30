// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a, which represents a maze.
// 4. You are standing in top-left cell and are required to move to bottom-right cell.
// 5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
// 6. Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom- 
//      right cell).
// 7. You are required to traverse through the matrix and print the cost of path which is least costly.

/*

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


int findMinCost(vector<vector<int>> v){

    int m = v.size();
    int n = v[0].size();

    vector<vector<int>> dp(m, vector<int>(n));

    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){

            if(i==m-1 && j==m-1) dp[i][j] = v[i][j];
            else if(i==m-1) dp[i][j] = v[i][j] + dp[i][j+1];
            else if(j==n-1) dp[i][j] = v[i][j] + dp[i+1][j];
            else {
                int min = dp[i+1][j]>dp[i][j+1]?dp[i][j+1]:dp[i+1][j];
                dp[i][j] = v[i][j] + min;
            }

        }
    }

    return dp[0][0];

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

    int minCost = findMinCost(v);

    cout<<minCost<<endl;

    return 0;

}