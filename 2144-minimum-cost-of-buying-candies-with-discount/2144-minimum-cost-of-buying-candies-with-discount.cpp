class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        if(cost.size()==1)
            return cost[0];
        else if(cost.size()==2)
            return cost[0]+cost[1];
        
        int i=cost.size()-1;
        int ans=0;
        while(i>=0)
        {   if(i==0)
            { 
               ans+=cost[i];
               i--; 
            }
            else
            {   ans+=(cost[i]+cost[i-1]);
                i-=3;
            }
        }
        return ans;
    }
};