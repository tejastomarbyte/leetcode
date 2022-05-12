class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i;
        
        for(i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]) break;
        }
        
        if( i >= 0){
            for(int j = n-1; j>=0; j--){
                if(nums[j] > nums[i]){
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        
        reverse(nums.begin() + i+1, nums.end());
        } 
};