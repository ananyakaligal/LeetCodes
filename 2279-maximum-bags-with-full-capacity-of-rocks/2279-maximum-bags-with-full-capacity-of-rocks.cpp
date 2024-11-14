class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int additionalRocks) {
        
      int n=cap.size();
        vector<int>diff(n);

        for(int i=0;i<n;i++)
        {
            diff[i]=cap[i]-rocks[i];

        }

        sort(diff.begin(),diff.end());

        int ans=0;

        for(int i=0;i<n;i++)
        {
            int req=diff[i];
            if(req<=additionalRocks)
            {
                additionalRocks-=req;
                ans++;
            }
            else
            {
                break;

            }
        }
        return ans;
    }
};