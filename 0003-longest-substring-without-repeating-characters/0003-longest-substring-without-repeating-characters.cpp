class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector < int > mpp(256, -1);
        int l=0, r=0, max_len=0;

        while(r<s.length()){
            if(mpp[s[r]]!=-1){
                if(l<=mpp[s[r]]){
                    l=mpp[s[r]]+1;
                }
            }
            max_len=max(r-l+1,max_len);
            mpp[s[r]]=r;
            r++;
        }
        return max_len;
    }
};