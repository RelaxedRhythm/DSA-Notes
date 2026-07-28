#include<bits/stdc++.h>
using namespace std;

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

int maxOnes(vector<int>arr,int k){
    int maxLen=0;
    int left=0;
    int zeros=0;
    for(int right=0;right<arr.size();right++){
        if(arr[right]==0)zeros++;
        while(zeros>k){
            if(arr[left]==0)zeros--;
            left++;
        }
        maxLen=max(maxLen,right-left+1);
                
    }
    return maxLen;
}

int main(){
    vector<int>arr={1,1,1,0,0,0,1,1,1,1,0};
    cout<<maxOnes(arr,2);
}