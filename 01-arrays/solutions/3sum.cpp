#include <bits/stdc++.h>
using namespace std;

vector<int> threeSum(vector<int> arr, int k){
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        int left = i + 1;
        int right = arr.size() - 1;
        while (left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == k){
                ans.push_back(arr[i]);
                ans.push_back(arr[left]);
                ans.push_back(arr[right]);
                return ans;
            }
            else if (sum < k)
                left++;
            else
                right--;
        }
    }
    return {-1};
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
    vector<int> ans = threeSum(arr, 6);
     for (int x : ans) {
        cout << x << " ";
    }
}