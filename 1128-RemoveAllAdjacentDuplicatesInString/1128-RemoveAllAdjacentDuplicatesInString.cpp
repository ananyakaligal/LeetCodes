// Last updated: 9/16/2025, 12:03:58 AM
class Solution {
public:
    string removeDuplicates(string s) {
      string ans="";
        for(int i=0;i<s.length();i++)
        { char currchar=s[i];
          if(ans.empty())
          { 
           ans.push_back(currchar);
          }
          else if(currchar == ans.back())
          {
            ans.pop_back();
          }
           else if(currchar != ans.back())
          {
            ans.push_back(currchar);
          }
    
        } return ans;
    }
    
};