#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(int a[], int n){

	for(int i=0; i<n-1; i++){

		int min = i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[min]) min = j;
		}
		swap(a[i], a[min]);
	}

}

int main(){
	int a[] = {5, 4, 3, 2, 1, 0};
	int n = 6;
	selectionSort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}