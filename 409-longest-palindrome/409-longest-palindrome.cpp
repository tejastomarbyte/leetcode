class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26]={0},upper[26]={0};
        
        for(auto it:s)
        {
            if(it<=90 && it>=65)
                upper[it-'A']++;
            else
                lower[it-'a']++;
        }
        
        bool flag=false;
        
        int length=0;
        
        for(int i=0;i<26;i++)
        {
            if(lower[i]%2==0)
                length+=lower[i];
            else if(lower[i]%2)
            {
                if(flag==false)
                {
                    length+=lower[i];
                    flag=true;
                }
                else
                    length+=(lower[i]-1);
            }
            if(upper[i]%2==0)
                length+=upper[i];
            else if(upper[i]%2)
            {
                if(flag==false)
                {
                    length+=upper[i];
                    flag=true;
                }
                else
                    length+=(upper[i]-1);
            }
            
            
        }
        return length;
        
    }
};