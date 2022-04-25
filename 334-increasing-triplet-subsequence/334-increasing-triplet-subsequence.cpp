class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min=nums[0];
        int maxi=INT_MAX;
        
        for(auto i:nums)
        {
            if(i>min && i>maxi)return true;
            if(i>min)maxi=i;
            else 
                min=i;
        }
        return false;
    }
};