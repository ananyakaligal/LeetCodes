// Last updated: 9/16/2025, 12:04:06 AM
class Solution {
private:
    bool isValid(vector<int>& weights, int days, int mid){
        int count=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
            }
        }
        if(sum>0) count++;
        return (count<=days);
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<high){
            int mid=low+(high-low)/2;
            if(isValid(weights,days,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};