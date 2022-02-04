class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        if(s.length()==0||s.length()==1)
            return s.length();
        int i=0,j=0,l=1,maxl=INT_MIN;
        while(j<s.length())
        {
            if(m[s[j]]==0)
            {
                m[s[j]]++;
                l=(j-i+1);
                maxl=max(l,maxl);
                j++;
            }
            else if(m[s[j]]==1)
            {
                while(m[s[j]]!=0)
                {
                    if(s[j]==s[i])
                    {
                        m[s[j]]--;
                        i++;
                        l--;
                    }
                    else
                    {
                        m[s[i]]--;
                        i++;
                        l--;
                    }
                }
                
            }
        }
        return maxl;
    }
};