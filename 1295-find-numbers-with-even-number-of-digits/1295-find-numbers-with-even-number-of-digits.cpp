class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int out=0;
        
        for (int i=0; i<n;i++){
            int x=nums[i];
            int count=0;
            while(x!=0){
                count++;
                x/=10;
            }
            if (count%2==0){
                out++;
            }
            
        }
        return out;
    }
};