// Last updated: 9/16/2025, 12:07:33 AM
class Solution {
public:
    int calculate(string s) {
        int num=0;
        int sign=1;
        int result=0;

        stack <int> st;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            } else if(s[i]=='+'){
                result+=sign*num;
                sign=1;
                num=0;
            } else if(s[i]=='-'){
                result+=sign*num;
                sign=-1;
                num=0;
            } else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                num=0;
                sign=1;
            } else if(s[i]==')' ){
                result+=num*sign;
                num=0;

                int stack_sign= st.top();
                st.pop();

                int last_result=st.top();
                st.pop();

                result*=stack_sign;
                result+=last_result;
            }
        }
        result+=num *sign;
        return result;
    }
};