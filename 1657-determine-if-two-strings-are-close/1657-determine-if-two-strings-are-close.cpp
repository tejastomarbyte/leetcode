class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char>s1;
        set<char>s2;
        vector<int>a(26,0);
        vector<int>b(26,0);
        if(word1.length()!=word2.length())
            return false;
        for(int i=0;i<word1.length();i++)
        {
            s1.insert(word1[i]);
            s2.insert(word2[i]);
            a[word1[i]-'a']++;
            b[word2[i]-'a']++;
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return s1==s2 && a==b;        
        
            
    }
};