#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int left=0,right=s.size()-1;
    while(left<=right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    string s="strinrts";
    cout<<isPalindrome(s);
}