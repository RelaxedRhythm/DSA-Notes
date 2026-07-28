#include <bits/stdc++.h>
using namespace std;

// Given a string s, find the length of the longest substring without duplicate characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

int longestSubstr(string s){
    int maxLen = 0;
    int left = 0;
    unordered_set<char> st;
    for (int right = 0; right < s.size(); right++){
        while (st.find(s[right]) != st.end()){
                st.erase(s[left]);
                left++;
        }

        st.insert(s[right]);

        int currLen = right - left + 1;
        maxLen = max(currLen, maxLen);
    }

    return maxLen;
}

int main(){
    string s = "shjshhsrt";
    cout<<longestSubstr(s);
}