/*
GIVEN A SORTED 2D ARRAY, WHERE ELEMENTS IN EACH ROW AND COL ARE PRESENT IN A SORTED MANNER, WE NEED TO SEARCH FOR THE TARGET ELEMENT

NAIVE WAY (O(N*N)):
USE TWO LOOPS, SEARCH ELEMENT BY ELEMENT

LITTLE BIT OPTIMISED SOLUTION ((O(N*LOG N)))
USE BINARY SEARCH ON EACH ROW

STAIRCASE SEARCH
IF WE SEE THE FIRST ELEMENT OF THE FIRST ROW, WE CANNOT START SEARCHING FOR THEIR, BECAUSE, IF WE HAVE AN ELEMENT GREATER THAN THAT, WE'RE CONFUSED
ABOUT THE DIRECTION IN WHICH THE SEARCH SHOULD PROCEED AND WE NEED TO CHECK IN BOTH DIRECTIONS I.E. HORIZONTAL AND VERTICAL

BUT IF WE SEE THE LAST ELEMENT OF THE FIRST ROW, WE KNOW THAT ALL THE ELEMENTS SMALLER THAN IT ARE ON THE HORIZONTAL SIDE I.E. TO ITS LEFT AND 
ALL THE ELEMENTS GREATER THAN IT ARE ON THE VERTICAL DIRECTION I.E. DOWNWARD DIRECTION
AND THIS INFORMATION MAKES THE SEARCH EASIER AND CAN BE ACCOMPLISHED USING A SINGLE LOOP

*/

#include<iostream>
using namespace std;

//  STAIRCASE SEARCH
bool searchMatrixUsingStaircase(vector<vector<int>>& matrix, int target) {
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    int i=0;
    int j=n-1;
    
    while(j>=0 && i<m){
        
        if(target<matrix[i][j]){
            j--;
        }else if(target>matrix[i][j]){
            i++;
        }else{
            return true;
        }
        
    }
    
    return false;
    
}

//  Binary Search on each row
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();
    
    for(int i=0; i<r; i++){
        int l = 0, h = c-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(matrix[i][mid]==target) return true;
            if(matrix[i][mid]<target) l=mid+1;
            if(matrix[i][mid]>target) h=mid-1;
        }
    }
    
    return false;
}