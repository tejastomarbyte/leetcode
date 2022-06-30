class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> n;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
            {
                n.push_back(grid[i][j]);
            }
        
        int s=n.size();
        nth_element(n.begin(),n.begin()+s/2,n.end());
        int count=0,temp=n[s/2];
        for(int i=0;i<s;i++)
        {
            int diff=abs(n[i]-temp);
            if(diff%x!=0)return -1;
            count+=diff/x;
        }
        return count;
    }
};