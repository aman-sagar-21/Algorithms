/*
In the Climb Stairs problem:

1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.

4. You are required to count the number of different paths via which you can climb to the top.
*/

#include<iostream>
using namespace std;

//using recursion
int countStairPaths(int n){

    if(n==0) return 1; //if(n==0) there is one way to reach 0, i.e. keep standing
    if(n<0) return 0;

    int a = countStairPaths(n-1);
    int b = countStairPaths(n-2);
    int c = countStairPaths(n-3);

    int totalPaths = a+b+c;
    return totalPaths;
}

int countStairPaths_memo(int n, int qb[]){

    if(n==0) return 1; //if(n==0) there is one way to reach 0, i.e. keep standing
    if(n<0) return 0;

    if(qb[n]>0) return qb[n];

    int a = countStairPaths(n-1);
    int b = countStairPaths(n-2);
    int c = countStairPaths(n-3);

    int totalPaths = a+b+c;
    qb[n] = totalPaths;
    return qb[n];
}

int countStairPaths_tab(const int n){
    
    int *paths = new int[n+1]; 
    //denotes no. of ways of reaching 0 from n+1, for eg, paths[4] stores no. of paths to reach 0 from 4 
    paths[0] = 1;
    for(int i=1; i<=n; i++){
        if(i==1){
            paths[i] = paths[i-1];
        }
        else if(i==2){
            paths[i] = paths[i-1] + paths[i-2];
        }else{
            paths[i] = paths[i-1] + paths[i-2] + paths[i-3];
        }
    }

    return paths[n];

}


int main(){
    int n = 10;
    cout<<countStairPaths(n)<<endl;
    //memoization table
    int qb[n+1];
    for(int i=0; i<n+1; i++){
        qb[i] = 0;
    }
    cout<<countStairPaths_memo(n, qb)<<endl;
    cout<<countStairPaths_tab(n);
}
