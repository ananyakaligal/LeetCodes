// Last updated: 9/16/2025, 12:02:32 AM
class Solution {
public:
    bool halvesAreAlike(string s) {
     int n = s.length();
     int firsthalf = 0, secondhalf = 0;
     for(int i = 0; i < n; i++){
            if(i < n/2 && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || 
            s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
            s[i] == 'O' || s[i] == 'U' )){
                firsthalf++;
            }
            else if(i >= n/2 && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || 
            s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || 
            s[i] == 'O' || s[i] == 'U' )){
                secondhalf++;
            }
     }
        if(firsthalf == secondhalf) return true;
        return false;
    }
};