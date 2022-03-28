class Solution {
public:
    
    int f(int index,int length,int n,vector<vector<int>> &dp)
    {
        if(index==4)
            return 1;
        if(length==n)
            return 1;
        if(dp[index][length]!=-1) return dp[index][length];
        //take
        int l=f(index,length+1,n,dp);
        
        //not take
        int r=f(index+1,length,n,dp);
        
        return dp[index][length]=l+r;
    
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5,vector<int>(n,-1)); 
        return f(0,0,n,dp);
    }
};