class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int t=nums[n/2];
        int ans=0;
        for(auto i:nums)
        {
            ans+=(abs(i-t));
        }
        
        return ans;
    }
};