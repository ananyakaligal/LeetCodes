// Last updated: 9/16/2025, 12:04:20 AM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double,int,int>> maxHeap;

        for(auto &it: points){
            double solve=sqrt(it[0]*it[0]+ it[1]*it[1]);
            maxHeap.push({solve,it[0],it[1]});

            if(maxHeap.size()>k) maxHeap.pop();
        }

        vector<vector<int>> result;

        while(!maxHeap.empty()){
            result.push_back({get<1>(maxHeap.top()), get<2>(maxHeap.top())});
            maxHeap.pop();
        }
        return result;
    }
};