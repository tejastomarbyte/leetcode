class Solution {
public:
    bool check(string s,vector<int>t)
    {
        vector<int>v(26),b(26);
        for(auto i:s)
            v[i-'a']++;
        for(int i=0;i<26;i++)
            if(v[i]!=0 && t[i]<v[i])
                return false;
        return true;
        
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        for(auto i:chars)
            v[i-'a']++;
        
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            if(check(words[i],v))
                ans+=words[i].length();
        }
        return ans;
    }
};