class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxh;
        for(int i=0;i<nums.size();i++)
        {
                maxh.push(nums[i]);
        }
        for(int i=0;i<k-1;i++)
            maxh.pop();
        return maxh.top();
    }
};