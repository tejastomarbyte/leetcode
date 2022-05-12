class Solution {
public:
    void f(set<vector<int>> &ans,vector<int>nums,int i,int r)
    {
        if(i==r)
        {
            ans.insert(nums);
            
        }
        for(int p=i;p<=r;p++)
        {
            swap(nums[i],nums[p]);
            f(ans,nums,i+1,r);
            swap(nums[i],nums[p]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        int n=nums.size();
        f(ans,nums,0,n-1);
        vector<vector<int>>a;
        for(auto it:ans)
            a.push_back(it);
        return a;
        
    }
};