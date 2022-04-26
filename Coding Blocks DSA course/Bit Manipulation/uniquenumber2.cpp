// Find two unique numbers from an array where all other numbers appear twice
// arr = {1, 2, 1, 2, 3, 5, 3, 7}
// o/p = 5 7

#include<iostream>
#include<vector>
using namespace std;

int getBit(int pos, int n){
	int mask = 1<<pos;
	return (n&mask)>0;
}

int main() {

	int n;
	cin>>n;

	int arr[n];
	int xor_all = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		xor_all = xor_all^arr[i];
	}

	int pos = 0;
	int temp = xor_all;
	while((temp&1)==0){
		pos++;
		temp = temp>>1;
	}

	// after above loop we have found the position of first set in xor_all bit from the right

	vector<int> ele;
	for(int x:arr){
		if(getBit(pos, x)){
			ele.push_back(x);
		}
	}
	// found all the numbers which have a set bit at pos

	int f = 0;
	for(int x: ele){
		f = f^x;
	}
	// above loop gives us first number

	int s = xor_all^f;
	// second number is found above

	if(f<s){
		cout<<f<<" "<<s<<endl;
	}else{
		cout<<s<<" "<<f<<endl;
	}

	return 0;
}