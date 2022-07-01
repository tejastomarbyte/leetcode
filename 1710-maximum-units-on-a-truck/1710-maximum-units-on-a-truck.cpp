class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int truck) {
        sort(box.begin(),box.end(),comp);
        
        int sum=0;
        int n=box.size();
        for(int i=0;i<n;i++)
        {
            int temp=min(box[i][0],truck);
            int s=temp*box[i][1];
            sum+=s;
            truck-=temp;
            if(!truck)
                break;
        }
        return sum;
    }
};