class Solution {
public:
    int maxArea(vector<int>& h) {
        int mar=INT_MIN,cur;
        int i=0,j=h.size()-1;
        while(i<j)
        {
            cur=min(h[i],h[j])*(j-i);
            mar=max(mar,cur);
            if(h[i]<h[j])
                i++;
            else if(h[i]>h[j])
                j--;
            else{
                i++;
            }
        }
        return mar;
    }
};