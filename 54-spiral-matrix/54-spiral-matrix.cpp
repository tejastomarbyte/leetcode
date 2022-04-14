class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int> v;
        int dir=0;
        while(top<=bottom && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v.push_back(matrix[top][i]);
                }
                top++;
                dir++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    v.push_back(matrix[i][right]);
                }
                right--;
                dir++;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir++;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
                dir=0;
            }
        }
        return v;
    }
};