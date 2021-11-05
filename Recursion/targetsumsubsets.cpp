/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. Complete the body of printTargetSumSubsets function - without changing signature - to calculate and print all subsets of given elements, the contents of which sum to "tar". 
Use sample input and output to get more idea.
Sample Input
5
10
20
30
40
50
60
Sample Output
10, 20, 30, .
10, 50, .
20, 40, .
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;

//sos: sum so far
void printTarSumSubs(vector<int> a, int idx, int target, int sos, string asf){

    if(sos>target) return;
    

    if(idx==a.size()){
        if(sos==target){
            cout<<asf+"."<<endl;
        }
        return;
    }

    printTarSumSubs(a, idx+1, target, sos+ a[idx], asf + to_string(a[idx])+", ");
    printTarSumSubs(a, idx+1, target, sos, asf); // this one so that we start our search again for a new subset from the next index at every recursive call
    // If you're seeing this code and don't understand what "printTarSumSubs(a, idx+1, target, sos, asf);" does, just remove it and see what happens
    // initial call was from 0th index, after we print a subset from there we move to 1st index and check for a subset from there and so on

}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(30);
    v.push_back(20);
    v.push_back(50);
    v.push_back(60);

    int target = 100;

    printTarSumSubs(v, 0, target, 0, "");
}