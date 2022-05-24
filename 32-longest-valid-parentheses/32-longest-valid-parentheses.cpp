class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0;
        int len=0,maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                left++;
            if(s[i]==')')
                right++;
            if(left==right)
            {   
                len=left+right;
                maxlen=max(maxlen,len);
            }
            else if(left<=right)
            {
                left=right=0;
            }
        }
        left=0,right=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            if(s[i]==')')
                right++;
            if(left==right)
            {   
                len=left+right;
                maxlen=max(maxlen,len);
            }
            else if(left>=right)
            {
                left=right=0;
            }
        }
        return maxlen;
    }
};