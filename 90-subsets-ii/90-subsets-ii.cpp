class Solution {
public:
    
    void sub(set<vector<int>> &s,vector<int> &v,vector<int> nums,int i)
    {
        if(i>nums.size()-1)
        {
            s.insert(v);
            return;
        }
        
        v.push_back(nums[i]);
        sub(s,v,nums,i+1);
        v.pop_back();
        sub(s,v,nums,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int> v;
        sort(nums.begin(),nums.end());
        sub(s,v,nums,0);
        vector<vector<int>> ans;
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};