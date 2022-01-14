// WAVE PRINT -- 2D ARRAY
// GIVEN A 2D ARR
// 1 2 3 4 5
// 6 7 8 9 0
// 4 8 3 7 2
// its traversal is 1 6 4 8 7 2 3 8 3 7 9 4 5 0 2

#include<iostream>
using namespace std;

int main(){

    int v[3][5] = {{1,2,3,4,5}, {6,7,8,9,0}, {4,8,3,7,2}};

    for(int i=0; i<5; i++){
        int j;
        if(i%2==0) {
            j = 0;
            while(j<3){
                cout<<v[j][i];
                j++;
            }
        }else{
            j = 2;
            while(j>=0){
                cout<<v[j][i];
                j--;
            }
        }

    }
    return 0;

}