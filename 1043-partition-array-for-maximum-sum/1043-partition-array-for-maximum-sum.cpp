class Solution {
public:
    vector<int>dp;
    int f(vector<int>&arr,int idx,int k)
    {
        if(idx==arr.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int maxans=0,maxi=INT_MIN;
        int n=arr.size();
        for(int i=idx;i<=min(n-1,idx+k-1);i++)
        {
            maxi=max(maxi,arr[i]);
            int ans=maxi*(i-idx+1)+f(arr,i+1,k);
            maxans=max(maxans,ans);
        }
        return dp[idx]=maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size()+1,-1);
        return f(arr,0,k);
    }
};