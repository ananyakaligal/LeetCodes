// Last updated: 9/16/2025, 12:03:59 AM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while(maxHeap.size()>1){
            int top1=maxHeap.top();
            maxHeap.pop();
            int top2=maxHeap.top();
            maxHeap.pop();

            if(top1==top2) continue;
            else{
                maxHeap.push(top1-top2);
            }
        }
        if (maxHeap.size()) return maxHeap.top();
        else return 0;
    }
};