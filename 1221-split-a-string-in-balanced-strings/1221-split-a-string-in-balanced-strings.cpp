class Solution {
public:
    int balancedStringSplit(string s) {
        vector<int>v(s.length(),0);
        v[0]=(s[0]=='R'?1:-1);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='R')
                v[i]=v[i-1]+1;
            else
                v[i]=v[i-1]-1;
        }
        int count=0;
        for(int i=0;i<v.size();i++)
            if(v[i]==0)
                count++;
        return count;
    }
};