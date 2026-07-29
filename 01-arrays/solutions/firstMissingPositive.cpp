#include <bits/stdc++.h>
using namespace std;

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.

// Approach
// Replace all numbers that are ≤ 0 or > n with n + 1 because they cannot affect the answer.
// Traverse the array and for every valid number x (1 ≤ x ≤ n), mark its presence by making nums[x - 1] negative.
// Traverse the array again. The first positive element at index i means the number i + 1 is missing.
// If every index is marked, then all numbers from 1 to n are present, so return n + 1.

int firstMiss(vector<int> nums){
    int n = nums.size();
    int idx = -1;
    for (int i = 0; i < n; i++){
        if (nums[i] > n || nums[i] <= 0)
            nums[i] = n + 1;
    }
    for (int i = 0; i < n; i++){
        int x = abs(nums[i]);
        if (x <= n)
            nums[x - 1] = -abs(nums[x - 1]);
        ;
    }
    for (int i = 0; i < n; i++){
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int main(){
    vector<int> arr = {3, 4, -1, 1};
    cout << firstMiss(arr);
}