#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.
// Note that:

// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

// Input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

// Approach
// Maintain a running prefix sum.
// Store the first occurrence of each remainder (prefixSum % k) in a hash map.
// Initialize the map with {0 : -1} to handle subarrays starting from index 0.
// For each element:
// Update the prefix sum.
// Compute its remainder with k.
// If this remainder has been seen before:
// Check if the subarray length is at least 2.
// If yes, return true.
// Otherwise, store the current index as the first occurrence of this remainder.
// If no valid subarray is found, return false.

bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int curr = 0;

        for (int i = 0; i < n; i++) {
            curr += nums[i];
            int x = curr % k;

            if (mpp.count(x)) {
                if (i - mpp[x] >= 2)
                    return true;
            } else {
                mpp[x] = i;
            }
        }

        return false;
    
}

int main(){
    vector<int>arr={23,2,6,4,7};
    cout<<checkSubarraySum(arr,6);
}