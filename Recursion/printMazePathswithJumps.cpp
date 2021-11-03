#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printPaths(int sr, int sc, int dr, int dc, string ans){

    if(sr==dr && sc==dc) {
        cout<<ans<<endl;
        return;
    }

    //horizontal paths
    for(int i=1; i<=dc-sc; i++){
        printPaths(sr, sc+i, dr, dc, ans+ "h"+to_string(i));
    }
    //vertical paths
    for(int i=1; i<=dr-sr; i++){
        printPaths(sr+i, sc, dr, dc, ans + "v"+to_string(i));
    }
    for(int i=1; i<=dc-sc && i<=dr-sr; i++){
        printPaths(sr, sc+i, dr, dc, ans + "d"+to_string(i));
    }

}

int main(){
    int m = 4;
    int n = 4;
    printPaths(0, 0, m-1, n-1, "");
    
    return 0;
}