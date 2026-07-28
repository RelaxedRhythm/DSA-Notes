#include<bits/stdc++.h>
using namespace std;

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

vector<int>twoSumII(vector<int>arr,int target){
    vector<int>ans;
    int left=0,right=arr.size()-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum<target) left++;
        else if(sum>target)right--;
        else{
            ans.push_back(left++);
            ans.push_back(right++);
        }
    }
    return ans;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    vector<int>ans=twoSumII(arr,9);
}