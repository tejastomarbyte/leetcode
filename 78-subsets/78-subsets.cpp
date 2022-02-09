
class Solution {
public:
    void sub(vector<int>nums,vector<int> &v,int i,vector<vector<int>> &ans)
    {
        if(i>nums.size()-1)
        {
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        sub(nums,v,i+1,ans);
        v.pop_back();
        sub(nums,v,i+1,ans);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sub(nums,v,0,ans);
        return ans;
    }
};