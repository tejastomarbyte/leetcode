class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board.size(),vector<int>(board[0].size(),0));
        vector<int> t={-1,-1,-1,0,1,1,1,0},s={-1,0,1,1,1,0,-1,-1};
        int fin=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {   
                if(board[i][j]==0)
                {   int temp=0;
                    for(int k=0;k<8;k++)
                    {
                        if(i+t[k]<=board.size()-1 && i+t[k]>=0 && j+s[k]<=board[0].size()-1 && j+s[k]>=0)
                        {
                            if(board[i+t[k]][j+s[k]]==1)
                               temp++;
                        }
                    }
                    if(temp==3)
                        ans[i][j]=1;
                }
                else
                {   int ones=0;
                    for(int k=0;k<8;k++)
                    {
                        if(i+t[k]<=board.size()-1 && i+t[k]>=0 && j+s[k]<=board[0].size()-1 && j+s[k]>=0)
                        {
                            if(board[i+t[k]][j+s[k]]==1)
                               ones++;
                        }
                        
                    }
                    if(ones==2 || ones==3)
                        ans[i][j]=1;
                    else if(ones<2 || ones>3)
                    {
                        ans[i][j]=0;
                    }
                    
                }    
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
                board[i][j]=ans[i][j];
        }
    }
};