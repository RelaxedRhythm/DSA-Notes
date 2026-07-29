#include<bits/stdc++.h>
using namespace std;

// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

// Example 1:
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
// Explanation:
// The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
// The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
// Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

vector<int>rearrangeEl(vector<int>&arr){
    vector<int>ans(arr.size(),0);
    int pos=0,neg=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            ans[pos]=arr[i];
            pos+=2;
        }
        else{
            ans[neg]=arr[i];
            neg+=2;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={3,1,-2,-5,2,-4,8};
    vector<int>ans=rearrangeEl(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}