// Last updated: 9/16/2025, 12:09:51 AM
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int low=1,high=x/2;
        
        while(low<high){
            int mid=low+(high-low+1)/2;
            
            long long square=1LL*mid*mid;
            if(square==x) return mid;
            else if(square<x){
                low=mid;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};