// Last updated: 9/16/2025, 12:04:02 AM
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for(char &c:s){
            if(c=='('){
                depth++;
                if(depth>1) result+='(';
            }else{
                if(depth>1) result+=')';
                depth--;
            }
        }
        return result;
    }
};