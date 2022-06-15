class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& w) {
        int cur=1,maxlen=1;
        int n=w.size();
        sort(w.begin(),w.end(),comp);
        unordered_map<string,int>m;
        for(auto i:w)
        {
            for(int j=0;j<i.length();j++)
            {
                string t=i.substr(0,j)+i.substr(j+1);
                m[i]=max(m[i],(m.find(t)==m.end()?1:m[t]+1));
            }
            maxlen=max(maxlen,m[i]);
        }
        return maxlen;
    }
};