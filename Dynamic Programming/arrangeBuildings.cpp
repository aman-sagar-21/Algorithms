/*
ARRANGE BUILDINGS
In this problem, 
1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

This problem is basically same as the counting number of binary strings without consecutive 0s. Here we can have an empty plot or a building at a particular position
We need to find the number of different arrangements for buildings and spaces on each side of the road. The number of arrangements for one side of 
the road is same as the number of arrangements for the other side as well. So we can find count of arrangements for 1 side and do something to find
total number of arrangements for buildings on both sides.

Now finding arrangements for one side similar to finding binary strings without consecutive 0s because binary strings are also an arrangement of 
0s and 1s if we consider buildings to be the 0s of each side of the road and 1s to be the spaces(empty plots) on each side of the road. We can consecutive
spaces but not buildings just like we had consecutive 1s but not zeros in previous ques.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    //for road of size 1
    //cbor = count of buildings on one side of road
    int cbor = 1;
    int csor = 1;

    for(int i=2; i<=n; i++){
        int ncbor = csor;
        int ncsor = cbor + csor;

        csor = ncsor;
        cbor = ncbor;
    }

    int total_ways_for_one_side = csor+cbor;

    //total ways for both sides 
    int total = total_ways_for_one_side*total_ways_for_one_side;
    //we squared because both sides can be arranged in total_ways_for_one_side ways
    //Basic permutation that even i need to learn again

    cout<<total;

    return 0;

}