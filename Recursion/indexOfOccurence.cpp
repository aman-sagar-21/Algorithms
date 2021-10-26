#include<iostream>
using namespace std;

int first_ioo (int arr[], int n, int x){

    //base case
    if(n==1) {
        if(arr[0]==x) return n-1;
        else return -1;
    }

    int fio = first_ioo(arr, n-1, x);
    if(fio!=-1) return fio;
    else if(arr[n-1]==x) return n-1;
    return -1;
    
}

int last_ioo(int arr[], int n, int x){
    // base case
    if(n==1) {
        if(arr[0]==x) return n-1;
        else return -1;
    }

    if(arr[n-1]==x) return n-1;
    else return last_ioo(arr, n-1, x); 
}

int main(){

    int arr[] = {8, 2, 3, 4, 5, 6, 4, 8, 7, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<n<<endl;
    int x = 0;

    cout<<"From beginning"<<endl;

    int index = first_ioo(arr, n, x);

    if(index!=-1){
        cout<<index<<" for programmers";
        cout<<endl<<index+1<<" for non-programmers";
    }else {
        cout<<"Not found";
    }
    

    cout<<endl<<endl<<"First occurence from last"<<endl;

    index = last_ioo(arr, n, x);
    
    if(index!=-1){
        cout<<n-index<<" from last";
    }else {
        cout<<"Not found";
    }

    return 0;

}