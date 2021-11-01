#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> getStairPaths(int n){

    if(n==0){
        // base case if we don't wanna go anywhere still we need a path... There is a path where we don't move any position and in that case we return an empty string
        vector<string> v;
        v.push_back("");
        return v;

    }else if(n<0){
        // There may be a case when on recursive call we get a negative value of n
        // In that case we return an empty list i.e. we don't add any path to the list
        vector<string> bv;
        return bv;
    }


    vector<string> v1 = getStairPaths(n-1); //helps us get paths when only 1 stair is climbed... n-1 because we'll have n-1 stairs remaining when we climb 1 stair
    vector<string> v2 = getStairPaths(n-2); //similar explanation as above
    vector<string> v3 = getStairPaths(n-3);

    vector<string> allPaths;

    // Adding 1 in front of paths returned when only 1 stair was climbed
    for(int i=0; i<v1.size(); i++){
        allPaths.push_back("1"+v1[i]);
    }
    for(int i=0; i<v2.size(); i++){
        allPaths.push_back("2"+v2[i]);
    }
    for(int i=0; i<v3.size(); i++){
        allPaths.push_back("3"+v3[i]);
    }

    return allPaths;


}

int main(){
    int n = 4;
    vector<string> v = getStairPaths(n);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<", ";
    }
    return 0;
}