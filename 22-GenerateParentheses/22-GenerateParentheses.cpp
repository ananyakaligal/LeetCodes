// Last updated: 9/16/2025, 12:10:42 AM
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0,0,n,ans, "");
        return ans;
    }

private:
    void dfs(int start, int end, int n, vector<string>& ans, string s){
        if(start==end && start+end==n*2){
            ans.push_back(s);
            return;
        }

        if(start<n){
            dfs(start+1, end, n, ans, s + "(");
        }

        if(end<start){
            dfs(start, end+1, n, ans, s +")");
        }
    }
};