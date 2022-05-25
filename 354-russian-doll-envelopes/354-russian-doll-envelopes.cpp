class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(),en.end(),comp);
        vector<int>dp;
        dp.push_back(en[0][1]);
        int len=1;
        for(int i=1;i<en.size();i++)
        {
            int temp=en[i][1];
            int l=lower_bound(dp.begin(),dp.end(),temp)-dp.begin();
            
            if(l==dp.size())
            {
                dp.push_back(temp);
                len++;
            }
            else
                dp[l]=temp;
        }
        return len;
        
        
    }
};