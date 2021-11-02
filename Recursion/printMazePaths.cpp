#include<iostream>
#include<string>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string path){
    if(sr==dr && sc==dc){
        cout<<path<<endl;
    }
    if(sr>dr || sc>dc){
        return;
    }

    printMazePaths(sr, sc+1, dr, dc, path+"h");
    printMazePaths(sr+1, sc, dr, dc, path+"v");

}

int main(){
    int n = 3;
    int m = 4;

    printMazePaths(0, 0, n-1, m-1, "");
    return 0;
}