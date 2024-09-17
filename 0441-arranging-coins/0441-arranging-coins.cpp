class Solution {
public:
    int arrangeCoins(int n) {
        int start=1;
        int end=n;
        int mid=-1;

        while(start<=end){
            mid=start+(end-start)/2;
            long long sum = static_cast<long long>(mid) * (mid + 1) / 2;

            if(sum<n){
                start=mid+1;
            }
            else if(sum==n){
                return mid;
            }
            else{
                end=mid-1;
            }
        }
    return end;
    }
};