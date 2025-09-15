// Last updated: 9/16/2025, 12:03:01 AM
class Solution {
public:
    int maxPower(string s) {
        int count=0;
        int max_count=0;

    for(int i =0 ; i<s.size() ; i++){
        if(s[i] == s[i+1]){
            count++;
        }else{
            max_count = max(count,max_count);
            count=0;
        }
    }
    return max_count+1; 
    }
};

