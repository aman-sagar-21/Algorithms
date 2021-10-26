#include<iostream>
using namespace std;

void printIncDec(int num){

    if(num==0) return;

    cout<<num<<" ";
    // if(num==1) return ; if we don't want 1 to be printed twice
    printIncDec(num-1);
    cout<<num<<" ";


}

int main(){

    printIncDec(5);
    return 0;

}