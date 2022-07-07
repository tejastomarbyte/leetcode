class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){return 0;}
       
        vector<int>ups(nums.size(),0);        
        vector<int>downs(nums.size(),0);
        ups[0]=1;
        downs[0]=1;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    ups[i]=max(ups[i],downs[j]+1);
                }
                else if(nums[i]<nums[j])
                {
                    downs[i]=max(downs[i],ups[j]+1);
                }
            }
        }
        return max(*max_element(ups.begin(),ups.end()),*max_element(downs.begin(),downs.end()));

    }
};