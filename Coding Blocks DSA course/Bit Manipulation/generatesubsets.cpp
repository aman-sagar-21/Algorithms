// Print subsets of the given string
// what we have to do is.. we are given a number N(i.e. length of a string, we need to find all binary values of length N) and get characters
// corresponding to the set bits of each binary number... This will give us all the subsets of the string
// Watch some video if you can't understand from this explanation

// 000 "" last bit corresponds to a.. and so on
// 001 a
// 010 b
// 011 ab
// 100 c
// 101 ac
// 110 bc
// 111 abc


#include<iostream>
#include<string>
using namespace std;

void filterchars(int n, string s){
    int j = 0;
    while(n>0){
        int lastbit = n & 1;
        if(lastbit){
            cout<<s[j];
        }
        j+=1;
        n = n>>1;
    }
    cout<<endl;
}

void printSubsets(string a){
    int n = a.size();
    // cout<<(1<<n); // 1*(2^n)
    for (int i=0; i<(1<<n); i++){
        // cout<<i<<endl;
        filterchars(i, a);
    }
}

int main(){
    string s = "abcdefgh";
    printSubsets(s);
    return 0;
}