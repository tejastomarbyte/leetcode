class Solution {
public:
    int count;
    void f(vector<int>&nums,int i,int ans,int temp)
    {
        if(i==nums.size())
        {
            if(ans==temp)
               count++;
            return;
        }
        f(nums,i+1,ans,temp|nums[i]);
        
        f(nums,i+1,ans,temp);
        
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        count=0;
        for(int i=0;i<32;i++)
        {
            bool flag=false;
            
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]&(1<<i))
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                ans+=(1<<i);
        }
        f(nums,0,ans,0);
        return count;
    }
};