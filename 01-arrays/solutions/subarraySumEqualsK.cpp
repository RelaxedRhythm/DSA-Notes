#include<bits/stdc++.h>
using namespace std;

int subArraySumEqualsK(vector<int>arr,int k){
    int count=0;
    int prefixSum=0;
    unordered_map<int,int>map;
    map[0]=1;

    for(int i=0;i<arr.size();i++){
        prefixSum+=arr[i];
        if(map.find(prefixSum-k)!=map.end()){
            count+=map[prefixSum-k];
        }
        map[prefixSum]++;
    }
    return count;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    cout<<subArraySumEqualsK(arr,11);

}