class Solution {
public:
    int minDeletions(string x) {
        unordered_map<char,int>m;
        for(auto i:x)
        {
            m[i]++;
        }
        
        unordered_set<int>s;
        int count=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            
                while(s.find(it->second)!=s.end() && it->second)
                {
                    it->second--;
                    count++;
                }
                

            s.insert(it->second);
        }
        return count;
        
    }
};