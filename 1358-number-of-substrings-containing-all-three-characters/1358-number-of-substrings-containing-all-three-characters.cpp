class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>m;
        
        int i=0,j=0,fin=0;
        while(j<s.length())
        {
            m[s[j]]++;
            int ans=0;
            while(m['a'] && m['b'] && m['c'])
            {
                ans+=(s.size()-j);
                --m[s[i]];
                i++;
            }
            fin+=ans;
            j++;
            
        }
        return fin;
    }
};