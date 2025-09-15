// Last updated: 9/16/2025, 12:02:52 AM
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int time=0;
        int prevMax=0;

        for(int i=0;i<n;i++){
            if(i>0 && colors[i]!=colors[i-1]){
                prevMax=0;
            }

            int curr=neededTime[i];
            time+=min(curr,prevMax);
            prevMax=max(curr,prevMax);
        }
        return time;
    }
};