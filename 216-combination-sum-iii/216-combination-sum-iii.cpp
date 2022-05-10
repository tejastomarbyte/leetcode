class Solution {
public:
    void f(int i,int k,int n,vector<vector<int>>&v,vector<int>a)
    {
        if(n==0)
        {
            if(k==0)
            {
                v.push_back(a);
            }
            return;
        }
        if(n<0)
            return;
        if(i>9)
            return;
        
        f(i+1,k,n,v,a);
        a.push_back(i);
        f(i+1,k-1,n-i,v,a);
        a.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>v;
        vector<int>a;
        f(1,k,n,v,a);
        return v;
    }
};