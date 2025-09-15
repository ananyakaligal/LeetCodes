// Last updated: 9/16/2025, 12:02:24 AM
class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), ans = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                
                int maxFreq = *max_element(freq.begin(), freq.end());
                int minFreq = INT_MAX;
                
                for (int f : freq) 
                    if (f > 0) minFreq = min(minFreq, f);  // Find min nonzero freq
                
                ans += maxFreq - minFreq;
            }
        }
        
        return ans;
    }
};
