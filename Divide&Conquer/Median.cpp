/*

We are given 2 sorted arrays of size n each. We need to write a program to find median of array that we get after merging both arrays.

IMP POINTS:
1. if there are even number of values in the list, median = mean of middle two values
2. in case of odd, median = middle element

** the list should be sorted to find median and mode

even no. of elements = [1, 2, 3, 4, 5, 6]
median = (list[n/2] + list[n/2-1])/2

odd no. of elements = [1, 2, 3, 4, 5, 6, 7]
median = list[n/2] = list[7/2] = list[3] = 4

*/

//finding median using divide and conquer

#include<iostream>
#include<algorithm>
using namespace std;

int median(int a[], int n){
    if(n%2==0){
        return (a[n/2] + a[n/2-1])/2;
    }else{
        return a[n/2];
    }
}

int getMedian(int ar1[], int ar2[], int n){

    if(n<=0) return -1;
    if(n==1) return (ar1[0]+ar2[0])/2;
    if(n==2) return (max(ar1[0], ar2[0])+min(ar1[1], ar2[1]))/2;

    int m1 = median(ar1, n);
    int m2 = median(ar2, n);

    if(m1==m2) return m1;
    
    if(m1>m2){
        if(n%2==0){
            return getMedian(ar1, ar2+n/2-1, n - n/2 + 1); //n-n/2+1 = 6-3+1 = 4 in our case of even no. of elements list
        }
        return getMedian(ar1, ar2+n/2, n-n/2); //n-n/2 = 7-3 = 4
    }

    if(m1<m2){
        if(n%2==0){
            return getMedian(ar1+n/2-1, ar2, n - n/2 + 1); //n-n/2+1 = 6-3+1 = 4 in our case of even no. of elements list
        }
        return getMedian(ar1+n/2, ar2, n-n/2);
    }


}


int main(){
    int ar1[] = {1, 2, 3, 4, 5};
    int ar2[] = {7, 8, 9, 10, 11};
    int n = 5;
    int median = getMedian(ar1, ar2, n);
    cout<<median<<endl;
    int ar3[] = {1, 2, 3, 4, 5, 6};
    int ar4[] = {7, 8, 9, 10, 11, 12};
    n=6;
    median = getMedian(ar3, ar4, n);
    cout<<median<<endl;
    int ar5[] = {1};
    int ar6[] = {7};
    n=1;
    median = getMedian(ar5, ar6, n);
    cout<<median;
    return 0;
}