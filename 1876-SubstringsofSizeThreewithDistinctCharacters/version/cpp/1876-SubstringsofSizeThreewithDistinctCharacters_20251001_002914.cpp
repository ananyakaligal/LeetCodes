// Last updated: 10/1/2025, 12:29:14 AM
class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0, count=0;
        int n=s.length();

        if(n<3) return 0;

        while(i<=n-3){
            char a=s[i];
            char b=s[i+1];
            char c= s[i+2];

            if(a!=b && b!=c && c!=a) count++;
            i++;
        }
        return count;
    }
};