// Last updated: 9/16/2025, 12:10:22 AM
class Solution {
public:
    void findC(int i, vector<int> & ds, vector<vector<int>>& ans, int target, vector<int>&arr ){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(i==arr.size() || target<0) return;

        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findC(i,ds,ans,target-arr[i],arr);
            ds.pop_back();
        }
        findC(i+1,ds,ans,target,arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector<int>>ans;
        vector <int> ds;
        findC(0,ds,ans,target,candidates);
        return ans;
    }
};