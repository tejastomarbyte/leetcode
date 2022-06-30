class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>m;
        for(auto it:nums)
            m[it]++;
        for(auto it=m.begin();it!=m.end();it++)
        {
            
            if(k==0)
            {
                if(it->second>1)
                    count++;
            }
            else
            {
                if(m.find(it->first-k)!=m.end())
                    count++;
            }
        }
        return count;
        
        
    }
};