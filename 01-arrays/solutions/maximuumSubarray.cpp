#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int maxSum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < nums.size(); i++){
        maxSum = max(maxSum + nums[i], nums[i]);
        ans = max(maxSum, ans);
    }
    return ans;
}

int main(){
    vector<int>nums={1,2,-3,2,-1,3,2,1};
    cout<<maxSubArray(nums);
}