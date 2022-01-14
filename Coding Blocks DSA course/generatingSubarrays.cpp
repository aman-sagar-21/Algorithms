#include<iostream>
using namespace std;

int main(){

    int n = 5;
    int a[n] = {1, 2, 3, 4, 5};

    for(int i=0; i<n; i++){

        for(int j=i; j<n; j++){

            // to print a subarray(i, j)
            for(int k=i; k<=j; k++){
                cout<<a[k];
            }
            cout<<endl;

        }

    }

    return 0;

}