#include<iostream>
#include<string>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};


void printKeypadCombos(string keycom, string ans){

    if(keycom.size()==0){
        cout<<ans<<endl;
        return;
    }

    string ch = keycom.substr(0,1);
    int fkey = stoi(ch);
    string ros = keycom.substr(1);

    string alphs_at_fkey = codes[fkey];
    for(int i=0; i<alphs_at_fkey.size(); i++){
        char ch = alphs_at_fkey[i];
        printKeypadCombos(ros, ans+ch);
    }


}

int main(){
    string ques = "678";
    printKeypadCombos(ques, "");

    return 0;
}