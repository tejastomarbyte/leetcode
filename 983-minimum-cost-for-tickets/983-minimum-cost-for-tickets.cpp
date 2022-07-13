class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d=days.back();
        
        unordered_set<int>s(days.begin(),days.end());
        vector<int>dp(d+1,0);
        for(int i=1;i<=d;i++)
        {
            if(s.find(i)!=s.end())
            {
                int one=costs[0]+dp[max(i-1,0)];
                int seven=costs[1]+dp[max(i-7,0)];
                int thirty=costs[2]+dp[max(i-30,0)];
                
                dp[i]=min({one,seven,thirty});
            }
            else
                dp[i]=dp[i-1];
        }
        return dp[d];
    }
};