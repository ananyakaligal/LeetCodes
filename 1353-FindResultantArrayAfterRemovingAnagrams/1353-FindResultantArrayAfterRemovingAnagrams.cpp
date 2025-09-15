// Last updated: 9/16/2025, 12:03:32 AM
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string s=words[0],t;
        sort(s.begin(),s.end());
        for(int i=1;i<words.size();i++){
            t=words[i];
            sort(t.begin(),t.end());
            if(t==s) words[i].clear();
            else s=t;}
        vector<string> ans;
        for(string i: words) {
            if(i.size()>0) ans.push_back(i);}
        return ans;}};