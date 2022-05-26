class Solution {
public:
    bool searchMatrix(vector<vector<int>>& ma, int target) {
        int i=0,j=ma[0].size()-1;
        while(i<ma.size() && j>=0)
        {
            if(ma[i][j]==target)
                return true;
            else if(ma[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
};