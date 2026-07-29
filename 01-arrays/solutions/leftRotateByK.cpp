#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

void rotateByk(vector<int>&arr,int k){
        k=k%arr.size();
        reverse(arr.begin(),arr.begin()+k);
        reverse(arr.begin()+k,arr.end());
        reverse(arr.begin(),arr.end());
}

int main(){
    vector<int>arr={2,4,1,5,8};
    //51428

    rotateByk(arr,3);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}