#include<bits/stdc++.h>
using namespace std;

void reverse(string &s){
    int left=0,right=s.size();
    while(left<=right){
        swap(s[left],s[right]);
        left++,right--;
    }
}


int main(){
    string s="strins";
    reverse(s);
    cout<<s;
}