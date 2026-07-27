#include<bits/stdc++.h>
using namespace std;

// vector<int>twoSum(vector<int>arr,int k){
//     vector<int>ans;
//     unordered_set<int>s;
//     for(int i=0;i<arr.size();i++){
//         s.insert(arr[i]);
//     }
//     for(int i=0;i<arr.size();i++){
//         int need= k-arr[i];
//         if(s.find(need)!=s.end()){
//             ans.push_back(arr[i]);
//             ans.push_back(need);
//             return ans;
//         }
//     }
//     return {-1};
// }
//two pointer..
vector<int>twoSum(vector<int>arr,int k){
    vector<int>ans;
    sort(arr.begin(),arr.end());

    int left=0,right=arr.size()-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==k){
            ans.push_back(arr[left]);
            ans.push_back(arr[right]);
            return ans;
        }
        else if(sum<k) left++;
        else right--;
    }
    return {-1};
}

int main(){
    vector<int>arr={1,2,3,4,6,8};
    vector<int>ans=twoSum(arr,15);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}