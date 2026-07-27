#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>&arr){
    int zeros=0,ones=1,twos=arr.size()-1;
    while(ones<=twos){
        if(arr[ones]==0){
            swap(arr[ones],arr[zeros]);
            ones++;
            zeros++;
        }
        else if(arr[ones]==1) ones++;
        else{
            swap(arr[twos],arr[ones]);
            twos--;
        }
    }
}

int main(){
    vector<int>arr={1,2,0,1,2,0,2,0,0,1,1};
    sortColors(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}