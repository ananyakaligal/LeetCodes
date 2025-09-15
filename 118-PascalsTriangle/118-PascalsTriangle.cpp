// Last updated: 9/16/2025, 12:08:55 AM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int m=numRows;
        vector<vector<int> >v;
        for(int i=0;i<m;i++){
           vector<int> a(i+1,1);
            for(int j=1;j<i;j++){
                a[j]=v[i-1][j-1]+v[i-1][j];
            }
            v.push_back(a);
    }
  return v;
    }
};