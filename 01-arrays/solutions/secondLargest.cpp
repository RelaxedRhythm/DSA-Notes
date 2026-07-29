#include<bits/stdc++.h>
using namespace std;

int secLarge(vector<int>arr){
    int maxEl=0;
    int secMax=0;
    for(int i=0;i<arr.size();i++){
        int curr=arr[i];
        if(curr>maxEl){
            secMax=maxEl;
            maxEl=curr;
        }
        else if(curr<maxEl && curr>secMax) secMax=curr;
    }
    return secMax;
}

int main(){
    vector<int>arr={1,4,6,3,8,2,6,3,8,1};
    cout<<secLarge(arr);
}