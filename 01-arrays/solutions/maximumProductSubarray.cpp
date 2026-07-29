#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element. 

// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

int maxProductSub(vector<int>arr){
    int currProd=1, maxProd=1;
    for(int i=0;i<arr.size();i++){
        currProd=max(arr[i],currProd*arr[i]);
        maxProd= max(currProd,maxProd);
    }
    return maxProd;
}

int main(){
    vector<int>arr={-2,0,-1};
    cout<<maxProductSub(arr);
}