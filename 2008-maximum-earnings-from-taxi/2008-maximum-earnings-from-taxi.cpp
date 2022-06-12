class Solution {
public:
    //flag=true means taxi occupied 
    //flag=false means taxi unoccupied
    int search(vector<vector<int>>&r,int t)
    {
        int i=0,j=r.size();
        while(i<j)
        {
            int mid=i+(j-i)/2;
            if(r[mid][0]>=t)
                j=mid;
            else
                i=mid+1;
        }
        return i;
    }
    long long f(vector<vector<int>>&r,int i,vector<long long>&dp)
    {
        if(i>=r.size())
        {
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        long long take,nottake;
        take=r[i][1]-r[i][0]+r[i][2]+f(r,search(r,r[i][1]),dp);
        nottake=f(r,i+1,dp);
        return dp[i]=max(take,nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        long long ans=0;
        bool flag=false;
        sort(rides.begin(),rides.end());
        vector<long long>dp(rides.size()+1,-1);
        return f(rides,0,dp);
        
    }
};