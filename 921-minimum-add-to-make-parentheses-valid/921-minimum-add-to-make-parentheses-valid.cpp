class Solution {
public:
    int minAddToMakeValid(string s) {
        int t=0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                t++;
            else
                t--;
            if(t<0)
            {
                ans+=abs(t);
                
                t=0;
            }
        }
        return ans+t;
    }
};