class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=1e9;
        while(low<high)
        {
            
            int mid=low+(high-low)/2;
            int total=0;
            for(auto i:nums)
            {
                total+=(i-1)/mid;
            }
            
            if(total>maxOperations)
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
    }
};