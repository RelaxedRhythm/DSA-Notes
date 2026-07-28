#include<bits/stdc++.h>
using namespace std;

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

int minLenSubarray(vector<int>arr,int target){
    int minLen=INT_MAX;
    int left=0;
    int sum=0;
    for(int right=0;right<arr.size();right++){
        if(arr[right]==target) return 1;
        sum+=arr[right];
        
        while(sum>=target){
            minLen=min(minLen,right-left+1);
            sum-=arr[left];
            left++;
        }
       
    }
    return minLen;
}

int main(){
    vector<int>arr={1,4,4};
    cout<<minLenSubarray(arr,4);
}