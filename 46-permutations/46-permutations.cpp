class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>nums,int i,int r)
    {
        if(i==r)
        {
            ans.push_back(nums);
            return;
        }
        for(int p=i;p<=r;p++)
        {
            swap(nums[p],nums[i]);
            f(ans,nums,i+1,r);
            swap(nums[p],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        f(ans,nums,0,n-1);
        return ans;
    }
};