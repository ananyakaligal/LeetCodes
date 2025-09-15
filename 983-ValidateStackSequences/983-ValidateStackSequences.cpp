// Last updated: 9/16/2025, 12:04:27 AM
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> st;
        int i=0, j=0;
        int m=pushed.size();
        int n=popped.size();

        if(m!=n) return false;

        while(i<m && j<m){

            st.push(pushed[i]);

            while(!st.empty() && st.top()==popped[j]){
                j++;
                st.pop();
            }
            i++;
        }
        return st.empty();
    }
};