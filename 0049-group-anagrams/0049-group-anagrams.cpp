class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        unordered_map<string,vector<string>>m;
        
        for(auto it:strs)
        {
            string a=it;
            sort(it.begin(),it.end());
            m[it].push_back(a);
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};