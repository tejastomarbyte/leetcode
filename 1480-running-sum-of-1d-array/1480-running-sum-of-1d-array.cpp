class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> t(nums.size());
        t[0]=nums[0];
        for(int i=1;i<t.size();i++)
        {
            t[i]=nums[i]+t[i-1];
        }
        return t;
    }
};