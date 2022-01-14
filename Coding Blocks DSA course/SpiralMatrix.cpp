// SPIRAL MATRIX 
// 1 2 3
// 4 5 6
// 7 8 9
// OUTPUT 1 2 3 6 9 8 7 4 5

// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// OUTPUT 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

#include<iostream>
using namespace std;

int main(){

    int m = 3;
    int n = 5;

    int a[m][n] = {{1,2,3,4,13}, 
                    {5,6,7,8,14}, 
                    {9,10,11,12,15}};

    int startRow = 0;
    int endRow = m-1;
    int startCol = 0;
    int endCol = n-1;

    while(startRow<=endRow && startCol<=endCol){

        for(int i=startCol; i<=endCol; i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;
        for(int i=startRow; i<=endRow; i++){
            cout<<a[i][endCol]<<' ';
        }
        endCol--;
        if(startRow<endRow){
            for(int i=endCol; i>=startCol; i--){
                cout<<a[endRow][i]<<' ';
            }
            endRow--;
        }
        
        if(startCol<endCol){
            for(int i=endRow; i>=startRow; i--){
                cout<<a[i][startCol]<<' ';
            }
            startCol++;
        }
        

    }

    return 0;

}