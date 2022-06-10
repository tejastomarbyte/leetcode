class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        long long int dist1=pow(a[0],2)+pow(a[1],2);
        long long int dist2=pow(b[0],2)+pow(b[1],2);
        return dist1<dist2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),comp);
        vector<vector<int>>ans;
        
        for(int i=0;i<k;i++)
            ans.push_back(points[i]);
        
        return ans;
    }
};