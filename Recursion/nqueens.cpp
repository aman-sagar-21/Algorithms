/*

1. You are given a number n, the size of a chess board.
2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
Note - Queens kill at distance in all 8 directions
3. Complete the body of printNQueens function - without changing signature - to calculate and print all safe configurations of n-queens.
 Use sample input and output to get more idea

 Constraints
1 <= n <= 10
Sample Input
4
Sample Output
0-1, 1-3, 2-0, 3-2, .
0-2, 1-0, 2-3, 3-1, .

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//using this function we check if there is a queen present in vertical or diagonal direction above this location, if a queen is present,\
the provided location is not safe to put the next queen
bool isSafeLoc(vector<vector<int>> chess, int row, int col){

    //checking vertical above
    for(int i=row-1, j=col; i>=0; i--){
        if(chess[i][j]==1) return false;
    }
    // checking left diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(chess[i][j]==1) return false;
    }
    // checking right diagonal
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--, j++){
        if(chess[i][j]==1) return false;
    }

    return true;

}


//Since we want to put a queen in every row starting from row 0, so we put a queen in each col and check for positions in other rows where we can put a queen
void nqueens(vector<vector<int>> chess, string qsf, int row){

    if(row==chess.size()){
        cout<<qsf<<" ."<<endl;
        return;
    }

    for(int i=0; i<chess.size(); i++){

        if(isSafeLoc(chess, row, i)==true){
            chess[row][i] = 1; //placing a queen here
            //and then looking for the positions in the next rows to place another queen using below recursion call
            nqueens(chess, qsf+to_string(row)+"-"+to_string(i)+",", row+1);
            chess[row][i] = 0; //removing the queen from here otherwise for the next iterations,\
            it would cause a problem because we won't be able to accomodate a queen in that column
        }
    }


}

int main(){
    int n = 6;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    nqueens(chess, "", 0);
    return 0;
}