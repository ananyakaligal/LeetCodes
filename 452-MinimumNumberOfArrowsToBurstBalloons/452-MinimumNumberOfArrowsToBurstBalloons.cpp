// Last updated: 9/16/2025, 12:06:28 AM
class Solution {
private:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparator);

        int i=0;
        int start=points[i][0];
        int end=points[i][1];
        int count=1;

        for(int i=1; i<points.size();i++){
            if(points[i][0]<=end){
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
            else{
                start=points[i][0];
                end=points[i][1];
                count++;
            }
        }
        return count;
    }
};