/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).
3. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

n=3
m=3

output
[hhvv, hvhv, hvvh, vhhv, vhvh, vvhh]

*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {

    if(sr==dr && sc==dc){
        vector<string> v;
        v.push_back("");
        return v;
    }else if(sr>dr || sc>dc){
        vector<string> v;
        return v;
    }

    vector<string> paths_onc = getMazePaths(sr, sc+1, dr, dc); //paths returned when we move 1 col
    vector<string> paths_onr = getMazePaths(sr+1, sc, dr, dc); //paths returned when we move 1 row

    vector<string> allPaths;

    for(int i=0; i<paths_onc.size(); i++){
        allPaths.push_back("h"+paths_onc[i]);
    }
    for(int i=0; i<paths_onr.size(); i++){
        allPaths.push_back("v"+paths_onr[i]);
    }

    return allPaths;


}

void display(vector<string> arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; 
    n = 4;
    m = 4;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}