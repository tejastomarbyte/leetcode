class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto i:s)
            m[i]++;
        multimap<int,char,greater<int>>p;
        string ans;
        for(auto it=m.begin();it!=m.end();it++)
        {
            p.insert({it->second,it->first});
        }
        for(auto i=p.begin();i!=p.end();i++)
        {
            for(int j=0;j<i->first;j++)
                ans.push_back(i->second);
            
        }
        // reverse(ans.begin(),ans.end());
        
        return ans;
    }
};