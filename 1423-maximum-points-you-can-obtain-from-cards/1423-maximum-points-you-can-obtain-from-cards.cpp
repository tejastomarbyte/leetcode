class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int len=c.size()-k;
        int sum=0,mini=INT_MAX;
        int i=0,j=0;
        while(j<c.size())
        {
            sum+=c[j];
            if(j-i+1==len)
            {
                mini=min(mini,sum);
                
                sum-=c[i];
                i++;
                
            }
            j++;
        }
        int s=0;
        
        for(auto it:c)
            s+=it;
        if(mini!=INT_MAX)
            return s-mini;
        return s;
    }
};