#include<iostream>
#include<string>

using namespace std;

void printAllSubsequence(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    string ch = s.substr(0,1);
    string ros = s.substr(1);

    printAllSubsequence(ros, ans+ch);
    printAllSubsequence(ros, ans+"");

}

int main(){

    string s = "abcd";
    string initialAns = "";
    printAllSubsequence(s, initialAns);
    return 0;

}