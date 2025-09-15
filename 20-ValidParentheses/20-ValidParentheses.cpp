// Last updated: 9/16/2025, 12:10:45 AM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char &c: s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            } else {
                // For closing brackets, check if stack is empty or top doesn't match
                if(st.empty()) return false;
                
                char x = st.top();
                if((x == '(' && c == ')') || 
                   (x == '[' && c == ']') || 
                   (x == '{' && c == '}')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched correctly
        return st.empty();
    }
};
