#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>arr){
    unordered_map<int,int>map;
    for(int i=0;i<arr.size();i++){
        map[arr[i]]++;
        if(map[arr[i]]>1)return true;
    }
    return false;
}
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

int removeDuplicates(vector<int>arr){
    int count=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[count]) {
            count++;
            arr[count]=arr[i];
        }
    }
    return count+1;
}

int main(){
    vector<int>arr={1,43,44,22,43,55};
    cout<<containsDuplicate(arr);
}