#include<iostream>
#include<string>
using namespace std;

void printPermutations(string ques, string ans){

    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }

    for(int i=0; i<ques.length(); i++){
        char ch = ques[i];
        string ros = ques.substr(0, i) + ques.substr(i+1);
        printPermutations(ros, ans+ch);
    }

}

int main(){
    string s = "abc";
    printPermutations(s, "");
    return 0;
}