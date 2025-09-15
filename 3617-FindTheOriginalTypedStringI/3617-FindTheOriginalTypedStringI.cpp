// Last updated: 9/16/2025, 12:00:43 AM
class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int total = 1;  // always count the original string
        
        for (int i = 0; i < n; ) {
            int j=i;
            while(word[i]==word[j]){
                j++;
            }
            int x=j-i;
            if(x>=2) total+=(x-1);
            i=j;
        }
        
        return total;
    }
};
