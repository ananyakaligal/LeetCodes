// Last updated: 9/16/2025, 12:07:39 AM
class Solution {
public:
    void findSum(int num, int target, int cap,vector<int>& sub ,vector<vector<int>> &ans){
        if(target==0 && sub.size()==cap){
            ans.push_back(sub);
            return;
        }
        if(target<=0 || num==10) return;
        sub.push_back(num);
        findSum(num+1,target-num, cap,sub,ans);
        sub.pop_back();
        findSum(num+1,target, cap,sub,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sub;
        vector<vector<int>>ans;
        findSum(1,n, k, sub, ans);
        return ans;
    }
};