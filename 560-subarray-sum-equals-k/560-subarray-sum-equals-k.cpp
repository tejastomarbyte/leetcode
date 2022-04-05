class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans=0;
        unordered_map<int,int> m;
        m[0]++;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {   sum+=nums[i];
            int f=sum-k;
            if(m.find(f)!=m.end())
                ans+=m[f];
            m[sum]++;
        }
        return ans;
    }
};