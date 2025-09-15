// Last updated: 9/16/2025, 12:03:09 AM
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>hash(3,0);
        int n=s.size();
        int i=0,j=0,count=0;

        while(j<n){
            hash[s[j]-'a']++;

            while(hash[0]!=0 && hash[1]!=0 && hash[2]!=0){
                count+=n-j;
                hash[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};