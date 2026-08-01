#include<bits/stdc++.h>
using namespace std;

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

bool isRansom(string mag,string ran){
    if(mag.length()<ran.length()) return false;
    unordered_map<char,int>freq;
    for(int i=0;i<mag.size();i++){
        freq[mag[i]]++;
    }
    for(int i=0;i<ran.size();i++){
        if(freq.find(ran[i])==freq.end()) return false;
        freq[ran[i]]--;
    }
    return true;

}

int main(){
    string mag="aa", ran="aab";
    cout<<isRansom(mag,ran);
}