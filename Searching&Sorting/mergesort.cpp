#include<iostream>
using namespace std;

void merge(int arr[], int const l, int const m, int const r){

    int const s1 = m-l+1;
    int const s2 = r-m;
    int *a = new int(s1);
    int *b = new int(s2);

    for(int i=0; i<s1; i++){
        a[i] = arr[l+i];
    }
    for(int i=0; i<s2; i++){
        b[i] = arr[m+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<s1 && j<s2){

        if(a[i]<b[j]){
            arr[k] = a[i];
            i++; k++;
        }else{
            arr[k] = b[j];
            j++; k++;
        }

    }

    while(i<s1){
        arr[k] = a[i];
        i++;k++;
    }

    while (j<s2)
    {
        arr[k] = b[j];
            j++; k++;
    }
    

}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);

    }
}


int main(){
	int a[] = {5, 4, 3, 2, 1, 0};
	int n = 6;
	mergeSort(a, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
