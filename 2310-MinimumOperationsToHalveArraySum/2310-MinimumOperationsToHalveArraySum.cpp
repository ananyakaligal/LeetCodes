// Last updated: 9/16/2025, 12:01:32 AM
class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=accumulate(nums.begin(),nums.end(),0.0);
        priority_queue<double>pq (nums.begin(),nums.end());

        int k=0;
        double half=sum/2;

        while(sum>half){
            double top=pq.top();
            pq.pop();
            sum-=top;
            sum+=(top/2.0);
            k++;
            pq.push(top/2.0);
        }
        return k;
    }
};