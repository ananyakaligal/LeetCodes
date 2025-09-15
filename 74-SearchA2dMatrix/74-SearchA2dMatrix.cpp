// Last updated: 9/16/2025, 12:09:43 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m=matrix.size();
        int n=matrix[0].size();

        int low=0;
        int high=m-1;
        int mid=0;
        int index=-1;

        while(low<=high){
            mid=(low+high)/2;

            if(matrix[mid][0]>target) high=mid-1;
            else if(matrix[mid][0]<=target && matrix[mid][n-1]>=target) {index=mid; break;}
            else low=mid+1; 
        }
        if(index==-1) return false;

        low=0;
        high=n-1;

        while(low<=high){
            mid=(low+high)/2;

            if(matrix[index][mid]==target) return true;
            else if(matrix[index][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};