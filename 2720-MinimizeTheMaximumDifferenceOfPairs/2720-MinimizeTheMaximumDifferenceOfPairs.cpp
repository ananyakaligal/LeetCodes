// Last updated: 9/16/2025, 12:00:55 AM
class Solution {
private:
    bool isPossible(int mid, int p, vector<int>& nums){
        int n=nums.size();
        int count=0;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=mid){
                count++;
                i++;
                if (count>=p) return true;
            }
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int low=0;
        int high=nums[n-1]-nums[0];
        int answer=high;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(isPossible(mid,p, nums)){
                answer=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return answer;
    }
};