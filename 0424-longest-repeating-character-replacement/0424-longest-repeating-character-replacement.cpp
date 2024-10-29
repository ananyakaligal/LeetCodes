class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, max_count=0, max_len=0;
        unordered_map<char,int> charCount;

        while(r<s.length()){
            charCount[s[r]]++;
            max_count=max(max_count, charCount[s[r]]);

            if((r-l+1)-max_count>k){
                charCount[s[l]]--;
                l++;
            }

            max_len=max(r-l+1,max_len);
            r++;
        }
        return max_len;
    }
};