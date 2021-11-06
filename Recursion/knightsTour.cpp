/*

1. You are given a number n, the size of a chess board.
2. You are given a row and a column, as a starting point for a knight piece.
3. You are required to generate the all moves of a knight starting in (row, col) such that knight visits 
     all cells of the board exactly once.
4. Complete the body of printKnightsTour function - without changing signature - to calculate and 
     print all configurations of the chess board representing the route
     of knight through the chess board. Use sample input and output to get more idea.

Input Format
A number n
A number row
A number col

Output Format
All configurations of the chess board representing route of knights through the chess board starting in (row, col)
Use displayBoard function to print one configuration of the board.

Sample Input
5
2
0

Sample Output
25 2 13 8 23 
12 7 24 3 14 
1 18 15 22 9 
6 11 20 17 4 
19 16 5 10 21 

19 2 13 8 21 
...

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void display(vector<vector<int>> chess){
    for(int i=0; i<chess.size(); i++){
        for(int j=0; j<chess.size(); j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}

//tour: path taken by knight
void knightsTour(vector<vector<int>> chess, int row, int col, int moveCount){

    if(row<0 || col<0 || row>=chess.size() || col>=chess.size() || chess[row][col]>0) return;
    else if(moveCount==chess.size()*chess.size()){
        chess[row][col] = moveCount;
        display(chess);
        chess[row][col] = 0;
        cout<<endl;
        return;
    }

    chess[row][col] = moveCount;
    knightsTour(chess, row-2, col+1, moveCount+1);
    knightsTour(chess, row-1, col+2, moveCount+1);
    knightsTour(chess, row+1, col+2, moveCount+1);
    knightsTour(chess, row+2, col+1, moveCount+1);
    knightsTour(chess, row+2, col-1, moveCount+1);
    knightsTour(chess, row+1, col-2, moveCount+1);
    knightsTour(chess, row-1, col-2, moveCount+1);
    knightsTour(chess, row-2, col-1, moveCount+1);
    chess[row][col] = 0; // making it 0 again because after printing a configuration, we need to go back to initial state to be able to print other configuration also

}

int main(){
    int n = 5;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    //row and col tell the initial position of knight (ghoda in hindi)
    int row = 2;
    int col=0;
    knightsTour(chess, row, col, 1);
}