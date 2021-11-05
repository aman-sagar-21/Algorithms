/*
PEPCODING QUES
1. You are given a string str of digits. (will never start with a 0)
2. You are required to encode the str as per following rules
    1 -> a
    2 -> b
    3 -> c
    ..
    25 -> y
    26 -> z
3. Complete the body of printEncodings function - without changing signature - to calculate and print all encodings of str.
Use the input-output below to get more understanding on what is required
123 -> abc, aw, lc
993 -> iic
013 -> Invalid input. A string starting with 0 will not be passed.
103 -> jc
303 -> No output possible. But such a string maybe passed. In this case print nothing.

*/


#include<iostream>
#include<string>
using namespace std;

void printEncodings(string ques, string ans){

    if(ques.length() == 0){
        cout<<ans<<endl;
        return;
    }else if(ques.length()==1){
        char ch = ques[0];
        if(ch=='0'){
            return;
        }
        int chv = ch - '0';
        char code = char('a'+chv-1);
        cout<<ans+code<<endl;

    }else{

        char ch = ques[0];
        string ros = ques.substr(1);
        if(ch=='0'){
            return;
        }else{
            int chv = ch - '0';
            char code = char('a'+chv-1);
            printEncodings(ros, ans+code);
        }

        string ch12 = ques.substr(0,2); //character 1 and 2 of the ques string
        string ros12 = ques.substr(2);

        if(stoi(ch12)>26){
            return;
        }else{

            int chv = stoi(ch12);
            char code = 'a' + chv - 1;
            printEncodings(ros12, ans+code);
        }

    }


}

int main(){
    cout<<"single characters (just like me :') )"<<endl;
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";
    string s4 = "4";
    printEncodings(s1, "");
    printEncodings(s2, "");
    printEncodings(s3, "");
    printEncodings(s4, "");

    cout<<"other test cases"<<endl;

    string s5 = "123";
    string s6 = "993";
    string s7 = "103";
    string s8 = "303";
    printEncodings(s5, "");
    printEncodings(s6, "");
    printEncodings(s7, "");
    printEncodings(s8, "");
    return 0;
}