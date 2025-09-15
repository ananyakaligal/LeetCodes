// Last updated: 9/16/2025, 12:06:58 AM
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1);
        for(int i=0;i<=n;i++){
            if(i%2==0){
                arr[i]=arr[i/2];
            }else{
                arr[i]=arr[i/2]+1;
            }
        }
        return arr;
    }
};