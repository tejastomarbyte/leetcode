class Solution {
public:
    
    void combination(vector<int> &c,int target,int cur,vector<int> &v,vector<vector<int>> &f)
    {
        if(cur>c.size()-1)
            return;
        if(target<=0)
        {
            if(target==0)
            {
                f.push_back(v);
                return;
            }
            else
                return;
        }
        
        
        for(int i=cur;i<c.size();i++)
        {
            v.push_back(c[i]);
            combination(c,target-c[i],i,v,f);
            v.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> f;
        combination(candidates,target,0,v,f);
        return f;
    }
};