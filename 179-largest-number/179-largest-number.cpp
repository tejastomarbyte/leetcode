class Solution {
public:
    static bool comp(string &a,string &b)
    {
        string t=a+b,p=b+a;
        return t>p;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        for(auto i:nums)
        {
            v.push_back(to_string(i));
        }
        
        sort(v.begin(),v.end(),comp);
        
        string t;
        if(v[0]=="0")
            return "0";
        for(int i=0;i<v.size();i++)
        {
            t+=v[i];
        }
        return t;
    }
};