// Last updated: 9/16/2025, 12:00:52 AM
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(int i=0; i<derived.size(); i++){
            x=x^derived[i];
        }
        if(x==0){
            return true;
        }
        return false;
    }
};