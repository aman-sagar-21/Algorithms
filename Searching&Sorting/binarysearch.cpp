// Works on sorted array

#include<iostream>
using namespace std;

int binsearch(int a[], int n, int k){

	int l=0;
	int h=n-1;
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid] == k) return mid;
		if(a[mid]<k) {
			l=mid+1;
		}
		if(a[mid]>k){
			h=mid-1;
		}
	}
	return -1;

}

int main(){

	int a[] = {5, 6, 7, 8, 9, 10};
	int n = sizeof(a)/sizeof(a[0]);
	int k = 5;
	int pos = binsearch(a, n, k);
	if(pos != -1) cout<<k<<" Found at "<<pos;
	else cout<<k<<" not found";

	return 0;
}