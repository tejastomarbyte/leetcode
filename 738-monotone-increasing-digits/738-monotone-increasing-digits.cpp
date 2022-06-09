class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s=to_string(n);
        
        int m=s.size();
        
        for(int i=s.length()-1;i>0;i--)
        {
            if(s[i]<s[i-1])
            {
                s[i-1]=s[i-1]-1;
                m=i;
            }
        }
        for(int i=m;i<s.length();i++)
            s[i]='9';
        
        return stoi(s);
    }
};