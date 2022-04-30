/* Create Swastik Pattern

*  ****
*  *
*  *
*******
   *  *
   *  *
****  *

*/

#include<iostream>
using namespace std;

int main(){
    int n = 7;
    int top_right = (n+1)/2;
    for(int i = 0; i < n; i++){
        
        if(i==0){

            for(int j=0; j<n; j++){
                if(j==0 or j>=n/2){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }


        }else if(i<n/2){

            for(int j=0; j<n; j++){
                if(j==0 or j==n/2){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }

        }else if(i==n/2){

            for(int j = 0;j<n; j++){
                cout<<"*";
            }

        }else if(i>n/2 and i<n-1){
            
            for (int j=0; j<n; j++){
                if(j==n/2 or j==n-1) cout<<"*";
                else cout<<" ";
            }

        }else{

            for(int j=0; j<n; j++){
                if(j<top_right or j==n-1){
                    cout<<"*";
                }else{
                    cout<<" ";
                }
            }

        }

        cout<<endl;


    }

    return 0;
}