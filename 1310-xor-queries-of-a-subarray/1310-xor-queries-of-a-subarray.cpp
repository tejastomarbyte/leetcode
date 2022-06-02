class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int>x(arr.size());
        x[0]=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++)
            x[i]=x[i-1]^arr[i];
        // for(auto i:x)cout<<i<<" ";
        vector<int>ans;
        for(int i=0;i<q.size();i++)
        {
            if(q[i][0]==0)
                ans.push_back(x[q[i][1]]);
            else
                ans.push_back(x[q[i][1]]^x[q[i][0]-1]);
        }
        return ans;
    }
};