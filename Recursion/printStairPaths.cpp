#include<iostream>
#include<string>
using namespace std;

void psp(int n, string path){
    if(n<0) return;
    if(n==0) {
        cout<<path<<endl;
        return;
    }

    psp(n-1, path + "1");
    psp(n-2, path + "2");
    psp(n-3, path + "3");
}

int main(){
    int n=5;
    psp(n, "");
    return 0;
}