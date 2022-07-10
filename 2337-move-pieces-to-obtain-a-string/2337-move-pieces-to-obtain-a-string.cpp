class Solution {
public:
    bool canChange(string s, string t) {
        vector<int>a,b;
        int i=0,n=s.length(),j=0;
        while(i<n && j<n)
        {
            while(i<n and s[i]=='_')i++;
            while(j<n and t[j]=='_')j++;
            
            if(i==n)
                return i==n and j==n;
            
            if(s[i]!=t[j])
                return false;
            if(s[i]=='L' && i<j)
                return false;
            if(s[i]=='R' && j<i)
                return false;
            
            i++,j++;
        }
        return true;
        
    }
};