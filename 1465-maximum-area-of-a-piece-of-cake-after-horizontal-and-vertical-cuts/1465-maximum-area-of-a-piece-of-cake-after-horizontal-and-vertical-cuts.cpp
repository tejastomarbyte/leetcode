class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        ho.push_back(0);       
        ve.push_back(0);
        ho.push_back(h);
        ve.push_back(w);
        sort(ho.begin(),ho.end());
        sort(ve.begin(),ve.end());
        int ml=0,mw=0,n=ho.size(),m=ve.size();
        for(int i=1;i<n;i++)
        {
            ml=max(ml,ho[i]-ho[i-1]);
        }
        for(int i=1;i<m;i++)
        {
            mw=max(mw,ve[i]-ve[i-1]);
        }
        int mod=1e9+7;
        return (1LL*ml*mw)%mod;
    }
};