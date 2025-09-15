// Last updated: 9/16/2025, 12:04:47 AM
class Solution {
private:
    bool check(vector<int>& piles, int h, int mid){
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum += (piles[i] + mid - 1) / mid;
        }
        return (sum<=h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(), piles.end());
        while(low<high){
            int mid= low+(high-low)/2;
            bool x= check(piles,h, mid);

            if(x){// yes, check for lower
                high=mid;
            }else{ //cannot, return back
                low=mid+1;
            }
        }
        return high;
    }
};