// Last updated: 9/16/2025, 12:04:43 AM
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats=0;
        int i=0, j=people.size()-1;
            while(i<=j){
                if(people[j]+people[i]<=limit){
                    boats++;
                    i++;
                    j--;
                }else {
                    j--;
                    boats++;
                }
        }
        return boats;
    }
};