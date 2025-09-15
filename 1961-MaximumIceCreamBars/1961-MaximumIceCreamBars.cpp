// Last updated: 9/16/2025, 12:02:15 AM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                sum++;
                coins-=costs[i];
            }
            else break;
        }
        return sum;
    }
};