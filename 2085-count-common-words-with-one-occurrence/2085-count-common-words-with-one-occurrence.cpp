class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans=0;
        unordered_map<string,int> a,b;
        for(auto i:words1)
        {
            a[i]++;
        }
        for(auto i:words2)
        {
            b[i]++;
        }
        for(auto i:words1)
        {
            if(a[i]==1 && b[i]==1)
                ans++;
        }
        return ans;
    }
};