class Solution {
public:
    const int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>range;
        for(int i=0;i<nums.size();i++)
        {   int sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                range.push_back(sum);
            }
        }
        sort(range.begin(),range.end());
        
        int sum=0;
        for(int i=left-1;i<right;i++)
        {
            sum=(sum+range[i])%mod;
        }
        return sum;
            
    }
};