#include<iostream>
using namespace std;


// print numbers from 1 to num
void printIncreasing(int num){
    if(num==0) return;
    printIncreasing(num-1);
    cout<<num<<" ";
}

int main(){
    printIncreasing(5);
    return 0;
}