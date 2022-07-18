class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& d) {
        int g=d[0];
        for(auto it:d)
            g=__gcd(it,g);
        sort(nums.begin(),nums.end());
        vector<int>div;
        for(int i=1;i*i<=g;i++)
        {
            if(g%i==0)
                div.push_back(i),div.push_back(g/i);
        }
        sort(begin(div),end(div));
        int n=nums.size(),ans=0;
        for(int i=0;i<div.size();i++)
        {
            while(ans<n && nums[ans]<div[i])
                ans++;
            
            if(ans<n and nums[ans]==div[i])
                return ans;
        }
        return -1;
    }
};