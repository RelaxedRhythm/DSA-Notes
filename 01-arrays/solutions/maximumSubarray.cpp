#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

int maxSub(vector<int>arr){
    int currSum=0;
    int maxSum=0;
    for(int i=0;i<arr.size();i++){
        currSum=max(arr[i],currSum+arr[i]);
        maxSum=max(maxSum,currSum);
    }
    return maxSum;
}

int main(){
    vector<int> arr={5,4,-1,7,8};
    cout<<maxSub(arr);
}