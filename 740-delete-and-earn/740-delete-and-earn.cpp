class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        vector<int>sum(n+1,0);
        for(auto it:nums)
            sum[it]+=it;
        
        int prev=0,cur=sum[1];
        for(int i=2;i<=n;i++)
        {
            int temp=max(cur,prev+sum[i]);
            prev=cur;
            cur=temp;
            
        }
        return cur;
    }
};