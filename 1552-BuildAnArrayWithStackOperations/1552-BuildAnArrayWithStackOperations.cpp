// Last updated: 9/16/2025, 12:02:59 AM
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack <int> st;
        int i=1, j=0;
        vector <string> ans;

        while (i<= target.back()){
            st.push(i);
            ans.push_back("Push");
            if(st.top()!=target[j]){
                st.pop();
                ans.push_back("Pop");
            }else{
                j++;
            }
            i++;
        }
        return ans;
    }
};