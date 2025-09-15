// Last updated: 9/16/2025, 12:01:15 AM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map <int,int> freq;
        int count=0;
        int ele=-1;

        for(int num: nums){
            if(num%2==0) freq[num]++;
        }

        for(auto& entry: freq){
            if(entry.second>count|| (entry.second==count && entry.first<ele)){
                ele=entry.first;
                count=entry.second;
            }
        }
        return ele;
    }
};