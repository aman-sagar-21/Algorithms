#include<iostream>
using namespace std;

int printFact(int n){
    
    if(n==0) return 1;

    return n*printFact(n-1);

}

int main(){


    unsigned long long int x = printFact(10);
    cout<<x;

    return 0;
}