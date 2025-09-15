// Last updated: 9/16/2025, 12:02:58 AM
class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int c = 0, mx = 0;
        vector<int> a(26,0);
        a['a'-'a'] = 1;
        a['e'-'a'] = 1;
        a['i'-'a'] = 1;
        a['o'-'a'] = 1;
        a['u'-'a'] = 1;

        while (j < n){
            c+=a[s[j]-'a'];
            if(j-i+1==k){
                mx=max(mx,c);
                c-=a[s[i]-'a'];
                i++;
            }
            j++;
        }

        return mx;
    }
};