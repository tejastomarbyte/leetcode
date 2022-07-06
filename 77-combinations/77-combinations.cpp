class Solution {
public:
    vector<bool>chosen;
    void f(vector<vector<int>>&ans,vector<int>&temp,int i,int n,int k)
    {
        if(temp.size()==k)
        {
            
            ans.push_back(temp);
            return;
        }
        
        if(i>n)
            return;
        
        for(int j=i;j<=n;j++)
        {
            if(!chosen[j])
            {
                chosen[j]=true;
                temp.push_back(j);
                f(ans,temp,j+1,n,k);
                temp.pop_back();
                chosen[j]=false;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        chosen.resize(21,false);
        vector<int>temp;
        f(ans,temp,1,n,k);
        return ans;
    }
};