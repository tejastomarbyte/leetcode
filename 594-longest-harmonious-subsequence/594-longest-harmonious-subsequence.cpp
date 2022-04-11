class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1,ans=0,len=0;
        while(j<nums.size())
        {
            if(nums[j]-nums[i]<1)
            {
                len=j-i+1;
                
                
            }
            if(nums[j]-nums[i]==1)
            {
                ans=max(ans,j-i+1);
                
            }
            else if(nums[j]-nums[i]>1)
            {
                while(nums[j]-nums[i]>1 && i<nums.size())
                    i++;
            }
            j++;
        }
        return ans;
        
    }
};