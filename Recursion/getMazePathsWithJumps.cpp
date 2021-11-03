#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> getPaths(int sr, int sc, int dr, int dc){

    if(sr==dr && sc==dc){
        vector<string> v;
        v.push_back("");
        return v;
    }
    

    vector<string> paths;

    //horizontal moves
    for(int i=1; i<=dc-sc; i++){
        vector<string> hpaths = getPaths(sr, sc+i, dr, dc);
        for(int j=0; j<hpaths.size(); j++){
            paths.push_back("h"+to_string(i)+hpaths[j]);
        }
    }

    //vertical moves
    for(int i=1; i<=dr-sr; i++){
        vector<string> vpaths = getPaths(sr+i, sc, dr, dc);
        for(int j=0; j<vpaths.size(); j++){
            paths.push_back("v"+to_string(i)+vpaths[j]);
        }
    }

    //diagonal moves
    for(int i=1; i<=dr-sr && i<=dc-sc; i++){
        vector<string> dpaths = getPaths(sr+i, sc+i, dr, dc);
        for(int j=0; j<dpaths.size(); j++){
            paths.push_back("d"+to_string(i)+dpaths[j]);
        }
    }

    return paths;


}

int main(){
    int m = 4;
    int n = 4;
    vector<string> paths = getPaths(0, 0, m-1, n-1);
    for(int i=0; i<paths.size(); i++){
        cout<<paths[i]<<" ";
    }
    return 0;
}