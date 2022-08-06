class Solution {
public:
    
    bool isP(string &t,int i,int j)
    {
        while(i<j)
        {
            if(t[i]!=t[j])
                return false;
            i++,j--;
        }
        return true;
    }
    void f(string &s,int i,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=i;j<s.length();j++)
        {
            if(isP(s,i,j))
            {
                temp.push_back(s.substr(i,j-i+1));
                f(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        vector<vector<string>>ans;
        
        f(s,0,temp,ans);
        return ans;
        
    }
};