// Pepcoding Tower of Hanoi question to print all steps involved in tower of hanoi

#include<iostream>
using namespace std;

void toh(int n, int t1id, int t2id, int t3id, int &countofsteps){

    if(n==0) return;

    toh(n-1, t1id, t3id, t2id, countofsteps); // putting n-1 disks on t1 above nth disk to t3 
    cout<<n<<"["<<t1id<<" -> "<<t2id<<"]"<<endl; //putting nth disk from t1 to t2
    countofsteps++; 
    toh(n-1, t3id, t2id, t1id, countofsteps); //putting n-1 disks from t3 to t2 

    // and after all above steps we put all disks from t1 to t2

}

int main(){
    int n = 20;
    int t1id = 10;
    int t2id = 20;
    int t3id = 30;
    int countofsteps = 0;
    toh(n, t1id, t2id, t3id, countofsteps);    
    cout<<"No. of steps to complete the tower of hanoi problem for "<<n<<" disks is "<<countofsteps;
    // minimum number of steps to complete a tower of hanoi problem is (2^n)-1, where n is the number of disks
}