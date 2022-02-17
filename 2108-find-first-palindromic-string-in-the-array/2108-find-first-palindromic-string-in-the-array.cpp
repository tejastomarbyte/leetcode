class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s;
        for(int i=0;i<words.size();i++)
        {
            s=words[i];
            bool flag=false;
            for(int j=0;j<s.length()/2;j++)
            {
                if(s[j]!=s[s.length()-j-1])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                return s;
            }
        }
        string t;
        return t;
    }
};