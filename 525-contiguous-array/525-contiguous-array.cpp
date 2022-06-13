class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int len=0,maxlen=0,count=0;
        unordered_map<int,int>m;
        m[0]=-1;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
                count++;
            else
                count--;
            if(m.find(count)!=m.end())
            {
                len=i-m[count];
                maxlen=max(len,maxlen);
            }
            else
                m[count]=i;
        }
        return maxlen;
    }
};