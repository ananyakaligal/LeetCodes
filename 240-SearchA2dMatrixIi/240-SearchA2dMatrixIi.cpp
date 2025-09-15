// Last updated: 9/16/2025, 12:07:18 AM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int row=0, col=n-1;

        while(row<m && col>=0){
            if(target == matrix[row][col]) return true;
            else if(target> matrix[row][col]) row+=1;
            else col-=1;
        }
        return false;
    }
};