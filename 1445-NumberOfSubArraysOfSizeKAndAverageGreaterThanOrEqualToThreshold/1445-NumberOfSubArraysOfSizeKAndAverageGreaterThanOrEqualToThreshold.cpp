// Last updated: 9/16/2025, 12:03:13 AM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0,count=0,sum=0,ans=0;
        while(j<arr.size()){
            sum+=arr[j];
            if(j-i+1==k){
                ans=sum/k;
                if(ans>=threshold) count++;
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return count;
    }
};
