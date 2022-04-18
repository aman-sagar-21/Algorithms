// find the sum of all the submatrices of a matrix

#include<iostream>
using namespace std;

int main(){
    int m;
    int n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    int sum = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x = (i+1)*(j+1);//no. of cells in the top left 
            int y = (m-i)*(n-j);//no. of cells in the bottom right
            sum+=a[i][j]*x*y;
        }
    }

    cout<<sum<<endl;
    return 0;

}