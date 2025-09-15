// Last updated: 9/16/2025, 12:11:10 AM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxLen=0;
        int i=0,j=0;
        int n=s.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end() && mp[s[j]]>=i){
                i=mp[s[j]]+1;
            }
            mp[s[j]]=j;
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};