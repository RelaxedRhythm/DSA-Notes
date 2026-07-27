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

int main(){
    vector<int>arr={1,43,44,22,43,55};
    cout<<containsDuplicate(arr);
}