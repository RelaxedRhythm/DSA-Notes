#include<bits/stdc++.h>
using namespace std;

int longestConsSeq(vector<int>arr){
    unordered_set<int>set(arr.begin(),arr.end());
    int maxLen=0;
    for(int i=0;i<arr.size();i++){
        int num=arr[i];
        if(set.find(num-1)!=set.end())continue;
        int start=num;
        int currLen=1;
        while(set.find(start+1)!=set.end()){
            start++;
            currLen++;
        }
        maxLen=max(maxLen,currLen);
    }
    return maxLen;
}

int main(){
    vector<int>arr={22,3,4,1,2,44,3,43,45,3,47,4,6,46,22,48};
    cout<<longestConsSeq(arr);
}