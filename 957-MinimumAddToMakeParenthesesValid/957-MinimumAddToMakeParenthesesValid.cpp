// Last updated: 9/16/2025, 12:04:33 AM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int close=0;

        for(char &c: s){
            if(c=='(') open++;
            else{
                if(open<=0) close++;
                else open--;
            }
        }
        return close+open;
    }
};