#include<iostream>
#include<string>
#include<vector>

using namespace std;


// Faith: getSubsequence(bc) => [--, -c, b-, bc]
// Expectation: getSubsequence(abc) => [---, --c, -b-, -bc, a--, a-c, ab-, abc]
vector<string> getSubsequence(string s){

    // base case, length of string is 0
    // Empty string has one subsequence i.e. empty string itself
    // Max no. of substrings that a string can have is 2^n , n = no. of characters in the string

    if(s.length()==0){
        // bres = base result
        vector<string> bres;
        bres.push_back("");
        return bres;
    }


    // ros - rest of string, string remaining after removing first element
    string ros = s.substr(1);
    vector<string> res = getSubsequence(ros);
    // mres-my result
    vector<string> mres;
    for(int i=0; i<res.size(); i++){
        mres.push_back(res[i]);
    }
    for(int i=0; i<res.size(); i++){
        mres.push_back(s[0] + res[i]);
    }

    return mres;

}

int main(){

    string s = "abcdef";
    vector<string> result = getSubsequence(s);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<", ";
    }

    return 0;

}