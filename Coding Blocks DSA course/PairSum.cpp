// PAIR SUM
// GIVEN A SORTED ARRAY, FIND PAIRS WHOSE SUM IS EQUAL TO THE GIVEN TARGET
// TWO POINTER APPROACH
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int target;
    cin>>target;

    vector<vector<int>> pairs;

    int i=0; int j=n-1;

    while(i<j){
        if(target-v[i]<v[j]) j--;
        else if(target-v[j]>v[i]) i++;
        else {
            vector<int> pair(2);
            pair[0] = v[i];
            pair[1] = v[j];
            i++; j--;
            pairs.push_back(pair);
        }
    }

    for(int i=0; i<pairs.size(); i++){
        cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
    }

    return 0;
    
}
