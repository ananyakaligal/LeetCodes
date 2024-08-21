class Solution {
public:

    int string_to_number(string s){
        int num=0;
        for(char c: s){
            if(c != '-'){
                num=num*10+(c-'0');
            }
        }
        if(s[0]=='-'){
                num=-1*num;
            }
        return num;
    }

    int calPoints(vector<string>& operations) {
        stack<string> st;
        for(int i=operations.size()-1;i>=0;i--){
            st.push(operations[i]);
        }
        vector<int> record;
        for(int i=0;i<operations.size();i++){
            if(st.top()=="+"){
                record.push_back(record[record.size()-1]+record[record.size()-2]);
            }
            else if(st.top()=="C"){
                record.pop_back();
            }
            else if(st.top()=="D"){
                record.push_back(2*record[record.size()-1]);
            }
            else{
                record.push_back(string_to_number(st.top()));
            }
            st.pop();
        }
        int sum=0;
        for(int i=0;i<record.size();i++){
            sum+=record[i];
        }
        return sum;
            
    }
};