// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner. 
// Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
// 5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.


#include<iostream>
#include<string>
#include<vector>
using namespace std;

void floodfill(vector<vector<int>> maze, int row, int col, string asf, vector<vector<bool>> visited){

    if(row<0 || col<0 || row==maze.size() || col==maze[0].size() || maze[row][col]==1 || visited[row][col] == true){
        // cout<<"Returning"<<endl;
        return;
    }
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<asf<<endl;
        return;
    }

    visited[row][col] = true;
    floodfill(maze, row-1, col, asf+"t", visited);
    floodfill(maze, row, col-1, asf+"l", visited);
    floodfill(maze, row+1, col, asf+"d", visited);
    floodfill(maze, row, col+1, asf+"r", visited);
    visited[row][col] = false;

}

int main() {
  int n, m;
  n=3;
  m=3;
  vector < vector < int >> arr(n, vector < int > (m));

  arr[0][0] = 0;
  arr[0][1] = 0;
  arr[0][2] = 0;
  arr[1][0] = 1;
  arr[1][1] = 0;
  arr[1][2] = 1;
  arr[2][0] = 0;
  arr[2][1] = 0;
  arr[2][2] = 0;
      
  
  vector<vector<bool>> visited(n, vector < bool > (m));

  
  floodfill(arr, 0, 0, "", visited);
}