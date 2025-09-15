// Last updated: 9/16/2025, 12:08:03 AM
class Solution {
public:
    int hammingWeight(int n) {
        int count =0;

        while(n){
            n=(n & (n-1));
            count++;
        }
        return count;
    }
};