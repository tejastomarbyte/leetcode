class Solution {
public:
    void f(vector<int> &v,vector<string> &ans,string s,int n,int i,string map[])
    {
        if(i>=n)
        {
            ans.push_back(s);
            return;
        }
        
        int idx=v[i];
        string x=map[idx];
        
        for(int j=0;j<x.length();j++)
        {
            s.push_back(x[j]);
            f(v,ans,s,n,i+1,map);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>s;
        if(digits.length()==0)
            return s;
        vector<int> v;
        string map[10]={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.length();i++)
        {
            v.push_back(digits[i]-'0');
        }
        string x="";
        f(v,s,x,v.size(),0,map);
        return s;
    }
};