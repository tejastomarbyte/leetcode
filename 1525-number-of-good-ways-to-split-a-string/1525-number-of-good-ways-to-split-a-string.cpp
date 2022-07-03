class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mb,mf;
        
        for(auto it:s)
            mb[it]++;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            mf[s[i]]++;
            mb[s[i]]--;
            if(mb[s[i]]==0)
                mb.erase(s[i]);
            if(mb.size()==mf.size())count++;
        }
        return count;
    }
};