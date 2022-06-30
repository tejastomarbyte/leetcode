class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count=0;
        for(auto it:nums)
        {
            count+=(m[it-k]+m[it+k]);
            m[it]++;
        }
        return count;
        
    }
};