#include<iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int a[], int n){

	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}

}

int main(){
	int a[] = {10, 9, 6, 8, 7, 5};
	int n = 6;
	bubbleSort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}