// Last updated: 9/16/2025, 12:06:37 AM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        vector<int>hash(26,0);
        int maxiChar=0, maxi=0;

        while(j<n){
            hash[s[j] - 'A']++;
            maxiChar = max(maxiChar, hash[s[j] - 'A']);

            if((j-i+1)-maxiChar>k){
                hash[s[i]-'A']--;
                i++;
            }

            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};