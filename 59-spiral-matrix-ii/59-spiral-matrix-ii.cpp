class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        // bool tr=true; if tr==true elements filled horizontally else vertically
        int left=0,right=n-1,top=0,bottom=n-1;
        int dir=0;
        int num=1;
        while(left<=right && top<=bottom)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v[top][i]=num++;
                }
                top++;
                dir++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    v[i][right]=num++;
                }
                right--;
                dir++;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v[bottom][i]=num++;
                }
                bottom--;
                dir++;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                {
                    v[i][left]=num++;
                }
                left++;
                dir=0;
            }
                
        }
        return v;
    }
};