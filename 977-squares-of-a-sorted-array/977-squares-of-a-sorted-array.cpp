class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v(nums.size());
        int start=0,end=nums.size()-1,idx=end;
        while(start<=end)
        {
            int l=nums[start]*nums[start],r=nums[end]*nums[end];
            
            if(l>r)
            {
                v[idx]=l;
                start++;
                idx--;
            }
            else
            {
                v[idx]=r;
                end--;
                idx--;
            }
        }
        return v;
    }
};