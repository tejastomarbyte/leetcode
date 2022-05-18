class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int maxi,sum=0;
        for(int i=1;i<points.size();i++){
            maxi = max(abs(points[i-1][0]-points[i][0]),abs(points[i-1][1]-points[i][1]));
            sum = sum+maxi;
        }
        return sum;
    }
};