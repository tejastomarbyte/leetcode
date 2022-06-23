class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
            while(!st.empty() && (abs(s[i+1]-st.top())==32))
            {
                st.pop();
                i++;
            }
        }
        string ans;
        
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};