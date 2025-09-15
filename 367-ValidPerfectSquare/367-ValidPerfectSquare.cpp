// Last updated: 9/16/2025, 12:06:53 AM
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0|| num==1){
            return true;
        }

        int start =0;
        int end=num;
        int mid=-1;

        while(start<=end){
            mid=start+(end-start)/2;

            long long square=static_cast<long long>(mid)* mid;

            if (square > num){
                end=mid-1;
            }
            else if(square==num){
                return true;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};