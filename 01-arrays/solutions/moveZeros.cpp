#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int>&arr){
    int left=0,right=left+1;
    while(right<arr.size()){
        if(arr[left]!=0){
            left++;
            right++;
        }
        else if(arr[right]!=0){
            swap(arr[right],arr[left]);
            left++;
            right++;
        }
        else right++;
    }
}

int main(){
    vector<int>arr={1,0,9,0,4,5,6,0};
    moveZeros(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}