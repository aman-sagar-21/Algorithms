#include<iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int l, int r){

	int pivot = a[r]; //considering the last element of the array as pivot
	int i=l-1;
	for(int j=l; j<=r-1; j++){
		if(a[j]<pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[r]);
	return i+1;

}

void quickSort(int a[], int l, int r){
	if(l<r){
		int pi = partition(a, l, r); // pivot position after every partition as pivot reaches its actual position(position in the sorted array)

		quickSort(a, l, pi-1);
		quickSort(a, pi+1, r);

	}
}


int main(){
	int a[] = {5, 4, 3, 2, 1, 0};
	int n = 6;
	quickSort(a, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}