class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // subtracting the subarrays having the same remainder when divided by k
        
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=(sum%k+nums[i]%k+k)%k;
            ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};