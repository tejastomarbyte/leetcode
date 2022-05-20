class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int i=0;
        vector<int>v=in[0];
        vector<vector<int>>ans;
        for(auto it:in)
        {
            if(v[1]>=it[0])
            {
                v[1]=max(v[1],it[1]);
            }
            else
            {
                ans.push_back(v);
                v=it;
            }
        }
        ans.push_back(v);
        return ans;
        
          
        
    }
};