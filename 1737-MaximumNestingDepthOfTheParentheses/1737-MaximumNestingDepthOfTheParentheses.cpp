// Last updated: 9/16/2025, 12:02:48 AM
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxi=0;

        for(char &c: s){
            if(c=='('){
                count++;
                maxi=max(maxi,count);
            }else if(c==')'){
                count--;
            }
        }
        return maxi;
    }
};