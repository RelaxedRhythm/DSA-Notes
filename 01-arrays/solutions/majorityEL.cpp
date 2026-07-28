#include<bits/stdc++.h>
using namespace std;

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

int majorityEl(vector<int>arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    return arr[n/2];
}

int main(){
    vector<int>arr={1,3,4,2,3,3,3};
    cout<<majorityEl(arr);
}