class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count=0,n=s.length();
        if(s.length()!=goal.length())
            return false;
        if(s.compare(goal)==0)
        {
            vector<int>m(26,0);
            
            for(auto it:s)
                m[it-'a']++;
            
            for(auto c:m)
                if(c>1) //2 same elements can be swapped
                    return true;
            return false;
        }
        else
        {
            int count=0;
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[i]!=s[j] && s[i]==goal[j] && s[j]==goal[i])
                        count++;
                }
            }
            if(count==1)
                return true;
            return false;
        }
    }
};